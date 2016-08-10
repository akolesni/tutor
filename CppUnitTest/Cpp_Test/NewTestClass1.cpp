#include "stdafx.h"
#include "NewTestClass1.h"


// Register the test suite that belongs to the given test class into the test 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION (NewTestClass1);
// ################################################################################################
void NewTestClass1::TestName_01()
{
  CPPUNIT_ASSERT(10==10);
}
// ################################################################################################
void NewTestClass1::TestName_02()
{
  CPPUNIT_ASSERT(10==10);
}
// ################################################################################################
//void NewTestClass1::setUp()
//{
//}
//
//void NewTestClass1::tearDown()
//{
//}