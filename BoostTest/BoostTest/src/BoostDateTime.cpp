#include "BoostDateTime.h"

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <iostream>

BoostDateTime::BoostDateTime()
{
}

BoostDateTime::~BoostDateTime()
{
}

void BoostDateTime::Do()
{
  try
  {
    //this->DateTest();
    //this->DateExceptionTest();
    // this->DateDuration();
    //this->DatePeriode();
    this->PosixDateTime();
  }
  catch (std::out_of_range& exeption)
  {
    std::cout << exeption.what() << '\n';
  }
  catch (...)
  {
    std::cout << "Error in BoostDateTime::Do()" << '\n';
  }
}

//http://www.boost.org/doc/libs/1_58_0/doc/html/date_time/gregorian.html
void BoostDateTime::DateTest()
{
  //boost::gregorian::date d(2015, 9, 30);

  //boost::gregorian::date d = boost::gregorian::day_clock::universal_day();
  //boost::gregorian::date d =   boost::gregorian::day_clock::local_day();

  //from_string(std::string)
  //date from_undelimited_string(std::string)
  //boost::gregorian::date d = boost::gregorian::date_from_iso_string("20140131");
  boost::gregorian::date d = boost::gregorian::from_simple_string("2001-10-9"); //2001-October-09
   //boost::gregorian::date d =  boost::gregorian::from_us_string():





  std::cout << "date \t\t:" << d << '\n';
  std::cout << "year \t\t:" << d.year() << '\n';
  std::cout << "month \t\t:" << d.month() << '\n';
  std::cout << "day \t\t:" << d.day() << '\n';

  std::cout << "day_number \t:" << d.day_number() << '\n';
  std::cout << "julian_day \t:" << d.julian_day() << '\n';
  std::cout << "day_count \t:" << d.day_count() << '\n';
  std::cout << "modjulian_day \t:" << d.modjulian_day() << '\n';

  std::cout << "day_of_year \t:" << d.day_of_year() << '\n';
  std::cout << "day_of_week \t:" << d.day_of_week() << '\n';
  std::cout << "end_of_month \t:" << d.end_of_month() << '\n';
  std::cout << "week_number \t:" << d.week_number() << '\n';

  std::cout << "as_special \t:" << d.as_special() << '\n';
  std::cout << "is_infinity \t:" << d.is_infinity() << '\n';


  std::cout << "is_neg_infinity :" << d.is_neg_infinity() << '\n';
  std::cout << "is_not_a_date \t:" << d.is_not_a_date() << '\n';
  std::cout << "is_pos_infinity :" << d.is_pos_infinity() << '\n';
  //std::cout << "year_month_day \t:" << d.year_month_day() << '\n';
}

void BoostDateTime::DateExceptionTest()
{
  //boost::gregorian::bad_day_of_year
  //boost::date_time::not_a_date_time
  try
  {
    boost::gregorian::date d(2015, 19, 30);
  }
  catch (boost::gregorian::bad_month& exeption)
  {
    std::cout << exeption.what() << '\n';
  }

  try
  {
    boost::gregorian::date d(2015, 9, 31);
  }
  catch (boost::gregorian::bad_day_of_month& exeption)
  {
    std::cout << exeption.what() << '\n';
  }


  try
  {
    boost::gregorian::date d(0, 9, 30);
  }
  catch (boost::gregorian::bad_year& exeption)
  {
    std::cout << exeption.what() << '\n';
  }
  catch (std::out_of_range& exeption)
  {
    std::cout << exeption.what() << '\n';
  }
}

void BoostDateTime::DateTyp()
{
  //typedef gregorian_calendar::year_type year_type;
  //typedef gregorian_calendar::month_type month_type;
  //typedef gregorian_calendar::day_type day_type;
  //typedef gregorian_calendar::day_of_year_type day_of_year_type;
  //typedef gregorian_calendar::ymd_type ymd_type;
  //typedef gregorian_calendar::date_rep_type date_rep_type;
  //typedef gregorian_calendar::date_int_type date_int_type;

  boost::gregorian::date d(2015, 9, 30);

  boost::gregorian::date::year_type yt = d.year();
  boost::gregorian::date::month_type tm = d.month();
  boost::gregorian::date::day_of_week_type dw = d.day_of_week();
  boost::gregorian::date::day_type dt = d.day();
}

void BoostDateTime::DateDuration()
{
  boost::gregorian::date d1(1975, 6, 15);
  boost::gregorian::date d2(2015, 9, 30);

  boost::gregorian::date_duration dd = d1 - d2;

  std::cout << "days \t\t:"<< dd.days() << '\n';
  std::cout << "get_rep \t:"<< dd.get_rep() << '\n';
  std::cout << "is_negative \t:"<< dd.is_negative() << '\n';
  std::cout << "is_special \t:"<< dd.is_special() << '\n';
  std::cout << "unit \t\t:"<< dd.unit() << '\n';

  boost::gregorian::date_duration dd1(4);
  std::cout << dd1.days() << '\n';

  boost::gregorian::weeks ws(4);
  std::cout << ws.days() << '\n';

  boost::gregorian::months ms(4);
  std::cout << ms.number_of_months() << '\n';

  boost::gregorian::years ys(4);
  std::cout << ys.number_of_years() << '\n';
  // 
  {
    boost::gregorian::date d(2014, 1, 31);
    boost::gregorian::months ms(1);
    boost::gregorian::date d2 = d + ms;
    std::cout << d2 << '\n';
    boost::gregorian::date d3 = d2 - ms;
    std::cout << d3 << '\n';
  }
}

void BoostDateTime::DatePeriode()
{
  boost::gregorian::date d1(2014, 1, 1);
  boost::gregorian::date d2(2014, 2, 28);
  boost::gregorian::date_period dp(d1, d2);

  boost::gregorian::date_duration dd = dp.length();
  
  std::cout << "BoostDateTime::DatePeriode " << dd.days() << '\n';

  std::cout.setf(std::ios::boolalpha);
  std::cout << dp.contains(d1) << '\n';
  std::cout << dp.contains(d2) << '\n';
}

void BoostDateTime::PosixDateTime()
{
  {
    boost::posix_time::ptime pt(boost::gregorian::date(2014, 5, 12), boost::posix_time::time_duration(12, 0, 0));
    boost::gregorian::date d = pt.date();
    std::cout << d << '\n';
    boost::posix_time::time_duration td = pt.time_of_day();
    std::cout << td << '\n';
  }
  {
    //---------------------

    boost::posix_time::ptime pt = boost::posix_time::second_clock::universal_time();
    std::cout << pt.date() << '\n';
    std::cout << pt.time_of_day() << '\n';

    pt = boost::posix_time::from_iso_string("20140512T123159");
    std::cout << pt.date() << '\n';
    std::cout << pt.time_of_day() << '\n';
  }
  {
    boost::posix_time::microsec_clock::universal_time();

  }
}