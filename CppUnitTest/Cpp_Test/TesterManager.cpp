#include "StdAfx.h"
#include "TesterManager.h"
#include "ParamHelper.h"
#include <iostream>
#include "cppunit/TestCase.h"

#include "cppunit/extensions/TestFactoryRegistry.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestResultCollector.h"
#include "cppunit/TestRunner.h"
#include "cppunit/BriefTestProgressListener.h"
#include "cppunit/XmlOutputter.h"

namespace po=boost::program_options;

TesterManager::TesterManager(void)
{
  this->rootTest = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
}


TesterManager::~TesterManager(void)
{
}



int TesterManager::Start(int argc, char* argv[])
{
  try
  {
    ParamHelper paramHelper(argc, argv);

    po::variables_map vm = paramHelper.GetParams();

    if (vm.count("help"))
    {
      std::cout << paramHelper.GetDesc() << '\n';
    }
    else if (vm.count("ls"))
    {
      dump(rootTest);
    }
    else if (vm.count("t"))
    {
      std::vector<std::string> v = vm["t"].as<std::vector<std::string>>();
      ValidateInputList(v);

      CppUnit::TestRunner runner;

      std::for_each(
        v.begin(),
        v.end(),
        [&](std::string testName)
      {
        runner.addTest(find(rootTest, testName));
      });
      CPPUNIT_NS::BriefTestProgressListener Progress;
      CPPUNIT_NS::TestResult testResult;
      testResult.addListener(&Progress);
      runner.run(testResult);
    }

    std::string strDllPath = vm["path"].as<std::string>();
    std::cout << "dll path :" << strDllPath << '\n';
  }
  catch(std::string& exception)
  {
    std::cout << "Exception :" << exception << std::endl;
  }
  catch(...)
  {
        std::cout << "exception\n";
  }
  return 0;
}


///
void TesterManager::dump(CppUnit::Test *test, std::string tree)
{
  if (0 == test) return;

  std::cout << tree << test->getName() << std::endl;
  tree.append("\t");
  if (0 == test->getChildTestCount()) return;

  for (int i = 0; i < test->getChildTestCount(); i++)
  {
    dump(test->getChildTestAt(i), tree);
  }
}

CppUnit::Test*TesterManager::find(CppUnit::Test *test, const std::string &name)
{
  if (0 == test) return nullptr;

  if (name == test->getName()) return test;

  if (0 == test->getChildTestCount()) return nullptr;

  for (int i = 0; i < test->getChildTestCount(); i++)
  {
    CppUnit::Test* found = find(test->getChildTestAt(i), name);

    if (found) return found;
  }

  return nullptr;
}

void TesterManager::ValidateInputList(std::vector<std::string> _inputList)
{
  bool result = false;
  std::for_each(
    _inputList.begin(),
    _inputList.end(),
    [&](std::string param)
    {
      if(find(rootTest, param)==nullptr)
      {
        std::string error = "Test '" + param + "' not faund"; 
        throw  error;
      }
    }
    );
}