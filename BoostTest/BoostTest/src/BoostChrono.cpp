#include "BoostChrono.h"
#include <iostream>
#include <boost/chrono.hpp>

/**
 *@brief - Constructor
 */
BoostChrono::BoostChrono()
{
}

/**
 *@brief - Destructor
 */
BoostChrono::~BoostChrono()
{
}

void BoostChrono::Do()
{
  std::cout << boost::chrono::system_clock::now() << '\n'; //gibt die Systemzeit an. Das ist die Uhrzeit, wie sie auf einem Computer angezeigt wird
#ifdef BOOST_CHRONO_HAS_CLOCK_STEADY
  std::cout << boost::chrono::steady_clock::now() << '\n'; // handelt es sich um eine Uhr, die garantiert, dass sie bei einem Zugriff zu einem späteren Zeitpunkt auch eine spätere Uhrzeit zurückgibt.
  // vom letztmaligen Bootvorgang gemessen
#endif
  std::cout << boost::chrono::high_resolution_clock::now() << '\n';

#ifdef BOOST_CHRONO_HAS_PROCESS_CLOCKS
  std::cout << boost::chrono::process_real_cpu_clock::now() << '\n';
  std::cout << boost::chrono::process_user_cpu_clock::now() << '\n';
  std::cout << boost::chrono::process_system_cpu_clock::now() << '\n';
  std::cout << boost::chrono::process_cpu_clock::now() << '\n';
#endif

#ifdef BOOST_CHRONO_HAS_THREAD_CLOCK
  std::cout << boost::chrono::thread_clock::now() << '\n';
#endif
}
