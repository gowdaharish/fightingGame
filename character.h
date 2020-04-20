#pragma once
#include <iostream>

using namespace std;

class Character
{
public:
    Character(const string name, const int health);
    string name() const {return _name;}
    int health() const {return _health;}
    void setHealth(const int health);
    bool attack(Character* character);

    enum Chars {
        Hero,
        Orc,
        Dragon,
        Unknown
    };

private:
    int getCharacter(const string name);
    void updateHealthMessage(const Character* giver, const Character* receiver);

private:
    string _name;
    atomic<int> _health;
};

