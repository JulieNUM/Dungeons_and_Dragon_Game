#if false
#include "testBuilder.hpp"
#include <sstream>

/*
 g++ -std=c++11 -arch x86_64 -I/usr/local/opt/cppunit/include -L/usr/local/opt/cppunit/lib -o test  character.cpp testBuilder.cpp -lcppunit -Wno-c++17-extensions

*/
void testBuilder::setUp() {
}

void testBuilder::tearDown() {
}

void testBuilder::testBullyBuilder() {
    BullyBuilder builder;
    string playerName="John";
    builder.buildName(playerName);
    Character* character = builder.getResult();
    CPPUNIT_ASSERT_EQUAL(playerName, character->getName());
}


void testBuilder::testNimbleBuilder(){
    NimbleBuilder builder;
    string playerName="John";
    builder.buildName(playerName);
    Character* character = builder.getResult();
    CPPUNIT_ASSERT_EQUAL(playerName, character->getName());
}

void testBuilder::testTankBuilder(){
    TankBuilder builder;
    string playerName="John";
    builder.buildName(playerName);
    Character* character = builder.getResult();
    CPPUNIT_ASSERT_EQUAL(playerName, character->getName());
}

int main(int argc, char *argv[]) {
    CPPUNIT_NS::TestResult testResult;
    CPPUNIT_NS::TestResultCollector resultCollector;
    testResult.addListener(&resultCollector);

    CPPUNIT_NS::TestRunner testRunner;
    testRunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    testRunner.run(testResult);
    CPPUNIT_NS::TextOutputter textOutputter(&resultCollector, std::cout);
    textOutputter.write();
    return 0;
}
#endif