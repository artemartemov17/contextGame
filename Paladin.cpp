#include "Paladin.h"

Paladin::Paladin()
{
    damage = 15;
    health = 25;
    intellect = 20;
    strenght = 20;
}

void Paladin::GetInfo()
{
    Warrior::GetInfo();
    cout << "Интеллект - " << intellect << endl;
    cout << "Доступные заклинания в книге заклинаний - ";
    for (int i = 0; i < lvl; i++)
    {
        cout << spell[i] << endl;
    }
}

void Paladin::Create()
{
    cout << "Вы создали паладина" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();
    GetWeapons();
    CastSpell();
}

Paladin::~Paladin()
{
    cout << name << " отправился к праотцам " << endl;
}