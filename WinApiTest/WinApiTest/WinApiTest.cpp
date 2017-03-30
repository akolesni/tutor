// WinApiTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include "TProcessMemory.h"
#include "TestNetApi.h"


int main()
{
  TProcessMemory pm;
  pm.Do();
  //TestNetApi test_net_api;
  //test_net_api.Do();

  system("pause");
  return 0;
}

