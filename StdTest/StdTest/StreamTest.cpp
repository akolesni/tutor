#include "StreamTest.h"
#include <fstream>
#include <iostream>

//https://habrahabr.ru/post/130472/
StreamTest::StreamTest()
{
}


StreamTest::~StreamTest()
{
}

void StreamTest::Do()
{
  this->Test01();
}

void StreamTest::Test01()
{
  std::ifstream f1("c:\\workspace\\github\\tutor\\resource\\Lena\\Lenna.png", std::ios::binary);

  if (!f1)
  {
    std::cout << "EROR\n";
    system("pause");
  }

  size_t count = 0;

  do
  {
    std::cout << f1.get() << std::endl;
    count++;
  } while (count < 20);
//} while (f1.eof());

  //std::cout << f1.getline();

}
