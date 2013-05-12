#ifndef META_ALGEBRA_FUNCTIONOP_H
#define META_ALGEBRA_FUNCTIONOP_H

#include "Param.h"
#include "ParamCombiner.h"

struct Plus
{
	template< typename T1, typename T2 >
	static double //typename ReturnCombiner<T1, T2>::type
		apply( const T1& v1, const T2& v2 )
	{
		return v1 + v2;
	}
};

struct Minus
{
	template< typename T1, typename T2 >
	static double //typename ReturnCombiner<T1, T2>::type
		apply( const T1& v1, const T2& v2 )
	{
		return v1 - v2;
	}
};

struct Mult
{
	template< typename T1, typename T2 >
	static double //typename ReturnCombiner<T1, T2>::type
		apply( const T1& v1, const T2& v2 )
	{
		return v1 * v2;
	}
};

struct Divide
{
	template< typename T1, typename T2 >
	static double //typename ReturnCombiner<T1, T2>::type
		apply( const T1& v1, const T2& v2 )
	{
		return v1 / v2;
	}
};

template < typename ParamSet, typename ReturnType = double >
struct IPFunction;

template< typename Func1, typename Func2, typename OP >
struct FunctionOp : public IPFunction< 
	typename ParamCombiner< typename Func1::ParamSet, typename Func2::ParamSet >::type,
	typename ReturnCombiner< typename Func1::ReturnType, typename Func2::ReturnType >::type
	>
{
	typedef typename Func1::ParamSet ParamSet1;
	typedef typename Func2::ParamSet ParamSet2;

	typedef typename ReturnCombiner< 
		typename Func1::ReturnType, 
		typename Func2::ReturnType >::type ReturnType;

	typedef typename ParamCombiner<
		typename Func1::ParamSet,
		typename Func2::ParamSet >::type NewParam;
	
	typedef typename Func1::Ptr F1;
	typedef typename Func2::Ptr F2;

	FunctionOp( const F1& f1, const F2& f2 ) :
		m_f1(f1), m_f2(f2)
	{}

	ReturnType operator()( const NewParam& p ) const
	{
		typename Func1::ReturnType v1 = (*m_f1)( p );
		typename Func2::ReturnType v2 = (*m_f2)( p );

		return OP::apply( v1, v2 );
	}

	FunctionOp* clone() const 
	{
		return new FunctionOp( F1(m_f1->clone()), F2(m_f2->clone()) );
	}


private:
	F1 m_f1;
	F2 m_f2;
};



#endif // META_ALGEBRA_FUNCTIONOP_H
