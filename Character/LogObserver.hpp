//Log Observer
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

//observer interface
class LogObserver{
    public:
    virtual void update(const std::string& event) = 0;
};


class GameLogObserver: public LogObserver{
    public:
        void update(const std::string& event) override{
            std::cout << "Game Log: "<< event << std::endl;
        }
};

class CharacterLogObserver: public LogObserver{
    public:
    void update(const std::string& event) override{
        std::cout << "Character Log: "<< event << std::endl;
    }
};

