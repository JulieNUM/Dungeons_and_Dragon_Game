#if false
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>  
#include <cppunit/TextOutputter.h>      

#include "BullyBuilder.hpp"
#include "NimbleBuilder.hpp"
#include "TankBuilder.hpp"
#include "Character.hpp"
using namespace CppUnit;
using namespace std;


class testBuilder : public CPPUNIT_NS::TestFixture{
    CPPUNIT_TEST_SUITE(testBuilder);
    CPPUNIT_TEST(testBullyBuilder);
    CPPUNIT_TEST(testNimbleBuilder);
    CPPUNIT_TEST(testTankBuilder);
    CPPUNIT_TEST_SUITE_END();


public:
    void setUp();
    void tearDown();

    void testBullyBuilder();
    void testNimbleBuilder();
    void testTankBuilder();


private:


};

CPPUNIT_TEST_SUITE_REGISTRATION(testBuilder);

#endif