#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "LogObserver.hpp"

using namespace std;

class LogSubject{
    public:
        virtual void attach(LogObserver* observer) = 0;
        virtual void detach(LogObserver* observer) = 0;
        virtual void notify(const string& event) = 0;
};