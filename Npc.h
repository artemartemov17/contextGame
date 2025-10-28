#pragma once
#ifndef NPC_H
#define NPC_H
#include <iostream>

using namespace std;
//базовый класс (абстрактный - хотя бы 1 метод будет виртуальным)
class Npc
{
protected: //модификатор доступа защищенный (дает доступ внутри класса родителя и наследника)
    //но все еще не дает доступ в основном потоке программы
    string name{ "персонаж" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };

public: //публичный модификатор доступ (использовать метод можно в любом месте)

    Npc();

    virtual void GetInfo(); //ключевое слово virtual 

    virtual void Create(); //ключевое слово virtual 

    ~Npc();
};
#endif // !NPC_H