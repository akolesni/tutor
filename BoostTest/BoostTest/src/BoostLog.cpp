#include "BoostLog.h"
#include <boost/log/common.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/utility/empty_deleter.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>

//using namespace boost::log;

/**
 *@brief - Constructor
 */
BoostLog::BoostLog()
{
}

/**
 *@brief - Destructor
 */
BoostLog::~BoostLog()
{
}

void BoostLog::Do()
{
  typedef boost::log::sinks::asynchronous_sink<boost::log::sinks::text_ostream_backend> text_sink;

  boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();

  boost::shared_ptr<std::ostream> stream(&std::clog, boost::empty_deleter());

  sink->locked_backend()->add_stream(stream);

  boost::log::core::get()->add_sink(sink);

  boost::log::sources::logger lg;

  BOOST_LOG(lg) << "note";
  sink->flush();
}
