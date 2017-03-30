#pragma once
class TProcessMemory
{
public:
  TProcessMemory();
  ~TProcessMemory();
  void Do();
  void test1();

private:
  size_t GetMamorySize();
};

