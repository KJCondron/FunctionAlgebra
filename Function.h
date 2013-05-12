
#ifndef META_ALGEBRA_FUNCTION_H
#define META_ALGEBRA_FUNCTION_H

#include "ParamCombiner.h"
#include "FunctionOp.h"
#include <boost/shared_ptr.hpp>

///////////////////// NEW META FUNCTIONS //////////////////////////////////////////

template< typename F1, typename F2 >
struct FType 
{
	typedef IPFunction< 
		typename ParamCombiner< 
			typename F1::ParamSet,
			typename F2::ParamSet >::type,
		typename ReturnCombiner<
			typename F1::ReturnType,
			typename F2::ReturnType>::type
	> type;
};

////////////////////////////////////////////////////////////////////////////////////


//template < typename ParamSet, typename ReturnType = double >
//struct IPFunction;

template < typename ParamSet, typename ReturnType = double >
struct PFunction : IPFunction< ParamSet >
{
	typedef IPFunction< ParamSet > Base;
	typedef PFunction ThisType;
	
	typedef typename Base::Ptr BPtr;
	typedef boost::shared_ptr< const PFunction > Ptr;

	PFunction( BPtr f ) :
		m_f(f) {}

	virtual ReturnType operator()( const ParamSet& p ) const
	{
		return (*m_f)(p);
	}

	virtual std::string toString() const
	{
		return m_f->toString();
	}

	virtual ThisType* clone() const
	{
		return new ThisType( m_f );
	}

private:
	BPtr m_f;

};


template < typename ParamSet, typename ReturnType >
struct IPFunction
{
	typedef boost::shared_ptr< const IPFunction > Ptr;
	typedef IPFunction ThisType;

	typedef ParamSet ParamSet;
	typedef ReturnType ReturnType;

	virtual ReturnType operator() ( const ParamSet& p ) const = 0;
	virtual std::string toString() const { return "not done yet"; }
	virtual ThisType* clone() const = 0; 

	/*template< typename OtherParamSet, typename OtherReturnType >
	PFunction< OtherParamSet, ReturnType >
	compose( const IPFunction<OtherParamSet, OtherReturnType>& f )
	{
		typename boost::shared_ptr< 
			IPFunction<OtherParamSet, OtherReturnType> > OPtr;
		OPtr

	}*/

	template< typename OtherFunc >
	PFunction< 
		typename ParamCombiner< ParamSet, typename OtherFunc::ParamSet >::type,
		typename ReturnCombiner< ReturnType, typename OtherFunc::ReturnType >::type
	>
	operator+( const OtherFunc& f )
	{
		return combine<Mult>(f);
	}

private:
	template< typename Op, typename OtherFunc >
	PFunction< typename ParamCombiner< ParamSet, typename OtherFunc::ParamSet >::type,
		       typename ReturnCombiner< ReturnType, typename OtherFunc::ReturnType >::type >
	combine( const OtherFunc& f )
	{
		typedef typename ParamCombiner<
			ParamSet,
			typename OtherFunc::ParamSet >::type NewParam;

		typedef typename ReturnCombiner<
			ReturnType,
			typename OtherFunc::ReturnType>::type NewReturn;

		typedef boost::shared_ptr< const OtherFunc > OPtr;

		typedef boost::shared_ptr< 
			const IPFunction< NewParam, NewReturn> > RPtr;
		
		Ptr me( clone() );
		OPtr nf1( f.clone() );

		RPtr func( new FunctionOp< ThisType, OtherFunc, Op >( me, nf1 ) );
					//Ptr( clone() ),
					//OPtr( f.clone() ) 
				 //));
		
		return PFunction< NewParam, NewReturn >( func );

	}
};

#endif //META_ALGEBRA_FUNCTION_H