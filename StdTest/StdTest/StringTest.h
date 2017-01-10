#pragma once
#include <string>

class StringTest
{
public:
  StringTest();
  ~StringTest();
  void Do();
private:
  void Test1();
  void Str1(std::string strParam);
  void Str2(std::string& strParam);
  void Str3(const std::string& strParam);
  void Str4(std::string&& strParam);
  void Str(std::string& strParam);
};

