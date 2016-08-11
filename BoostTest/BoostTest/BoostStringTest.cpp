#include "BoostStringTest.h"
#include <boost/algorithm/string/trim.hpp>
#include <string>
#include <iostream>

/**
 *@brief - Constructor
 */
BoostStringTest::BoostStringTest()
{
}

/**
 *@brief - Destructor
 */
BoostStringTest::~BoostStringTest()
{
}

void BoostStringTest::Do()
{
	std::string null_string(nullptr);

	std::string str1(" \t  123  456  \n \t    ");

	boost::trim(str1);

	std::cout << str1 << std::endl;
}
