#include "Ch1.h"
#include <iostream>

void trace(const char* pMsg) {
	std::cout << pMsg << std::endl;
}

class CA : public IX,
	public IY
{
public:
	virtual void __stdcall Fx1() { std::cout << "CA::Fx1" << std::endl; }
	virtual void __stdcall Fx2() { std::cout << "CA::Fx2" << std::endl; }
	virtual void __stdcall Fx3() { std::cout << "CA::Fx3" << std::endl; }
	virtual void __stdcall Fx4() { std::cout << "CA::Fx4" << std::endl; }

	virtual void __stdcall Fy1() { std::cout << "CA::Fy1" << std::endl; }
	virtual void __stdcall Fy2() { std::cout << "CA::Fy2" << std::endl; }

	CA(double d) :m_Fx2(d* d), m_Fx3(d* d), m_Fx4(d* d* d* d) {}

	double m_Fx2;
	double m_Fx3;
	double m_Fx4;
};

class CB : public IX
{
public:
	virtual void __stdcall Fx1() { std::cout << "CB::Fx1" << std::endl; }
	virtual void __stdcall Fx2() { std::cout << "CB::Fx2" << std::endl; }

	virtual void __stdcall Fx3() { std::cout << "CB::Fx3" << std::endl; }
	virtual void __stdcall Fx4() { std::cout << "CB::Fx4" << std::endl; }
};

void foo(IX* pIX) {
	pIX->Fx1();
	pIX->Fx2();
}

int main()
{
	trace("Client : Create an instance of the component.");

	CA* pa = new CA(1.5);
	IX* pIX = pa;
	pIX->Fx1();
	pIX->Fx2();

	IY* pIY = pa;
	pIY->Fy1();
	pIY->Fy2();

	CA* pa2 = new CA(2.5);

	CB* pb = new CB;
	pIX = pa;
	foo(pIX);

	pIX = pb;
	foo(pIX);

	delete pa;
	delete pa2;

	return 0;
}
