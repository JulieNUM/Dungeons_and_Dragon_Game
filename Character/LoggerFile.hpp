
#pragma once
#include <fstream>
#include <ctime>
#include <iostream>
#include <vector>
#include <memory>
#include "LoggerObserver.hpp"

using namespace std;

class LoggerFile: public LoggerObserver{
    public:
    LoggerFile(const string& fileName): filename(fileName){}

    void update(const string& message) override{
          std::ofstream logFile(filename, std::ios::app);
        if (logFile.is_open()) {
            // Get current time
            std::time_t currentTime = std::time(nullptr);
            // Convert current time to string
            std::string timeString = std::ctime(&currentTime);
            // Remove newline character from timeString
            timeString.erase(timeString.find_last_not_of("\n") + 1);

            // Write timestamp and message to the log file
            logFile << "[" << timeString << "] " << message << std::endl;
            logFile.close();
        } else {
            std::cerr << "Error: Unable to open log file for writing." << std::endl;
        }
    }   


    private:
        string filename;

};

