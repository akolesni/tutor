#pragma once

namespace CppUnit
{
  class Test;
}

class ParamHelper
{
public:
  ParamHelper(int argc, char* argv[]);
  ~ParamHelper(void);
  //void log();
private:
  void dump(CppUnit::Test *test, std::string tree = "");
};

