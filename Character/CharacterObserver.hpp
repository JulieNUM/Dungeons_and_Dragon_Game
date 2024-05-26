#pragma once

class Character;

class CharacterObserver{
    public:
        virtual ~CharacterObserver(){}
        virtual void updateView() = 0; // 如果在Subject中调用了不带参数的updateView方法，则需要在这里定义一个不带参数的updateView方法
        virtual  void updateView(Character* character)=0;
};