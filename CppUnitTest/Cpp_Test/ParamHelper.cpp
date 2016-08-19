#include "StdAfx.h"
#include <iostream>
#include "ParamHelper.h"
//#include <cppunit/extensions/TestFactoryRegistry.h>


namespace po=boost::program_options;

ParamHelper::ParamHelper(int argc, char* argv[])
{
  try
  {
    this->desc.add_options()
      ("help,h", "Help screen")
      ("path", po::value<std::string>()->default_value("PDUAPI_I+ME_ACTIA_XS.dll"), "PDU API dll path")
      ("vci", po::value<std::string>()->default_value("Xentry Connect"), "VCI type")
      ("t", po::value<std::vector<std::string>>()->multitoken()->zero_tokens()->composing(), "Test")
      ("ls", "List all available tests.");

    store(parse_command_line(argc, argv, desc), this->vm);
    notify(vm);
  }
  catch (std::string& _strExeption)
  {
    std::cout << _strExeption;
  }
  catch (...)
  {
    std::cout << "Error";
  }
}


ParamHelper::~ParamHelper(void)
{
}

po::variables_map& ParamHelper::GetParams()
{
  return this->vm;
}

po::options_description& ParamHelper::GetDesc()
{
  return this->desc;
}
