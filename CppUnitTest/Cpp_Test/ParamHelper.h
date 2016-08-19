#pragma once
#include "boost/program_options.hpp"
//namespace std
//{
  //class map;
//}

namespace CppUnit
{
  class Test;
}



class ParamHelper
{
public:
  ParamHelper(int argc, char* argv[]);
  ~ParamHelper(void);

   boost::program_options::variables_map& GetParams();
   boost::program_options::options_description& GetDesc();
  //void log();
private:
  boost::program_options::variables_map vm;
  boost::program_options::options_description desc;
  //void dump(CppUnit::Test *test, std::string tree = "");
};

