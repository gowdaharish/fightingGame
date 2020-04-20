#include "character.h"

Character::Character(const string name, const int health) : _name{name}, _health{health}
{
}

void Character::setHealth(const int health)
{
    if (health == _health)
        return;

    // nothing to update if the character is already dead
    // this can happen in the repeated attack
    if (_health < 0)
        return;

    _health = health;
}

bool Character::attack(Character &character)
{
    // this shouldn't happen but lets take the precaution
    if (character.name().empty())
    {
        cout << "can not attack a null character" << endl;
    }

    // a character cant attack himself
    if (this->name() == character.name())
    {
        cout << "a character can not attack itself" << endl;
        return false;
    }

    switch (getCharacter(character.name()))
    {
    case 0:
    {
        // before the new attack can takes place, old attack would have killed the character
        if (this->health() <= 0)
            return false;

        if (this->name() == "Orc")
            character.setHealth(character.health() - 1);
        else
            character.setHealth(character.health() - 3);

        updateHealthMessage(*this, character);
        return true;
    }

    case 1:
    case 2:
    {
        if (this->health() <= 0)
        {
            cout << "hero is dead, quit and restart the game" << endl;
            return false;
        }

        // Orc and Dragons would only be attacked by Hero
        if (this->name() != "Hero")
        {
            cout << "only a hero can attack Orc or Dragon" << endl;
            return  false;
        }

        character.setHealth(character.health() - 2);
        updateHealthMessage(*this, character);
        return true;
    }

    case 3:
    {
        cout << "unknown target specified for attacking" << endl;
        return false;
    }

    }

    return false;
}

int Character::getCharacter(const string name)
{
    if (name == "Hero")
        return  Chars::Hero;
    if (name == "Orc")
        return Chars::Orc;
    if (name == "Dragon")
        return  Chars::Dragon;

    return Chars::Unknown;
}

void Character::updateHealthMessage(const Character& giver, const Character& receiver)
{
    // if the character is dead don't show the health status, instead just display that the character is dead
    if (receiver.health() <= 0)
    {
        cout << receiver.name() << " is dead" << endl;
        return;
    }

    cout << giver.name() << " hits " << receiver.name() << ". " << receiver.name() << " health is: " << receiver.health() << endl;
}
