#include "character.h"
#include "timer.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <thread>

using namespace std;

namespace {

const auto HERO_HEALTH = 40;
const auto ORC_HEALTH = 7;
const auto DRAGON_HEALTH = 20;

Timer timerOrc, timerDragon;

void printInstructions ()
{
    cout << "type attack <space> orc/dragon and enter, to attack orc or dragon respectively. Ex: attack orc\n";
    cout << "alternatively you can type \"a\" instead of \"attack\" Ex: a orc\n";
    cout << "type quit and enter, to quit the game\n\n";
}
} // namespace

// Orc and Dragon will attack hero in a regular interval
// this function will be running in a separate thread
// without blocking the console update
void attackOnHero(Character* orc, Character* dragon, Character* hero) {
    timerOrc.start();
    timerDragon.start();

    while (true)
    {
        if (orc->health() > 0 && timerOrc.elapsedSeconds() > 1.3)
        {
            orc->attack(hero);
            timerOrc.reset();
        }

        if (dragon->health() > 0 && timerDragon.elapsedSeconds() > 2.6)
        {
            dragon->attack(hero);
            timerDragon.reset();
        }

        // while the Orc and Dragon attack the hero, hero would been head
        // so check whether he is already dead, after each attack
        if (hero->health() <= 0)
        {
            cout << "*********Hero has lost the game*********" << endl;
            timerOrc.stop();
            timerDragon.stop();
            break;
        }
    }
}

int main()
{
    cout << "The hero has to fight the orc and dragon\n";
    cout << "With his 40 health points against Orcs 7 and Dragons 20, hero stands tall in the fight\n";
    cout << "You can help him reach the glory by helping him win his battle against Orc and Dragon\n\n";

    printInstructions();

    Character* hero =  new Character{"Hero", HERO_HEALTH};
    Character* orc =  new Character{"Orc", ORC_HEALTH};
    Character* dragon = new Character{"Dragon", DRAGON_HEALTH};

    thread enemyThread(attackOnHero, orc, dragon, hero);

    string name;
    while (true)
    {
        getline (cin, name);
        stringstream ss(name);
        vector<std::string> results(std::istream_iterator<std::string>{ss},
                                         std::istream_iterator<std::string>());


        if (results[0] == "quit")
            break;
        else if (results[0] == "attack" || results[0] == "a")
        {
            if (results[1] == "orc")
                hero->attack(orc);
            else if (results[1] == "dragon")
                hero->attack(dragon);
            else
                cout << results[1] << "! there is no such character to attack" << endl;
        }
        else
        {
            cout << "input has no action assigned, please try again" << endl;
            printInstructions();
        }

        // while the hero attacks Orc and Dragon, keep track of both of their health
        // if both of them are dead means hero has won
        if (orc->health() <= 0 && dragon->health() <= 0)
        {
            cout << "*********Hero won the game*********" << endl;
            break;
        }
    }

    delete orc;
    delete dragon;
    delete hero;
    return 0;
}
