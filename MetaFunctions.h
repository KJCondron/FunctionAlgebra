#ifndef META_ALGEBRA_METAFUCTIONS_H
#define META_ALGEBRA_METAFUCTIONS_H

#include <boost/mpl/begin.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/distance.hpp>

namespace mpl = boost::mpl;

template< typename S, typename T >
struct IndexOf : mpl::distance< typename mpl::begin<S>::type,
				typename mpl::find< S, T >::type >
{};

#endif
