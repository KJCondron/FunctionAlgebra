

#ifndef META_ALGEBRA_PARAMCOMBINER_H
#define META_ALGEBRA_PARAMCOMBINER_H

#include "Param.h"
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/remove.hpp>
#include <boost/mpl/remove_if.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/joint_view.hpp>
#include <boost/mpl/at.hpp>

namespace mpl = boost::mpl;
namespace ph = mpl::placeholders;
using mpl::int_;

#define TYPEDEFX(count) \
	typedef typename mpl::at< types, int_<count> >::type X##count

#define CHECKVALUE(count, v1, v2) Comparer<P##count>::CHECKVALUE( v1, v2 )

#define GETVALUE(count) typename type::P##count v##count = \
	Contains<P1, typename type::P##count>:: value ? \
	GetWrapper<P1, typename type::P##count>::get(d1) : \
	GetWrapper<P2, typename type::P##count>::get(d2)

#define GETVALUEA(P, count) typename P::P##count v##count = \
	GetWrapper<P, typename P::P##count >::get(d)

template< typename ParamSet1, typename ParamSet2 >
struct ParamCombiner
{
private:
	typedef ParamSet1 P1;
	typedef ParamSet1 P2;
	typedef mpl::vector< _null, _null, _null, _null, _null,
		                 _null, _null, _null, _null, _null,
		                 _null, _null, _null, _null, _null,
		                 _null, _null, _null, _null, _null > TwentyNulls;

	typedef typename mpl::remove< typename P1::types, _null >::type P1RTypes; 
	typedef typename mpl::remove< typename P2::types, _null >::type P2RTypes;

	typedef typename mpl::remove_if< 
		P2RTypes, mpl::contains< P1RTypes, ph::_1 >
		>::type UniqueP2Types;

	typedef mpl::joint_view < P1RTypes, UniqueP2Types > utypes;

public:
	typedef mpl::joint_view< utypes, TwentyNulls > types;

	TYPEDEFX(0); TYPEDEFX(1); TYPEDEFX(2); TYPEDEFX(3); TYPEDEFX(4);
    TYPEDEFX(5); TYPEDEFX(6); TYPEDEFX(7); TYPEDEFX(8); TYPEDEFX(9);
    TYPEDEFX(10); TYPEDEFX(11); TYPEDEFX(12); TYPEDEFX(13); TYPEDEFX(14);
    TYPEDEFX(15); TYPEDEFX(16); TYPEDEFX(17); TYPEDEFX(18); TYPEDEFX(19);

	typedef Param<X0, X1, X2, X3, X4, X5, X6, X7, X8, X9,
		          X10, X11, X12, X13, X14, X15, X16, X17, X18, X19> type;

	static type NewParam( const P1& p1, const P2& p2 )
	{
		typedef typename type::P0 P0; typedef typename type::P1 P1; 
		typedef typename type::P2 P2; typedef typename type::P3 P3; 
		typedef typename type::P4 P4; typedef typename type::P5 P5; 
		typedef typename type::P6 P6; typedef typename type::P7 P7; 
		typedef typename type::P8 P8; typedef typename type::P9 P9; 
		typedef typename type::P10 P10; typedef typename type::P11 P11; 
		typedef typename type::P12 P12; typedef typename type::P13 P13; 
		typedef typename type::P14 P14; typedef typename type::P15 P15; 
		typedef typename type::P16 P16; typedef typename type::P17 P17; 
		typedef typename type::P18 P18; typedef typename type::P19 P19;

		bool chk = 
			CHECKVALUE(0, p1, p2) && CHECKVALUE(1, p1, p2) && 
			CHECKVALUE(2, p1, p2) && CHECKVALUE(3, p1, p2) && 
			CHECKVALUE(4, p1, p2) && CHECKVALUE(5, p1, p2) && 
			CHECKVALUE(6, p1, p2) && CHECKVALUE(7, p1, p2) && 
			CHECKVALUE(8, p1, p2) && CHECKVALUE(9, p1, p2) && 
			CHECKVALUE(10, p1, p2) && CHECKVALUE(11, p1, p2) && 
			CHECKVALUE(12, p1, p2) && CHECKVALUE(13, p1, p2) && 
			CHECKVALUE(14, p1, p2) && CHECKVALUE(15, p1, p2) && 
			CHECKVALUE(16, p1, p2) && CHECKVALUE(17, p1, p2) && 
			CHECKVALUE(18, p1, p2) && CHECKVALUE(19, p1, p2);

		if(!ck)
			throw std::runtime_error("NewParam: Parameter set values do not match" );

		GETVALUE(0); GETVALUE(1); GETVALUE(2); GETVALUE(3); GETVALUE(4);
		GETVALUE(5); GETVALUE(6); GETVALUE(7); GETVALUE(8); GETVALUE(9);
		GETVALUE(10); GETVALUE(11); GETVALUE(12); GETVALUE(13); GETVALUE(14);
		GETVALUE(15); GETVALUE(16); GETVALUE(17); GETVALUE(18); GETVALUE(19);

		return type( v0, v1, v2, v3, v4, v5, v6, v7, v8, v9,
			     v10, v11, v12, v13, v14, v15, v16, v17, v18, v19);
 
	}
    

};




#endif // META_ALGEBRA_PARAMCOMBINER_H