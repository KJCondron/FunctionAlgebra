#ifndef META_ALGEBRA_METAFUCTIONS_H
#define META_ALGEBRA_METAFUCTIONS_H

#include <boost/mpl/begin.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/contains.hpp>

namespace mpl = boost::mpl;

template< typename S, typename T >
struct IndexOf : public mpl::distance< typename mpl::begin<S>::type,
				typename mpl::find< S, T >::type >
{};

template< typename P, typename T >
struct ContainsOrIsNull : public mpl::or_< 
	boost::is_same< T, _null >,
	mpl::contains< typename P::types, T > >
{};

template<typename P, typename T>
struct GetWrapper
{
	T static get( const P& p ) { return p.template get<T>(); }
};

template<typename P>
struct GetWrapper<P,_null>
{
	_null static get( const P& ) { return _null(); }
};

#endif
