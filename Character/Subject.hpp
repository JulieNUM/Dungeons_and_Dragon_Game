#pragma once
#include <vector>
#include "CharacterObserver.hpp"

class Subject {
public:
    virtual ~Subject() {}
    void addObserver(CharacterObserver* observer);
    void removeObserver(CharacterObserver* observer);
    void notifyObserver();

protected:
    void notifyObserver(Character* character);

private:
    std::vector<CharacterObserver*> observers;
};
