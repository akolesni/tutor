#include "StdAfx.h"
#include "TesterManager.h"
#include "ParamHelper.h"
#include <iostream>

TesterManager::TesterManager(void)
{
}


TesterManager::~TesterManager(void)
{
}

int TesterManager::Start(int argc, char* argv[])
{
  ParamHelper paramHelper(argc, argv);
  return 0;
}

void TesterManager::dump(CppUnit::Test *test, std::string tree)
{
  if (0 == test) return;

  std::cout << tree << test->getName() << std::endl;
  tree.append("\t");
  if (0 == test->getChildTestCount()) return;

  for (int i = 0; i < test->getChildTestCount(); i++) {
    
    dump(test->getChildTestAt(i), tree);
  }

  return;
}