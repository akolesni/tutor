// BoostTest.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
//#include "BoostChrono.h"
//#include "BoostDateTime.h"
//#include "BoostFilesystem.h"
//#include "BoostTimer.h"
#include "BoostLog.h"
#include "BoostStringTest.h"
#include <system_error>

int _tmain(int argc, _TCHAR* argv[])
{
  //BoostChrono boost_chrono;
  //boost_chrono.Do();
  //BoostDateTime boost_date_time;
  //boost_date_time.Do();
  //BoostFilesystem boost_filesystem;
  //boost_filesystem.Do();
  //BoostTimer boost_timer;
  //boost_timer.Do();
  //BoostLog boost_log;
  //boost_log.Do();
	BoostStringTest boost_string_test;
	boost_string_test.Do();

	system("pause");
	return 0;
}

