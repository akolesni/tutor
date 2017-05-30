#include "MemoryTest.h"
#include <iostream>


MemoryTest::MemoryTest()
{
}


MemoryTest::~MemoryTest()
{
}

void MemoryTest::Do()
{
  this->TestUniqPtr();
}


class UTest
{
public:
  UTest()
  {
    std::cout << "Construct" << std::endl;
  }

  ~UTest()
  {
    std::cout << "Destruct" << std::endl;
  }

};

void MemoryTest::TestUniqPtr()
{
  UTest utest;
}
