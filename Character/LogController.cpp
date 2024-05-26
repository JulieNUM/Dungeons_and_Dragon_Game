#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "LogSubject.hpp"

using namespace std;

class LogController: public LogSubject{
    private:
        vector<LogObserver*> observers;

    public:
        void attach(LogObserver* observer){
            observers.push_back(observer);
        }

        void detach(LogObserver* observer){
            observers.erase(find(observers.begin(), observers.end(), observer));
        }

        void notify(const string& event){
            for(auto observer: observers){
                observer->update(event); 
            }
        }


        void gameSetup() {
        notify("Game setup phase started");
        }

        void switchTurn() {
            notify("Switched turns");
        }

};