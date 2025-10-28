#include "Wizard.h"

Wizard::Wizard()
{
    cout << "конструктор волшебника по умолчанию" << endl;
    name = "волшебник";
    health = 23;
    damage = 15;
}

Wizard::Wizard(string name, unsigned int health, float damage)
{
    cout << "кастомный конструктор волшебника" << endl;
    this->name = name;
    this->health = health;
    this->damage = damage;
}

void Wizard::GetInfo()
{
    Npc::GetInfo();
    cout << "Интеллект - " << intellect << endl;
    cout << "Доступные заклинания в книге заклинаний - ";
    for (int i = 0; i < lvl; i++)
    {
        cout << spell[i] << endl;
    }
}

void Wizard::CastSpell()
{
    cout << name << " применяет " << spell[lvl - 1] << endl;
}

void Wizard::Create()
{
    cout << "Вы создали волшебника" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();
    CastSpell();
}

Wizard::~Wizard()
{
    cout << name << " испустил дух" << endl;
}

