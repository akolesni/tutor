#include "StdAfx.h"
#include <iostream>

#include "ParamHelper.h"

#include "cppunit/TestCase.h"
#include "cppunit/extensions/TestFactoryRegistry.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestResultCollector.h"
#include "cppunit/TestRunner.h"
#include "cppunit/BriefTestProgressListener.h"
#include "cppunit/XmlOutputter.h"


namespace po=boost::program_options;

ParamHelper::ParamHelper(int argc, char* argv[])
{
 try
  {
    po::options_description desc;
    desc.add_options()
      ("help,h", "Help screen")
      ("path", po::value<std::string>()->default_value("PDUAPI_I+ME_ACTIA_XS.dll") , "PDU API dll path")
      ("vci",  po::value<std::string>()->default_value("Xentry Connect") , "VCI type")
      ("t",  po::value<std::string>()->default_value("Xentry Connect") , "Test")
      ("ls", "List all available tests.");


    po::variables_map vm;

    store(parse_command_line(argc, argv, desc), vm);
    //notify(vm);
    if (vm.count("help"))
    {
      std::cout << desc << '\n';
      //return 0;
    }
    else if(vm.count("ls"))
    {
        CppUnit::Test *all = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
        
        dump(all);
    }

    std::string strDllPath = vm["path"].as<std::string>();
    std::cout << "dll path :" << strDllPath << '\n';

    //pLibraryManager->LoadPDULibrary(strDllPath);
    //PduTestBase::InitFunctor(pLibraryManager.get());
    //PduTestBase::SimpleCheck();
  }
  catch (std::string& _strExeption)
  {
    std::cout << _strExeption;
    //return 1;
  }
  catch (...)
  {
    std::cout << "Error";
    //return 2;
  }
}


ParamHelper::~ParamHelper(void)
{
}

boost::program_options::variables_map& ParamHelper::getParams()
{
  return this->vm;
}

//
//void ParamHelper::log()
//{
//  std::cout << "log";
//}

