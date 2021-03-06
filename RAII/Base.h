#ifndef BASE_H
#define BASE_H

#include <iostream>

class Base{

public:

	Base( ):i(0){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	Base(int i):i(i){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	Base (Base && base){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	Base (const Base & base){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	~Base(){
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	void operation(){
		std::cout << __PRETTY_FUNCTION__ << "i: " << i << std::endl;
	}

private:
	int i;
};

#endif // BASE_H
