// StdTest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <cstdlib>
// ---------
#include "TupleTest.h"
#include "VectorTest.h"
#include "FunctionalTest.h"
#include "AlgorithmTest.h"
#include "Cpp11_17Test.h"
#include "StringTest.h"
#include "MemoryTest.h"
#include "StdTest.h"

int main()
{
  //TupleTest containerTest;
  //containerTest.Do();
  VectorTest vector_test;
  vector_test.Do();
  //FunctionalTest functional_test;
  //functional_test.Do();
  //AlgorithmTest algorithm;
  //algorithm.Do();
  //Cpp11_17Test cpp11;
  //cpp11.Do();
  //StringTest string_test;
  //string_test.Do();
  //MemoryTest memoryTest;
  //memoryTest.Do();

  system("pause");
  return 0;
}

