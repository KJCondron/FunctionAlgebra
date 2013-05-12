#ifndef META_ALGEBRA_PARAMNAMES_H
#define META_ALGEBRA_PARAMNAMES_H

#include <string>

#ifdef FOR_PRINTING
	#define CONSTRUCTOR(letter) \
	_##letter() : _val(-1) {} \
	_##letter( double val ) : _val(val) {}	
#else
#define CONSTRUCTOR(letter) \
	_##letter( double val ) : _val(val) {}
#endif

#define MAKEPARAMETER(letter) \
	struct _##letter \
	{ \
		CONSTRUCTOR(letter) \
		const double& operator()() const { return _val; } \
		static std::string toString()  { return #letter; } \
		double _val; \
	};

#define DECL(letter, identity) \
	MAKEPARAMETER(letter); \
	Identity<_##type> identity;

#define DEC(letter) DECL(letter, letter);

MAKEPARAMETER(a);
MAKEPARAMETER(b);
MAKEPARAMETER(c);
MAKEPARAMETER(d);
MAKEPARAMETER(g);
MAKEPARAMETER(j);
MAKEPARAMETER(k);
MAKEPARAMETER(m);
MAKEPARAMETER(n);
MAKEPARAMETER(p);
MAKEPARAMETER(q);
MAKEPARAMETER(r);
MAKEPARAMETER(s);
MAKEPARAMETER(t);
MAKEPARAMETER(u);
MAKEPARAMETER(v);
MAKEPARAMETER(w);
MAKEPARAMETER(x);
MAKEPARAMETER(y);
MAKEPARAMETER(z);

struct _null
{
	_null() {}
	double operator()() const { throw; }
	static std::string toString() { return "null"; }
};


#endif