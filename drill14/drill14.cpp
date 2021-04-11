#include "std_lib_facilities.h"

class B1
{
public: 
	virtual void vf(){cout << "B1::vf"<<endl;}
	void f(){cout << "B1::f"<<endl;}
	virtual void pvf()=0;
};

class D1: public B1
{
public:
	void vf() override{cout << "D1::vf"<<endl;}
	void f() {cout << "D1::f"<<endl;}

};

class D2 : public D1
{
public:	
	void pvf() override{cout<<"D2::pvf"<<endl;}


};

class B2
{
public:	
	virtual void pvf()=0;
};

class D21 : public B2
{
	string dm = "D21::pvf()";

public:

	void pvf() override {cout << dm << endl;}


};

class D22 : public B2
{
	int dm=22;

public:
	void pvf() override {cout << dm << endl;}
};


void f(B2& ref)
{
	ref.pvf();
}


int main()
{
	/*B1 b1;
	b1.vf();
	b1.f();
	D1 d1;
	d1.vf();
	d1.f();*/

	D2 d2;
	d2.vf();
	d2.f();
	d2.pvf();

	B1& b1_r=d2;
	b1_r.vf();
	b1_r.f();

	D21 d21;
	D22 d22;
	f(d21);
	f(d22);


	return 0;
}