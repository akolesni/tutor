#include "Cpp11_17Test.h"
#include <memory>
#include <iostream>


Cpp11_17Test::Cpp11_17Test()
{
}


Cpp11_17Test::~Cpp11_17Test()
{
}

void Cpp11_17Test::Do()
{
  //this->TestNullPtr();
  this->TestDigitSeparators();
}

void foo(int* p)
{
  std::cout << "foo " << std::endl;
}

void bar(std::shared_ptr<int> p)
{
  if (p == nullptr)
  {
    std::cout << "bar " << std::endl;
  }
}

void Cpp11_17Test::TestNullPtr()
{
  int* p1 = NULL;
  int* p2 = nullptr;

  int* i1 = nullptr;
  int* i2 = nullptr;

  if (i1 == i2)
  {
    std::cout << "if 1" << std::endl;
  }

  if (p1 == p2)
  {
    std::cout << "if 2" << std::endl;
  }

  std::cout << "sizeof(nullptr) " << sizeof(nullptr) << std::endl;
  std::cout << "sizeof(NULL) "    << sizeof(NULL) << std::endl;

  foo(nullptr);
  bar(nullptr);

  bool f = nullptr;
  //int i = nullptr; // ошибка: для преобразования в int надо использовать reinterpret_cast
}

// 14
void Cpp11_17Test::TestDigitSeparators()
{
  auto integer_literal = 1'000'000;
  auto floating_point_literal = 0.000'015'3;
  auto binary_literal = 0b0100'1100'0110;
  auto silly_example = 1'0'0'000'00;

  //int a1 = 1`000;
  //int a2 = 1´000;
  int a3 = 1'000'000;

  std::cout << "a3 " << a3 << std::endl;
}
