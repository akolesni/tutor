#pragma once
#include <cppunit/extensions/HelperMacros.h>

class NewTestClass3 : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE(NewTestClass3);

  CPPUNIT_TEST(TestName_01);
  CPPUNIT_TEST(TestName_02);

  CPPUNIT_TEST_SUITE_END();

public:

  void TestName_01();
  void TestName_02();

  // TestFixture
  //virtual void setUp() override;
  //virtual void tearDown() override;
};
