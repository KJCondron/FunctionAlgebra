
#ifndef META_ALGEBRA_FUNCTION_H
#define META_ALGEBRA_FUNCTION_H

#include "ParamCombiner.h"
#include <boost/shared_ptr.hpp>


template < typename ParamSet, typename ReturnType = double >
struct IPFunction;

template < typename ParamSet, typename ReturnType = double >
struct PFunction : IPFunction< ParamSet >
{
	typedef IPFunction< ParamSet > Base;
	typedef typename Base::Ptr BPtr;
	typedef boost::shared_ptr< const PFunction > Ptr;

	PFunction( BPtr ) :
		m_f(f) {}

	virtual ReturnType operator()( const ParamSet& p ) const
	{
		return (*m_f)(p);
	}

	virtual std::string toString() const
	{
		return m_f->toString();
	}


private:
	BPtr m_f;

};


template < typename ParamSet, typename ReturnType >
struct IPFunction
{
	typedef boost::shared_ptr< const IPFunction > Ptr;

	virtual ReturnType operator() ( const ParamSet& p ) const;
	virtual std::string toString() const = 0;

	/*template< typename OtherParamSet, typename OtherReturnType >
	PFunction< OtherParamSet, ReturnType >
	compose( const IPFunction<OtherParamSet, OtherReturnType>& f )
	{
		typename boost::shared_ptr< 
			IPFunction<OtherParamSet, OtherReturnType> > OPtr;
		OPtr

	}*/


template< typename R1, typename R2 >
struct ReturnCombiner
{
	const static bool val = boost::is_same< R1, R2 >::value;  
	BOOST_STATIC_ASSERT( val );
	typedef R1 type;
};

private:
	template< typename Op, typename OtherParamSet, typename OtherReturnType >
	PFunction< typename ParamCombiner<ParamSet, OtherParamSet>::type,
		       typename ReturnCombiner<ReturnType, OtherReturnType>::type >
	combine( const IPFunction<OtherParamSet, OtherReturnType>& f )
	{
		typename typename ParamCombiner<ParamSet, OtherParamSet>::type NewParam;
		typename typename ReturnCombiner<ReturnType OtherReturnType>::type NewReturn;

		typename boost::shared_ptr< 
			const IPFunction<OtherParamSet, OtherReturnType> > OPtr;

		typename boost::shared_ptr< 
			const IPFunction<NewParam, NewReturn> > RPtr;
		
		RPtr func( new PFuncOp2< ParamSet, OtherParamSet, ReturnType, OtherReturnType, Op >(
					Ptr( clone() ),
					OPtr( f.clone() ) 
				 ));
		return PFunction< NewParam, NewReturn >( func );

	}


};

#endif //META_ALGEBRA_FUNCTION_H