#pragma once
#include <string>
#include "Netioapi.h"
class TestNetApi
{
public:
  TestNetApi();
  ~TestNetApi();
  void Do();

private:
  void Test1();
  static std::string rowToString(MIB_IF_ROW2& _row);
};

