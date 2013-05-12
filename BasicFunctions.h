
#ifndef META_ALGEBRA_BASICFUNCTIONS_H
#define META_ALGEBRA_BASICFUNCTIONS_H

#include "Function.h"

template< typename T, typename Return = double >
struct Identity : public IPFunction< Param<T>, Return >
{
	Return operator()( const Param<T>& v ) const
	{
		return v._v0();
	}

	Identity* clone() const
	{
		return new Identity();
	}
};

#endif
