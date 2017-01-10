#include "AlgorithmTest.h"
#include <iostream>


AlgorithmTest::AlgorithmTest()
{
}


AlgorithmTest::~AlgorithmTest()
{
}

void AlgorithmTest::Do()
{
  this->TestFor();
}

void AlgorithmTest::TestFor()
{
  int arr[] = { 1,2,3 };

  int* b =  std::begin(arr);
  int* e = std::end(arr);

  std::cout << *b << " begin " << b << " end " << e << std::endl;


  for(int& a: arr)
  {
    std::cout << a << std::endl;
    a = 7;
  }

  std::cout << "for 2" << std::endl;

  for (int a1 : arr)
  {
    std::cout << a1 << std::endl;
  }
}