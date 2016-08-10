#include "stdafx.h"
#include "NewTestClass3.h"


// Register the test suite that belongs to the given test class into the test 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION (NewTestClass3);
// ################################################################################################
void NewTestClass3::TestName_01()
{
  CPPUNIT_ASSERT(10==10);
}
// ################################################################################################
void NewTestClass3::TestName_02()
{
  CPPUNIT_ASSERT(10==10);
}
// ################################################################################################
//void NewTestClass3::setUp()
//{
//}
//
//void NewTestClass3::tearDown()
//{
//}