
#ifndef _1_cppunit_cpp_
#define _1_cppunit_cpp_

/*
 * Copyright (c) 2008, Robert Emerson
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Robert Emerson nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ROBERT EMERSON ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBERT EMERSON BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "stdafx.h"

#include <unistd.h>

#include <iostream>
#include <exception>
#include <memory>
#include <string>
#include <map>

#include <cppunit/CompilerOutputter.h>
#include <cppunit/TextOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TextTestProgressListener.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/TestSuccessListener.h>
#include <cppunit/Portability.h>

using namespace CPPUNIT_NS;

using std::cerr;
using std::cout;
using std::endl;
using std::exception;
using std::auto_ptr;
using std::string;
using std::map;
using std::make_pair;

static const int RET_OK = 0;
static const int RET_USAGE = -1;
static const int RET_BAD_OUTPUTTER = -2;
static const int RET_BAD_LISTENER = -3;
static const int RET_BAD_TEST = -4;

typedef map<string, Outputter *> OutputterMap;
typedef map<string, TestListener *> ListenerMap;

void usage(const char *image, 
           const char *defaultTest,
           const OutputterMap &outputters,
           const ListenerMap &listeners)
{
  cout << endl;
  cout << "Usage: " << basename(image) 
       << " (-o outputter) (-p progress) (-t test) (-r count)" << endl;
  cout << "       " << basename(image) 
       << " [ -l | -h ]" << endl;
  cout << endl;
  cout << "A CppUnit command line test execution tool. " << endl;
  cout << endl;
  cout << "Built against cppunit version: " << CPPUNIT_VERSION << endl;
  cout << endl;
  cout << "Options:" << endl;
  cout << endl;
  cout << "    -o Output style. Choices: ";
  
  {
    OutputterMap::const_iterator it = outputters.begin();
    
    while (it != outputters.end()) { 
      
      cout << it->first << " "; 
      ++it;
    }
  }

  cout << "Default: compiler";

  cout << endl;
  
  cout << "    -p Progress style. Choices: ";

  {
    ListenerMap::const_iterator it = listeners.begin();
    
    while (it != listeners.end()) { 
      
      cout << it->first << " "; 
      ++it;
    }
  }

  cout << "Default: dots";

  cout << endl;

  cout << "    -t Runs given the test only. Default: \"" << defaultTest << "\"" << endl;

  cout << "    -r Repeat count. Default: 1" << endl;

  cout << endl;

  cout << "    -l List all available tests." << endl;

  cout << "    -h Print this usage message." << endl;

  cout << endl;

  cout << "Returns 0 on success, negative for usage errors, positive errors plus failures." << endl;

  cout << endl;

  cout << "If the image name is a valid test name, then this is the default test executed." << endl;

  cout << endl;

  return;
}

// Recursive dumps the given Test heirarchy to cout
void dump(Test *test)
{
  if (0 == test) return;

  cout << test->getName() << endl;

  if (0 == test->getChildTestCount()) return;

  for (int i = 0; i < test->getChildTestCount(); i++) {
    
    dump(test->getChildTestAt(i));
  }

  return;
}

// Recursively seeks the Test matching the given name, returns 0 otherwise.
Test *find(Test *test, const string &name)
{
  if (0 == test) return 0;

  if (name == test->getName()) return test;

  if (0 == test->getChildTestCount()) return 0;

  for (int i = 0; i < test->getChildTestCount(); i++) {
    
    Test *found = find(test->getChildTestAt(i), name);

    if (found) return found;
  }

  return 0;
}

int main(int argc, char **argv)
{
  TestResult result;

  TestResultCollector collector;

  result.addListener(&collector);
  
  OutputterMap allOutputters;

  {
    allOutputters.insert(make_pair("compiler", 
                                   new CompilerOutputter(&collector, cout)));
    
    allOutputters.insert(make_pair("text", 
                                   new TextOutputter(&collector, cout)));

    allOutputters.insert(make_pair("xml", 
                                   new XmlOutputter(&collector, cout)));

    allOutputters.insert(make_pair("none", static_cast<Outputter *>(0)));
  }

  Outputter *outputter = allOutputters.find("compiler")->second;
 
  ListenerMap allListeners;

  {
    allListeners.insert(make_pair("dots", new TextTestProgressListener()));
    
    allListeners.insert(make_pair("brief", new BriefTestProgressListener()));
    
    allListeners.insert(make_pair("none", static_cast<TestListener *>(0)));
  }

  TestListener *listener = allListeners.find("dots")->second;

  char flag = 0;

  string runTest = basename(argv[0]);

  if (!find(TestFactoryRegistry::getRegistry().makeTest(), runTest)) {

      runTest = "All Tests";
  }

  int repeat = 1;

  while ((flag = getopt(argc, argv, "r:t:o:p:lh")) != -1)
  {

    switch(flag) {

    case 'r':

      repeat = atoi(optarg);
      break;

    case 'o':

      {
        OutputterMap::const_iterator it = allOutputters.find(optarg);
        
        if (it == allOutputters.end()) {
          
          cerr << "Unknown outputter: " << optarg << endl;
          return RET_BAD_OUTPUTTER;
        }
        
        outputter = it->second;
      }

      break;

    case 'p':

      {
        string progress(optarg);
        
        ListenerMap::const_iterator it = allListeners.find(optarg);
        
        if (it == allListeners.end()) {
          
          cerr << "Unknown listener: " << optarg << endl;
          return RET_BAD_LISTENER;
        }
        
        listener = it->second;
      }

      break;

    case 'l':
      {
        Test *all = TestFactoryRegistry::getRegistry().makeTest();
        
        dump(all);
        
        return RET_OK;
        
      }
      break; // not reached

    case 't':
      {
        runTest = optarg;
      }
      break;

    case 'h':
    default:

      usage(argv[0], runTest.c_str(), allOutputters, allListeners);

      return RET_USAGE;

      break; // not reached
    }

  }

  if (listener != 0) result.addListener(listener);

  Test *run = find(TestFactoryRegistry::getRegistry().makeTest(), runTest);
  
  if (run == 0) {
    
    cerr << "Unknown test case: " << runTest << endl;
    return RET_BAD_TEST;
  }
  
  TestRunner runner;
  
  runner.addTest(run);
  
  for (int i = 0; i < repeat; i++) {
    runner.run(result);
  }

  if (outputter) outputter->write();

  return collector.testErrors() + collector.testFailures();

}

#endif // _1_cppunit_cpp_



/*

#include "stdafx.h"

#include <cassert>
#include "cppunit/TestCase.h"
#include "cppunit/extensions/TestFactoryRegistry.h"
#include "cppunit/TestResult.h"
#include "cppunit/TestResultCollector.h"
#include "cppunit/TestRunner.h"
#include "cppunit/BriefTestProgressListener.h"
#include "cppunit/XmlOutputter.h"
//#include "PduTestBase.h"
//#include "boost/program_options.hpp"


#define OUTPUT_RESULT_FILE "UnitTestApiResult.xml"

//namespace po=boost::program_options;

int main(int argc, char* argv[])
{
  // ##############################################################################################
    // Get the top level suite from the registry



    CPPUNIT_NS::Test*                       suite  = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();


    assert(suite->getChildTestCount() == 3);
    assert(suite->countTestCases() == 6);
    assert(suite->getName()== "All Tests");

    CPPUNIT_NS::Test* t1 = suite->getChildTestAt(0);
    CPPUNIT_NS::Test* t2 = suite->getChildTestAt(1);
    CPPUNIT_NS::Test* t3 = suite->getChildTestAt(2);

    assert(t1->getChildTestCount()== 2);
    assert(t1->countTestCases()== 2);

    CPPUNIT_NS::Test* t11 = t1->getChildTestAt(0);


    std::string s = t11->getName();



    int i = t11->getChildTestCount();

 //   //---------------------------------------
 //std::string testPath = (argc > 1) ? std::string(argv[1]) : "";
 //* 
 //*   // Create the event manager and test controller
 //CppUnit::TestResult controller;
 //* 
 //*   // Add a listener that colllects test result
 //   CppUnit::TestResultCollector result;
 //   controller.addListener( &result );        
 //* 
 //*   // Add a listener that print dots as test run.
 //*   CppUnit::TextTestProgressListener progress;
 //*   controller.addListener( &progress );      
 //* 
 //*   // Add the top suite to the test runner
 //*   CppUnit::TestRunner runner;
 //*   runner.addTest( CppUnit::TestFactoryRegistry::getRegistry().makeTest() );   
 //*   try
 //*   {
 //*     std::cout << "Running "  <<  testPath;
 //*     runner.run( controller, testPath );
 //* 
 //*     std::cerr << std::endl;
 //* 
 //*     // Print test in a compiler compatible format.
 //*     CppUnit::CompilerOutputter outputter( &result, std::cerr );
 //*     outputter.write();                      
 //*   }
 //*   catch ( std::invalid_argument &e )  // Test path not resolved
 //*   {
 //*     std::cerr  <<  std::endl  
 //*                <<  "ERROR: "  <<  e.what()
 //*                << std::endl;
 //*     return 0;
 //*   }
 //* 
 //*   return result.wasSuccessful() ? 0 : 1;


 // -----------------------------






    //std::string s = a->getName();


    //CPPUNIT_NS::TestResult                  testResult;
    //a->run(&testResult);

    //int i = ;


    CppUnit::TestRunner                     Runner;
    // Informs test-listener about testresults
    CPPUNIT_NS::TestResult                  TestResult;
    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector         CollectedResults;
    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener   Progress;
    //CLogger                                 logger;
    bool                                    bSuccess = false;

    // register listener that collects the test results
    TestResult.addListener(&CollectedResults);
    // register listener that collects the result of each single test
    TestResult.addListener(&Progress);
    // add Test-Suite to test runner
    //Runner.addTest(suite);
    Runner.addTest(t11);
    //Runner.addTest(t2);


    Runner.run(TestResult);

    // Output results as XML
    std::ofstream XmlFileOut(OUTPUT_RESULT_FILE);
    CPPUNIT_NS::XmlOutputter XmlOut(&CollectedResults, XmlFileOut);
    XmlOut.setStyleSheet("report.xsl");
    XmlOut.write();

		system("pause");
  return 0;
}
*/
