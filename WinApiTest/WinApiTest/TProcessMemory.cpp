#include "stdafx.h"
#include "TProcessMemory.h"

#include <Windows.h>
#include <Psapi.h> // GetProcessMemoryInfo

#include <iostream>

class Mem
{
  int a1;
  int a2;
  int a3;
  int a4;
  int a5;
  int a6;
  int a7;
  int a8;
  int a9;
  int a10;
  int a11;
  int a12;
  int a13;
  int a14;
  int a15;
  int a16;
  int a17;
  int a18;
  int a19;
  int a20;
  int a21;
  int a22;
  int a23;
  int a24;
  int a25;
};

TProcessMemory::TProcessMemory()
{
}


TProcessMemory::~TProcessMemory()
{
}

void TProcessMemory::Do()
{
  this->test1();
}

void TProcessMemory::test1()
{
  HANDLE processHandle = GetCurrentProcess();
  DWORD processID = -1;

  if (GetLastError() == false)
  {
    processID = GetProcessId(processHandle);

    HANDLE processHandle = OpenProcess(PROCESS_ALL_ACCESS | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

    PROCESS_MEMORY_COUNTERS pmc;

    GetProcessMemoryInfo(processHandle, &pmc, sizeof(pmc));
    int start = pmc.WorkingSetSize;
    size_t dif = 0;

    for (size_t a = 0; a < 100000; a++)
    {
      start += 100;
      BOOL result = GetProcessMemoryInfo(processHandle, &pmc, sizeof(pmc));
      std::cout << ", memory usage " << pmc.WorkingSetSize << " + 100 " << start << " dif " << (pmc.WorkingSetSize - dif) << " B\n";
      Mem* m = new Mem;
      dif = pmc.WorkingSetSize;
      delete m;
    }

    std::cout << "Mem size = " << sizeof(Mem) << std::endl;
    //Mem* m = new Mem;
    //result = GetProcessMemoryInfo(processHandle, &pmc, sizeof(pmc));
    //std::cout << ", memory usage " << pmc.WorkingSetSize / 1024 << " kB\n";
  }
  else
  {

  }
}
