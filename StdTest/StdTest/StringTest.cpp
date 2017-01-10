#include "StringTest.h"
#include <iostream>


StringTest::StringTest()
{
}


StringTest::~StringTest()
{
}

void StringTest::Do()
{
  this->Test1();
}

void StringTest::Test1()
{
  this->Str1("Str1");

  // void Str2(std::string& strParam);
  // error C2664: 'void StringTest::Str2(std::string &)': 
  // cannot convert argument 1 from 'const char [5]' to 'std::string &'
  //this->Str2("Str2");

  this->Str3("Str3");
  this->Str4("Str4");
}

void StringTest::Str1(std::string strParam)
{
  std::cout << "Str1 " << strParam << std::endl;
  Str(strParam);
}

void StringTest::Str2(std::string& strParam)
{
  std::cout << "Str2 " << strParam << std::endl;
  Str(strParam);
}

void StringTest::Str3(const std::string& strParam)
{
  std::cout << "Str3 " << strParam << std::endl;

  // 'void StringTest::Str(std::string &)':
  //cannot convert argument 1 from 'const std::string' to 'std::string &'
  //Str(strParam);
}

void StringTest::Str4(std::string&& strParam)
{
  std::cout << "Str4 " << strParam << std::endl;
  Str(strParam);
}

void StringTest::Str(std::string& strParam)
{
  std::cout << "Str " << strParam << std::endl;
}