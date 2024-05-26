#include "Subject.hpp"
#include <iostream>
#include <algorithm>
using namespace std;

void Subject::addObserver(CharacterObserver* observer) {
    observers.push_back(observer);
}

void Subject::removeObserver(CharacterObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notifyObserver() {
    for (CharacterObserver* observer : observers) {
        observer->updateView();
    }
}

void Subject::notifyObserver(Character* character){
    for(CharacterObserver* observer: observers){
        observer->updateView(character);
    }
}