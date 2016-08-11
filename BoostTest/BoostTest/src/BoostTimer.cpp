#include "BoostTimer.h"
#include <iostream>
#include <boost/timer/timer.hpp>

/**
 *@brief - Constructor
 */
BoostTimer::BoostTimer()
{
}

/**
 *@brief - Destructor
 */
BoostTimer::~BoostTimer()
{
}

void BoostTimer::Do()
{
  //boost::timer::cpu_timer timer;
  //
  //timer.start();
  ////timer.stop();

  //boost::timer::cpu_times cpuTimes = timer.elapsed();

  //boost::timer::nanosecond_type nnt = cpuTimes.wall;


  //timer.format();
  //timer.is_stopped();
  //timer.resume();

  //  char *testLeak = new char[1000000];
  //testLeak = nullptr;

  {
    boost::timer::cpu_timer timer;
    boost::timer::cpu_times cpuTimes0 = timer.elapsed();
    for (int i = 0; i < 1000000; ++i)
      std::pow(1.234, i);
    boost::timer::cpu_times cpuTimes1 = timer.elapsed();

    for (int i = 0; i < 1000000; ++i)
      std::pow(1.234, i);
    boost::timer::cpu_times cpuTimes2 = timer.elapsed();

    std::cout << "t0 " << cpuTimes0.wall <<" t1 " << cpuTimes1.wall << " t2" << cpuTimes2.wall << std::endl;

    std::cout << timer.format() << '\n';
  }
  //{
  //  boost::timer::cpu_timer timer;

  //  for (int i = 0; i < 1000000; ++i)
  //    std::pow(1.234, i);
  //  std::cout << timer.format() << '\n';

  //  timer.stop();

  //  for (int i = 0; i < 1000000; ++i)
  //    std::pow(1.234, i);
  //  std::cout << timer.format() << '\n';

  //  timer.resume();

  //  for (int i = 0; i < 1000000; ++i)
  //    std::pow(1.234, i);
  //  std::cout << timer.format() << '\n';
  //}
}
