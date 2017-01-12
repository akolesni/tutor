#include "FunctionalTest.h"
#include <iostream>
#include <functional>
#include <random>

//void f(int n1, int n2, int n3, const int& n4, int n5)
//{
//  std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
//}
//
//int g(int n1)
//{
//  return n1;
//}
//
//struct Foo
//{
//  void print_sum(int n1, int n2)
//  {
//    std::cout << n1 + n2 << '\n';
//  }
//  int data = 10;
//};

FunctionalTest::FunctionalTest()
{
}


FunctionalTest::~FunctionalTest()
{
}

void FunctionalTest::Do()
{
  //TestBind1();
  TestBind2();
  //TestBind3();
}

// ------------------------------------------------------------------------------------------------
void f(int n1, int n2, int n3, const int& n4, int n5)
{
  std::cout << n1 << ' ' << n2 << ' ' << n3 << ' ' << n4 << ' ' << n5 << '\n';
}



struct Foo
{
  void print_sum(int n1, int n2)
  {
    std::cout << n1 + n2 << '\n';
  }
  int data = 10;
};
// ------------------------------------------------------------------------------------------------
void FunctionalTest::TestBind1()
{
  //using namespace std::placeholders;

  // demonstrates argument reordering and pass-by-reference
  int n = 7;

  auto f1 = std::bind(
    f,                    // f()
    std::placeholders::_2,
    std::placeholders::_1,
    42,
    std::cref(n),
    n);

  n = 10;
  f1(1, 2, 1001); // 1 is bound by _1, 2 is bound by _2, 1001 is unused
  /*
  ---------------------
  2 1 42 10 7
  ---------------------
  */
}

int g(int n1)
{
  return n1;
}
void FunctionalTest::TestBind2()
{
   //nested bind subexpressions share the placeholders
  auto f2 = std::bind(
    f,
    std::placeholders::_3,
    std::bind(g, std::placeholders::_3),
    std::placeholders::_3,
    4,
    5);

  f2(10, 11, 12);
  /*
  ---------------------
  12 12 12 4 5
  ---------------------
  */

}

void FunctionalTest::TestBind3()
{
  // common use case: binding a RNG with a distribution
  std::default_random_engine e;
  std::uniform_int_distribution<> d(0, 10);
  std::function<int()> rnd = std::bind(d, e);
  for (int n = 0; n<10; ++n)
    std::cout << rnd() << ' ';
  std::cout << '\n';

  // bind to a member function
  Foo foo;
  auto f3 = std::bind(&Foo::print_sum, foo, 95, std::placeholders::_1);
  f3(5);

  // bind to member data
  auto f4 = std::bind(&Foo::data, std::placeholders::_1);
  std::cout << f4(foo) << '\n';
}