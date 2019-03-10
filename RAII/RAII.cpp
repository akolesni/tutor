#include "Base.h"
#include "UniquePtr.h"
#include "SharedPtr.h"
#include "TestSharedPtr.h"

using namespace std;

void demoResourceLeak ( bool throwException);
void demoMakeUnique();
void demoSharedPtr();
void copySharedPtr(SharedPtr<Base> sharedPtr);
void copySharedPtr2(SharedPtr<Base> sharedPtr);

int main() {
	cout << "RAII" << endl;
	try {
        // demoResourceLeak(false);
        // demoResourceLeak(true);
        // Handler<Base> pb(new Derived);
        // Handler<Derived> pd(new Derived);
        // Handler<Base> pb2(std::move(pd));
        // auto p=makeUnique<Base>(1);
        // demoMakeUnique();
        //demoSharedPtr();
        TestSharedPtr testSharedPtr;
        testSharedPtr.Do();
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

	if( throwException){
		throw std::logic_error("exception");
	}
	else {
		return;
	}
}

void demoSharedPtr()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    SharedPtr<Base> sharedPtr(new Base(10));
    copySharedPtr(sharedPtr);
    copySharedPtr(sharedPtr);
    copySharedPtr(sharedPtr);
}

void copySharedPtr(SharedPtr<Base> sharedPtr)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    sharedPtr->operation();
    copySharedPtr2(sharedPtr);
}

void copySharedPtr2(SharedPtr<Base> sharedPtr)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    sharedPtr->operation();
}
