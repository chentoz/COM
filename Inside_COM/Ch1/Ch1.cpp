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

	virtual void __stdcall Fy1() { std::cout << "CA::Fy1" << std::endl; }
	virtual void __stdcall Fy2() { std::cout << "CA::Fy2" << std::endl; }
};

int main()
{
	trace("Client : Create an instance of the component.");

	CA* pa = new CA;
	IX* pIX = pa;
	pIX->Fx1();
	pIX->Fx2();

	IY* pIY = pa;
	pIY->Fy1();
	pIY->Fy2();

	delete pa;

	return 0;
}
