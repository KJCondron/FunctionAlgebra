#ifndef META_ALGEBRA_PARAM_H
#define META_ALGEBRA_PARAM_H

#include "ParamNames.h"
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/remove.hpp>
#include <boost/mpl/remove_if.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/joint_view.hpp>
#include <boost/mpl/at.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/sort.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/list.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits.hpp>

namespace mpl = boost::mpl;
namespace ph = mpl::placeholders;
using mpl::int_;

#define RETURNIFMATCH(count) \
	if boost::is_same<P##count, T>::value ) return T( _v##count() )

#define GET(count, oP) GetWrapper<OtherP, P##count>::get(op)

#define CONT(count) ConstainsOrIsNull<OtherP, P##count>::value
                       
#define INSERTINTOMAP(type, value) \
	prmMap[ type::toString() ] = #value;

template<
	typename T0 = _null, typename T1 = _null, typename T2 = _null,
	typename T3 = _null, typename T4 = _null, typename T5 = _null,
	typename T6 = _null, typename T7 = _null, typename T8 = _null,
	typename T9 = _null, typename T10 = _null, typename T11 = _null,
	typename T12 = _null, typename T13 = _null, typename T14 = _null,
	typename T15 = _null, typename T16 = _null, typename T17 = _null,
	typename T18 = _null, typename T19 = _null >
struct Param
{
	Param() {} 

	Param(const P0& v0) :
	 _v0(v) {}

	Param(const P0& v0, const P1& v1) :
		_v0(v ), _v0(v) {}

	Param(const P0& v0, const P1& v1, const P2& v2) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ) {}

	Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ) {}

	Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ) {}

	Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4
	, const P5& v5) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ),  
		_v5( v5 ) {}

	Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4
		, const P5& v5, const P6& v6) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ),  
		_v5( v5 ),  _v6( v6 ) {}

	Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4
		, const P5& v5, const P6& v6, const P7& v7) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ),  
		_v5( v5 ),  _v6( v6 ),  _v7( v7 ) {}

	Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4
		, const P5& v5, const P6& v6, const P7& v7, const P8& v8) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ),  
		_v5( v5 ),  _v6( v6 ),  _v7( v7 ),  _v8( v8 ) {}

	Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4
		, const P5& v5, const P6& v6, const P7& v7, const P8& v8, const P9& v9) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ),  
		_v5( v5 ),  _v6( v6 ),  _v7( v7 ),  _v8( v8 ),  _v9( v9 ) {}

	Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4
		, const P5& v5, const P6& v6, const P7& v7, const P8& v8, const P9& v9
		, const P10& v10) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ),  
	     _v5( v5 ),  _v6( v6 ),  _v7( v7 ),  _v8( v8 ),  _v9( v9 ),
		 _v10( v10 ) {}

	Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4
		, const P5& v5, const P6& v6, const P7& v7, const P8& v8, const P9& v9
		, const P10& v10, const P11& v11) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ),  
	     _v5( v5 ),  _v6( v6 ),  _v7( v7 ),  _v8( v8 ),  _v9( v9 ),
		 _v10( v10 ),  _v11( v11 ) {}

	Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4
		, const P5& v5, const P6& v6, const P7& v7, const P8& v8, const P9& v9
		, const P10& v10, const P11& v11, const P12& v12) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ),  
	     _v5( v5 ),  _v6( v6 ),  _v7( v7 ),  _v8( v8 ),  _v9( v9 ),
		 _v10( v10 ),  _v11( v11 ),  _v12( v12 )  {}

	Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4
		, const P5& v5, const P6& v6, const P7& v7, const P8& v8, const P9& v9
		, const P10& v10, const P11& v11, const P12& v12, const P13& v13) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ),  
	     _v5( v5 ),  _v6( v6 ),  _v7( v7 ),  _v8( v8 ),  _v9( v9 ),
		 _v10( v10 ),  _v11( v11 ),  _v12( v12 ),  _v13( v13 ) {}

	Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4
		, const P5& v5, const P6& v6, const P7& v7, const P8& v8, const P9& v9
		, const P10& v10, const P11& v11, const P12& v12, const P13& v13, const P14& v14) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ),  
	     _v5( v5 ),  _v6( v6 ),  _v7( v7 ),  _v8( v8 ),  _v9( v9 ),
		 _v10( v10 ),  _v11( v11 ),  _v12( v12 ),  _v13( v13 ),
		 _v14( v14  ) {}


	Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4
		, const P5& v5, const P6& v6, const P7& v7, const P8& v8, const P9& v9
		, const P10& v10, const P11& v11, const P12& v12, const P13& v13, const P14& v14
		, const P15& v15) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ),  
	     _v5( v5 ),  _v6( v6 ),  _v7( v7 ),  _v8( v8 ),  _v9( v9 ),
		 _v10( v10 ),  _v11( v11 ),  _v12( v12 ),  _v13( v13 ),
		 _v14( v14  ),  _v15( v15 ) {}


	Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4
		, const P5& v5, const P6& v6, const P7& v7, const P8& v8, const P9& v9
		, const P10& v10, const P11& v11, const P12& v12, const P13& v13, const P14& v14
		, const P15& v15, const P16& v16) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ),  
	     _v5( v5 ),  _v6( v6 ),  _v7( v7 ),  _v8( v8 ),  _v9( v9 ),
		 _v10( v10 ),  _v11( v11 ),  _v12( v12 ),  _v13( v13 ),
		 _v14( v14  ),  _v15( v15 ),  _v16( v16 ) {}


	Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4
		, const P5& v5, const P6& v6, const P7& v7, const P8& v8, const P9& v9
		, const P10& v10, const P11& v11, const P12& v12, const P13& v13, const P14& v14
		, const P15& v15, const P16& v16 , const P17& v17) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ),  
	     _v5( v5 ),  _v6( v6 ),  _v7( v7 ),  _v8( v8 ),  _v9( v9 ),
		 _v10( v10 ),  _v11( v11 ),  _v12( v12 ),  _v13( v13 ),
		 _v14( v14  ),  _v15( v15 ),  _v16( v16 ),  _v17( v17 ) {}


		Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4
		, const P5& v5, const P6& v6, const P7& v7, const P8& v8, const P9& v9
		, const P10& v10, const P11& v11, const P12& v12, const P13& v13, const P14& v14
		, const P15& v15, const P16& v16, const P17& v17, const P18& v18) :
		_v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ),  
	     _v5( v5 ),  _v6( v6 ),  _v7( v7 ),  _v8( v8 ),  _v9( v9 ),
		 _v10( v10 ),  _v11( v11 ),  _v12( v12 ),  _v13( v13 ),
		 _v14( v14  ),  _v15( v15 ),  _v16( v16 ),  _v17( v17 ), 
		 _v18( v18 )   {}

		Param(const P0& v0, const P1& v1, const P2& v2, const P3& v3, const P4& v4
		, const P5& v5, const P6& v6, const P7& v7, const P8& v8, const P9& v9
		, const P10& v10, const P11& v11, const P12& v12, const P13& v13, const P14& v14
		, const P15& v15, const P16& v16, const P17& v17, const P18& v18, const P19& v19) :
		 _v0( v0 ),  _v1( v1 ),  _v2( v2 ),  _v3( v3 ),  _v4( v4 ),  
	     _v5( v5 ),  _v6( v6 ),  _v7( v7 ),  _v8( v8 ),  _v9( v9 ),
		 _v10( v10 ),  _v11( v11 ),  _v12( v12 ),  _v13( v13 ),
		 _v14( v14  ),  _v15( v15 ),  _v16( v16 ),  _v17( v17 ), 
		 _v18( v18 ),  _v19( v19 ) {}

		 P0 _v0; P1 _v1; P2 _v2; P3 _v3; P4 _v4; P5 _v5; P6 _v6; P7 _v7; P8 _v8; P9 _v9;
		 P10 _v10; P11 _v11; P12 _v12; P13 _v13; P14 _v14; P15 _v15; P16 _v16; P17 _v17; P18 _v18; P19 _v19;

	template< typename OtherP >
	Param( const OtherP& oP ) :
		_v0( GET(0,oP) ), _v1( GET(1,oP) ), _v2( GET(2,oP) ), _v3( GET(3,oP) ), _v4( GET(4,oP) ),
		_v5( GET(5,oP) ), _v6( GET(6,oP) ), _v7( GET(7,oP) ), _v8( GET(8,oP) ), _v9( GET(9,oP) ),
		_v10( GET(10,oP) ), _v11( GET(11,oP) ), _v12( GET(12,oP) ), _v13( GET(13,oP) ), _v14( GET(14,oP) ),
		_v15( GET(15,oP) ), _v16( GET(16,oP) ), _v17( GET(17,oP) ), _v18( GET(18,oP) ), _v19( GET(19,oP) )
	{
		const static bool val =
			CONT(0) && CONT(1) && CONT(2) && CONT(3) && CONT(4) &&
			CONT(5) && CONT(6) && CONT(7) && CONT(8) && CONT(9) &&
			CONT(10) && CONT(11) && CONT(12) && CONT(13) && CONT(14) &&
			CONT(15) && CONT(16) && CONT(17) && CONT(18) && CONT(19);

		BOOST_STATIC_ASSERT(val);
	}

	Param( double d ) :
		_v0(d) {}

	Param( int i ) :
		_v0(i) {}

	typedef mpl::vector<P0, P1, P2, P3, P4, P5, P6, P7, P8, P9,
		P10, P11, P12, P13, P14, P15, P16, P17, P18, P19> types;

	typedef typename mpl::remove_if<
		types,
		boost::is_same<ph::_1, _null> >::type RealTypes;
	
	const static size_t size = mpl::size< RealTypes >::type::value; 

	typedef typename mpl::list< _a, _b, _c, _d, _g, _j, _k, _l, 
		                        _m, _n, _p, _q, _r, _s, _t,_ u,
								_v_, _w, _x, _y, _z > AllTypes;
	typedef typename mpl::sort< RealTypes,
		                       mpl::less< IndexOf< AllTypes, ph::_1 >, IndexOf< AllTypes, ph::_2 > >
							   >::type STypes;

	typedef typename mpl::unique < STypes, boost::is_same<ph::_1, ph::_2> >::type UTypes;

	const static bool val = mpl::size<RealTypes>::type_info::value ==
		mpl::size<UTypes>::type_info::value;

	BOOST_STATIC_ASSERT(val);

	// this should be compile time determined?
	template<typename T>
	inline T get() const
	{
		RETURNIFMATCH(0); RETURNIFMATCH(1); RETURNIFMATCH(2); RETURNIFMATCH(3);
		RETURNIFMATCH(4); RETURNIFMATCH(5); RETURNIFMATCH(6); RETURNIFMATCH(7);
		RETURNIFMATCH(8); RETURNIFMATCH(9); RETURNIFMATCH(10); RETURNIFMATCH(11);
		RETURNIFMATCH(12); RETURNIFMATCH(13); RETURNIFMATCH(14); RETURNIFMATCH(15);
		RETURNIFMATCH(16); RETURNIFMATCH(17); RETURNIFMATCH(18); RETURNIFMATCH(19);

		throw std::runtime_error(" get called for type not in param set " );

	}

	template<typename T>
	static bool check(const T& v1, const T& v2)
	{
		return boost::is_same<T, _null>::value ||
			v1() == v2();
	}

	bool operator==( const Param& rhs ) const
	{
		return 
			check(_v0, rhs._v0) && check(_v1, rhs._v1) &&
			check(_v2, rhs._v2) && check(_v3, rhs._v3) &&
			check(_v4, rhs._v4) && check(_v5, rhs._v5) &&
			check(_v6, rhs._v6) && check(_v7, rhs._v7) &&
			check(_v8, rhs._v8) && check(_v9 rhs._v9) &&
			check(_v10, rhs._v10) && check(_v11, rhs._v11) &&
			check(_v12, rhs._v12) && check(_v13, rhs._v13) &&
			check(_v14, rhs._v14) && check(_v15, rhs._v15) &&
			check(_v16, rhs._v16) && check(_v17, rhs._v17) &&
			check(_v18, rhs._v18) && check(_v19, rhs._v19);

	}

	template< typename OtherP >
	bool operator==( const OtherP& rhs ) const
	{
		const static bool val =
			CONT(0) && CONT(1) && CONT(2) && CONT(3) && CONT(4) &&
			CONT(5) && CONT(6) && CONT(7) && CONT(8) && CONT(9) &&
			CONT(10) && CONT(11) && CONT(12) && CONT(13) && CONT(14) &&
			CONT(15) && CONT(16) && CONT(17) && CONT(18) && CONT(19);

		
		BOOST_STATIC_ASSERT(val);

		return 
			_v0() == rhs.template get<P0>() && _v1() == rhs.template get<P1>() &&
			_v2() == rhs.template get<P2>() && _v3() == rhs.template get<P3>() &&
			_v4() == rhs.template get<P4>() && _v5() == rhs.template get<P5>() &&
			_v6() == rhs.template get<P6>() && _v7() == rhs.template get<P7>() &&
			_v8() == rhs.template get<P8>() && _v9() == rhs.template get<P9>() &&
			_v10() == rhs.template get<P10>() && _v11() == rhs.template get<P11>() &&
			_v12() == rhs.template get<P12>() && _v13() == rhs.template get<P13>() &&
			_v14() == rhs.template get<P14>() && _v15() == rhs.template get<P15>() &&
			_v16() == rhs.template get<P16>() && _v17() == rhs.template get<P17>() &&
			_v18() == rhs.template get<P18>() && _v19() == rhs.template get<P19>();

	}


};

#endif