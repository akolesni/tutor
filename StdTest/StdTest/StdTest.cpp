// StdTest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <memory>
// ---------
#include "TupleTest.h"
#include "VectorTest.h"
#include "FunctionalTest.h"
#include "AlgorithmTest.h"
#include "Cpp11_17Test.h"
#include "StringTest.h"
#include "MemoryTest.h"
#include "StdTest.h"
#include "StreamTest.h"

int main()
{
  //TupleTest containerTest;
  //containerTest.Do();
  //VectorTest vector_test;
  //vector_test.Do();
  //FunctionalTest functional_test;
  //functional_test.Do();
  //AlgorithmTest algorithm;
  //algorithm.Do();
  Cpp11_17Test cpp11;
  cpp11.Do();
  //StringTest string_test;
  //string_test.Do();
  //MemoryTest memoryTest;
  //memoryTest.Do();
  //StreamTest streamTest;
  //streamTest.Do();

  //std::cout << "Pointer safety: ";
  //switch (std::get_pointer_safety()) {
  //case std::pointer_safety::relaxed:   std::cout << "relaxed";   break;
  //case std::pointer_safety::preferred: std::cout << "preferred"; break;
  //case std::pointer_safety::strict:    std::cout << "strict";    break;
  //}
  //std::cout << '\n';

  system("pause");
  return 0;
}

