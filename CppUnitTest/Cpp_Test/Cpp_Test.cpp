#include "stdafx.h"

//#include <cassert>
//#include "cppunit/TestCase.h"
//#include "cppunit/extensions/TestFactoryRegistry.h"
//#include "cppunit/TestResult.h"
//#include "cppunit/TestResultCollector.h"
//#include "cppunit/TestRunner.h"
//#include "cppunit/BriefTestProgressListener.h"
//#include "cppunit/XmlOutputter.h"
//#include "PduTestBase.h"
//#include "boost/program_options.hpp"
//#include "ParamHelper.h"

#define OUTPUT_RESULT_FILE "UnitTestApiResult.xml"
#include "TesterManager.h"

//namespace po=boost::program_options;

int main(int argc, char* argv[])
{
  TesterManager tester_manager;
  return tester_manager.Start(argc, argv);


   












  // ##############################################################################################
    // Get the top level suite from the registry



    //CPPUNIT_NS::Test*                       suite  = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();


    //assert(suite->getChildTestCount() == 3);
    //assert(suite->countTestCases() == 6);
    //assert(suite->getName()== "All Tests");

    //CPPUNIT_NS::Test* t1 = suite->getChildTestAt(0);
    //CPPUNIT_NS::Test* t2 = suite->getChildTestAt(1);
    //CPPUNIT_NS::Test* t3 = suite->getChildTestAt(2);

    //assert(t1->getChildTestCount()== 2);
    //assert(t1->countTestCases()== 2);

    //CPPUNIT_NS::Test* t11 = t1->getChildTestAt(0);


    //std::string s = t11->getName();



    //int i = t11->getChildTestCount();

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


  //  CppUnit::TestRunner                     Runner;
  //  // Informs test-listener about testresults
  //  CPPUNIT_NS::TestResult                  TestResult;
  //  // register listener for collecting the test-results
  //  CPPUNIT_NS::TestResultCollector         CollectedResults;
  //  // register listener for per-test progress output
  //  CPPUNIT_NS::BriefTestProgressListener   Progress;
  //  //CLogger                                 logger;
  //  bool                                    bSuccess = false;

  //  // register listener that collects the test results
  //  TestResult.addListener(&CollectedResults);
  //  // register listener that collects the result of each single test
  //  TestResult.addListener(&Progress);
  //  // add Test-Suite to test runner
  //  //Runner.addTest(suite);
  //  Runner.addTest(t11);
  //  //Runner.addTest(t2);


  //  Runner.run(TestResult);

  //  // Output results as XML
  //  std::ofstream XmlFileOut(OUTPUT_RESULT_FILE);
  //  CPPUNIT_NS::XmlOutputter XmlOut(&CollectedResults, XmlFileOut);
  //  XmlOut.setStyleSheet("report.xsl");
  //  XmlOut.write();

		//system("pause");
  //return 0;
}

