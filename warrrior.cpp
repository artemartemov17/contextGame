#include "warrrior.h"
#include <iostream>

using namespace std;

Warrior::Warrior()
{
    cout << "конструктор война по умолчанию" << endl;
    name = "воин";
    health = 35;
    damage = 10;
}

Warrior::Warrior(string name, unsigned int health, float damage)
{
    cout << "кастомный конструктор война" << endl;
    this->name = name;
    this->health = health;
    this->damage = damage;
}

void Warrior::GetWeapons()
{
    cout << name << " вз€л в руки " << weapons[lvl - 1];
}

void Warrior::GetInfo()
{
    Npc::GetInfo();
    cout << "—ила - " << strenght << endl;
    cout << "ƒоступное оружие - ";
    for (int i = 0; i < lvl; i++)
    {
        cout << weapons[i] << endl;
    }
}

void Warrior::Create()
{
    cout << "¬ы создали война" << endl;
    cout << "¬ведите им€ персонажа\t";
    cin >> name;
    GetInfo();
    GetWeapons();
}

Warrior::~Warrior()
{
    cout << name << " пал смертью храбрых" << endl;
}
