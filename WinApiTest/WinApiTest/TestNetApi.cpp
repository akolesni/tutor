#include "stdafx.h"

#include "TestNetApi.h"

#include <iostream>
#include <sstream>
#include <algorithm>

TestNetApi::TestNetApi()
{
}


TestNetApi::~TestNetApi()
{
}

void TestNetApi::Do()
{
  this->Test1();
}





void TestNetApi::Test1()
{
  MIB_IF_TABLE2* table = nullptr;
 if (::GetIfTable2(&table) == NO_ERROR)
 {
   std::cout << "Num " << table->NumEntries << "\n";

   std::for_each(
     &table->Table[0],
     &table->Table[table->NumEntries],
     [](MIB_IF_ROW2& row)
   {
     std::cout << rowToString(row);
   });

   FreeMibTable(table);
 }
 else
 {

 }
}

/*
https://msdn.microsoft.com/en-us/library/windows/desktop/aa814491(v=vs.85).aspx
*/
std::string TestNetApi::rowToString(::MIB_IF_ROW2& _row)
{
  std::wostringstream oss;
  //oss << "InterfaceLuid\n\tValue " << _row.InterfaceLuid.Value << "\n";

  oss << "\n\nAlias " << std::wstring(_row.Alias) << "\n";
  oss << "Description " << std::wstring(_row.Description);
  oss << "\nType " << _row.Type;

  std::wstring t = oss.str();

  return std::string(t.begin(), t.end());
}