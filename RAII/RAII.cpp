//============================================================================
// Name        : RAII.cpp
// Author      : Ich
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Base.h"
#include "UniquePtr.h"

using namespace std;

void demoResourceLeak ( bool throwException);
void demoMakeUnique();

int main() {
	cout << "RAII" << endl;
	try {
		//demoResourceLeak(false);
		//demoResourceLeak(true);
		//Handler<Base> pb(new Derived);
		//Handler<Derived> pd(new Derived);
		//Handler<Base> pb2(std::move(pd));
		//auto p=makeUnique<Base>(1);
		demoMakeUnique();

	}
	catch (std::exception& e){
		cout << e.what();
	}
	return 0;
}
void demoMakeUnique(){
	//Base b;
	//auto h1 = makeUnique<Base>(b);
	auto h2 = makeUnique<Base>(Base(1));

}
void demoResourceLeak ( bool throwException){

	std::cout << __PRETTY_FUNCTION__ << std::endl;
	UniquePtr<Base> h(new Base);
	UniquePtr<Base>& rh = h;
	h = std::move(rh);

	h->operation();

//	Handler h2(new T);
	//h = std::move(h2);


	//(*h).operation();

	if( throwException){
		throw std::logic_error("exception");
	}
	else {
		return;
	}
}
