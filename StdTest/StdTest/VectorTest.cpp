#include "VectorTest.h"
#include <iostream>
#include <vector>


VectorTest::VectorTest()
{
}


void VectorTest::Do()
{
  this->Test1();
}

VectorTest::~VectorTest()
{
}

class MyKlass {
public:
  MyKlass(const MyKlass& _other)
    : i(_other.i),
      f(_other.f)
  {
    std::cout << "Kopy-Construct\n";
  }

  MyKlass(MyKlass&& _other)
    : i(_other.i),
      f(_other.f)
  {
    std::cout << "Move-Construct\n";
  }

  MyKlass& operator=(const MyKlass& _other)
  {
    std::cout << "operator=\n";
    if (this == &_other)
      return *this;
    i = _other.i;
    f = _other.f;
    return *this;
  }

  MyKlass& operator=(MyKlass&& _other)
  {
    std::cout << "operator= move\n";
    if (this == &_other)
      return *this;
    i = _other.i;
    f = _other.f;
    return *this;
  }

public:
  MyKlass(int ii_, float ff_)
  {
    i = ii_;
    f = ff_;
    std::cout << "Construct " << ii_ << " " << ff_ << "\n";
  }
  ~MyKlass()
  {
    std::cout << "Destruct\n";
  }
private:
  int i;
  float f;
};

void VectorTest::Test1()
{
  std::vector<MyKlass> v;
  /*
    Сначала выполняется конструктор временного объекта класса MyKlass
    Затем, для объекта, непосредственно расположенного внутри вектора, вызывается конструктор перемещения (если такой определен в MyClass, если не определен – тогда вызывается конструктор копирования)
    Деструктор временного объекта
  */
  std::cout << "push_back+\n";
  v.push_back(MyKlass(2, 3.14f));
  std::cout << "push_back-\n\n\n";


  std::cout << "emplace_back-\n";
  v.emplace_back(2, 3.14f);
  std::cout << "emplace_back-\n\n\n";

}
