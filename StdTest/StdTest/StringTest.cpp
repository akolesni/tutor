#include "StringTest.h"
#include <iostream>
#include <cassert>
#include <algorithm>
#include <regex>

//const char* ws = " \t\n\r\f\v";

StringTest::StringTest()
{
}


StringTest::~StringTest()
{
}

void StringTest::Do()
{
  //this->Test1();
  //this->TrimTest();
  //this->LocaleTest();
  //this->HtmlEncoding();
  this->TestReplace();
}

void StringTest::Test1()
{
  this->Str1("Str1");

  // void Str2(std::string& strParam);
  // error C2664: 'void StringTest::Str2(std::string &)': 
  // cannot convert argument 1 from 'const char [5]' to 'std::string &'
  //this->Str2("Str2");

  this->Str3("Str3");
  this->Str4("Str4");
}

void StringTest::Str1(std::string strParam)
{
  std::cout << "Str1 " << strParam << std::endl;
  Str(strParam);
}

void StringTest::Str2(std::string& strParam)
{
  std::cout << "Str2 " << strParam << std::endl;
  Str(strParam);
}

void StringTest::Str3(const std::string& strParam)
{
  std::cout << "Str3 " << strParam << std::endl;

  // 'void StringTest::Str(std::string &)':
  //cannot convert argument 1 from 'const std::string' to 'std::string &'
  //Str(strParam);
}

void StringTest::Str4(std::string&& strParam)
{
  std::cout << "Str4 " << strParam << std::endl;
  Str(strParam);
}

void StringTest::Str(std::string& strParam)
{
  std::cout << "Str " << strParam << std::endl;
}


#include "StringHelpers.h"
void StringTest::TrimTest()
{
  std::string string1 = "";
  std::string string2 = "     ";
  std::string string3 = "     sss";
  std::string string4 = "sss     ";
  std::string string5 = " \t    sss  \n  ";
  std::string string6 = " \t\n\n s  s  s  ";

  assert(StringHelpers::trim(string1) == "");
  assert(StringHelpers::trim(string2) == "");
  assert(StringHelpers::trim(string3) == "sss");
  assert(StringHelpers::trim(string4) == "sss");
  assert(StringHelpers::trim(string5) == "sss");
  assert(StringHelpers::trim(string6) == "s  s  s");
}


#include <locale>
void StringTest::LocaleTest()
{
  char c = 'Ü';

  std::string str = "aaa";
  assert(std::find_if_not(str.begin(), str.end(), [](char c) {return isalnum(c); }) == str.end());
  str = "1a2a3a000";
  assert(std::find_if_not(str.begin(), str.end(), [](char c) {return isalnum(c); }) == str.end());
  str = "!aaa";
  assert(std::find_if_not(str.begin(), str.end(), [](char c) {return isalnum(c); }) != str.end());
  str = " ";
  assert(std::find_if_not(str.begin(), str.end(), [](char c) {return isalnum(c); }) != str.end());
  str = "ÄÄ";
  assert(std::find_if_not(str.begin(), str.end(), [](char c) {return c < 0 && isalnum(c); }) != str.end());
  str = "aaä";
  assert(std::find_if_not(str.begin(), str.end(), [](char c) {return c < 0 && isalnum(c); }) != str.end());
  str = "<>";
  assert(std::find_if_not(str.begin(), str.end(), [](char c) {return c < 0 && isalnum(c); }) != str.end());


/*
  assert(isalnum('1'));
  assert(isalnum('0'));
  assert(isalnum('a'));
  assert(isalnum('A'));
  //assert(isalnum('Ü') == false);
  //assert(isalnum('ß') == false);
  assert(isalnum(' ') == false);
  assert(isalnum('!') == false);
  assert(isalnum('\"') == false);
  assert(isalnum('\'') == false);
  assert(isalnum('\t') == false);
  assert(isalnum('\n') == false);
  assert(isalnum('%') == false);
  assert(isalnum('<') == false);
  assert(isalnum('>') == false);
  assert(isalnum('#') == false);
  assert(isalnum('/') == false);
  assert(isalnum('\\') == false);
  */
}

std::string& StringTest::HtmlEncoding(std::string& strInput)
{
  strInput = std::regex_replace(strInput, std::regex(std::string("<")), std::string("&lt;"));
  strInput = std::regex_replace(strInput, std::regex(std::string(">")), std::string("&gt;"));

  return strInput;
}



void StringTest::HtmlEncoding()
{
  std::string strInput = "ICOM1124380\"><script>alert(1)< / script><input name = \"nope\" value = \"";

  strInput = StringTest::HtmlEncoding(strInput);

  //std::replace(input.begin(), input.end(), "<", "");

  //strInput = std::regex_replace(strInput, std::regex(std::string("<")), std::string("&lt;"));
  //strInput = std::regex_replace(strInput, std::regex(std::string(">")), std::string("&gt;"));

  assert(strInput == "ICOM1124380\"&gt;&lt;script&gt;alert(1)&lt; / script&gt;&lt;input name = \"nope\" value = \"");

}


std::string ReplaceAll(std::string str, const std::string& from, const std::string& to)
{
  size_t start_pos = 0;
  while ((start_pos = str.find(from, start_pos)) != std::string::npos)
  {
    str.replace(start_pos, from.length(), to);
    start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
  }

  return str;
}

void StringTest::TestReplace()
{
  std::string strInput = "ICOM1124380\"><script>alert(1)< / script><input name = \"nope\" value = \"";

  std::string result = ReplaceAll(strInput, std::string("<"), std::string("&lt;"));
  result = ReplaceAll(result, std::string(">"), std::string("&gt;"));

  assert(result == "ICOM1124380\"&gt;&lt;script&gt;alert(1)&lt; / script&gt;&lt;input name = \"nope\" value = \"");
}

// trim from both ends of string (left & right)
//std::string& StringTest::trim(std::string& strInput)
//{
//  return ltrim(rtrim(strInput));
//}

// trim from end of string (right)
//std::string& StringTest::rtrim(std::string& strInput)
//{
//  strInput.erase(strInput.find_last_not_of(ws) + 1);
//
//  return strInput;
//}

// trim from beginning of string (left)
//std::string& StringTest::ltrim(std::string& strInput)
//{
//  strInput.erase(0, strInput.find_first_not_of(ws));
//
//  return strInput;
//}
