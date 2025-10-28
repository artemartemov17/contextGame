#pragma once
#ifndef WIZARD_H
#define WIZARD_H
#include "Npc.h"
#include <iostream>

using namespace std;


class Wizard : virtual public Npc
{
protected:
    unsigned short intellect = 27;
    string spell[4] = { "вспышка", "магисческая стрела", "огненный шар", "метеоритный дождь" };
public:
    Wizard();
    Wizard(string name, unsigned int health, float damage);

    //полиморфизм (перегрузка для метода)
    void GetInfo() override;
    void CastSpell();
    void Create() override;

    //перегрузка оператора суммирования
    Wizard operator + (const Wizard& wizard) const
    {
        return Wizard(this -> name, 
            (this->health + wizard.health),
            (this->damage + wizard.damage)
        );
    };

    /*Paladin operator + (const Warrior& warior) const
    {
        return Paladin();
    };*/


    //деструктор всегда без аргументов
    ~Wizard();
};


#endif // !WIZARD_H