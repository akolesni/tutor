#pragma once
class Cpp11_17Test
{
public:
  Cpp11_17Test();
  ~Cpp11_17Test();
    void Do();

private:
  void TestNullPtr();
  [[deprecated("TestDigitSeparators is deprecated")]] void TestDigitSeparators();
  void TestSmartPointer();
};
