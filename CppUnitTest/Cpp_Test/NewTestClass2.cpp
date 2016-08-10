#include "stdafx.h"
#include "NewTestClass2.h"


// Register the test suite that belongs to the given test class into the test 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION (NewTestClass2);
// ################################################################################################
void NewTestClass2::TestName_01()
{
  CPPUNIT_ASSERT(10==10);
}
// ################################################################################################
void NewTestClass2::TestName_02()
{
  CPPUNIT_ASSERT(10==10);
}
// ################################################################################################
//void NewTestClass2::setUp()
//{
//}
//
//void NewTestClass2::tearDown()
//{
//}