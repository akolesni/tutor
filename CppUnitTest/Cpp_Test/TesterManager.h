#pragma once
#include <string>
#include <vector>

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
  CppUnit::Test* rootTest;

  void TesterManager::dump(CppUnit::Test* _test, std::string _tree = "");
  static CppUnit::Test* TesterManager::find(CppUnit::Test* test, const std::string& name);
  void ValidateInputList(std::vector<std::string> _inputList);
};
