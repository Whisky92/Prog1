#include "std_lib_facilities.h"

class B1 {
public:
	virtual void vf()
	{ cout << "B1::vf\n"; }
	void f() 
	{ cout << "B1::f\n"; }
	virtual void pvf() = 0;
};

class D1 : public B1 {
public:
	void vf() override
	{ cout << "D1::vf\n"; }
	void f() 
	{ cout << "D1::f\n"; }
	void pvf() override
	{ cout << "D1::pvf\n"; }
};

class D2 : public D1 {
public:
	void pvf() override
	{ cout << "D2::pvf\n"; }
};

class B2 {
public:
	virtual void pvf() 
	{ cout << "B2::pvf\n"; }
};

class D21 : public B2 {
public:
	void pvf() override
	{ cout << szoveg << endl; }
private:
	string szoveg{"14. drill\n"};
};

class D22 : public B2 {
public:
	void pvf() override
	{ cout << n << endl; }
private:
	int n = 15;
};

void f(B2 &p)
{
	p.pvf();
}

int main() 
{

D1 d1;
d1.vf();
d1.f();

B1 &b1ref = d1;
b1ref.vf();
b1ref.f();

D2 d2;
d2.vf();
d2.f();
d2.pvf();

D21 d21;
D22 d22;
f(d21);
f(d22);

return 0;
}