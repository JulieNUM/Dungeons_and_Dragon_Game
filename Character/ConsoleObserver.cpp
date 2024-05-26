#include "CharacterObserver.hpp"
#include "Character.hpp"
#include <iostream>
using namespace std;

class ConsoleObserver: public CharacterObserver{
    public:
        void updateView(Character* character) override {
            cout<<"Character "<<character->getName()<<" has been updated."<<endl;
        }
            // Implementing the overloaded method with no parameters
        void updateView() override {
            std::cout << "Character has been updated." << std::endl;
        }
};