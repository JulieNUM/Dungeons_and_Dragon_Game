#pragma once
#include <fstream>
#include <ctime>
#include <iostream>

using namespace std;

class LoggerObserver {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~LoggerObserver() {}
};