#include "TupleTest.h"

#include <tuple>
#include <vector>
#include <iostream>
#include <string>

TupleTest::TupleTest()
{
}


TupleTest::~TupleTest()
{
}

void TupleTest::Do()
{
  //this->TupelTest1();
  //this->TupelTest2();
  this->TupleTest7();
}

void TupleTest::TupleTest0()
{
  std::tuple<int, char> first;                             // default
  std::tuple<int, char> second(first);                    // copy
  std::tuple<int, char> third(std::make_tuple(20, 'b'));   // move
  std::tuple<long, char> fourth(third);                   // implicit conversion
  std::tuple<int, char> fifth(10, 'a');                    // initialization
  std::tuple<int, char> sixth(std::make_pair(30, 'c'));    // from pair / move

  std::cout << "sixth contains: " << std::get<0>(sixth);
  std::cout << " and " << std::get<1>(sixth) << '\n';
}

typedef std::tuple<int, int, int> i3tuple;
/*
http://www.cplusplus.com/reference/tuple/

*/
void TupleTest::TupelTest1()
{


  std::vector<i3tuple> v;
  for (int i = 0; i < 10; i++)
  {
    v.push_back(i3tuple(i, i * 2, i * 2 + 1));
  }

  for (i3tuple t : v)
  {
    std::cout << std::get<0>(t) << ' ';
    std::cout << std::get<1>(t) << ' ';
    std::cout << std::get<2>(t) << '\n';
  };
}

void TupleTest::TupelTest2()
{
  // -------------
  auto t = std::make_tuple("String", 5.2, 1);

  std::cout << std::get<0>(t) << ' '
    << std::get<1>(t) << ' '
    << std::get<2>(t) << '\n';
}

void TupleTest::TupelTest3()
{
  std::tuple<int, char, double> mytuple(10, 'a', 3.14);

  std::cout << "mytuple has ";

  std::cout << std::tuple_size<decltype(mytuple)>::value;

  std::cout << " elements." << '\n';
}

void TupleTest::TupleTest4()
{
  auto mytuple = std::make_tuple(10, 'a');

  std::cout << std::get<0>(mytuple) << ' ' << std::get<1>(mytuple) << '\n';


  std::tuple_element<0, decltype(mytuple)>::type first = 20;
  std::tuple_element<1, decltype(mytuple)>::type second = 'b';

  std::cout << "mytuple contains: " << first << " and " << second << '\n';
  // mytuple contains: 20 and b
}

void print_pack(std::tuple<std::string&&, int&&> pack)
{
  std::cout << std::get<0>(pack) << ", " << std::get<1>(pack) << '\n';
}

void TupleTest::TupleTest5()
{
  // forward_as_tuple (кортеж из ссылок на временные значения )

  std::string str("John");

  auto mytuple = std::make_tuple(       str + " Smith", 25);
  auto mytupleF = std::forward_as_tuple(str + " Smith", 25);
  auto v1 = std::get<0>(mytupleF);
  auto v2 = std::get<1>(mytupleF);


  std::cout << std::get<0>(mytuple) << ", " << std::get<1>(mytuple) << '\n';
  std::cout << std::get<0>(mytupleF) << ", " << std::get<1>(mytupleF) << '\n';

  print_pack(std::forward_as_tuple(str + " Smith", 25));
  print_pack(std::forward_as_tuple(str + " Daniels", 22));
}

void TupleTest::TupleTest6()
{
  int myint;
  char mychar;

  std::tuple<int, float, char> mytuple;

  mytuple = std::make_tuple(10, 2.6, 'a');          // packing values into tuple

  std::tie(myint, std::ignore, mychar) = mytuple;   // unpacking tuple into variables

  std::cout << "myint contains: " << myint << '\n';
  std::cout << "mychar contains: " << mychar << '\n';
}

void TupleTest::TupleTest7()
{
  std::tuple<float, std::string> mytuple(3.14, "pi");

  std::pair<int, char> mypair(10, 'a');

  auto myauto = std::tuple_cat(mytuple, std::tuple<int, char>(mypair));

  std::cout << "myauto contains: " << '\n';
  std::cout << std::get<0>(myauto) << '\n';
  std::cout << std::get<1>(myauto) << '\n';
  std::cout << std::get<2>(myauto) << '\n';
  std::cout << std::get<3>(myauto) << '\n';
}