#pragma once
#include <string>

namespace CppUnit
{
  class Test;
}

class TesterManager
{
public:
  TesterManager(void);
  ~TesterManager(void);
  int Start(int _argc, char* _argv[]);
private:
  void TesterManager::dump(CppUnit::Test* _test, std::string _tree);
};

