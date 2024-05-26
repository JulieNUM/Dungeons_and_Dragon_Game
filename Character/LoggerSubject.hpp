#pragma once

#include <vector>
#include "LoggerObserver.hpp"
#include "LoggerFile.hpp"

class LoggerSubject {
public:
    // void setLogger(LoggerObserver* logger){
    //     logobservers.push_back(logger);
    // }
    // void notifyLoggerObserver(const std::string& message){
    //     for(LoggerObserver* logobserver : logobservers){
    //         logobserver->update(message);
    //     }
    // }

    virtual void registerLogger(LoggerObserver* logger) = 0;
    virtual void notifyLoggerObserver(const std::string& message) = 0;



private:
    std::vector<LoggerFile*> logobservers;
};
