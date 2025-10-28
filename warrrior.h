#pragma once
#ifndef WARRIOR_H
#define WARRIOR_H
#include "npc.h"
#include <iostream>
using namespace std;

//наследование - использование доступных свойств
// и методов класса родител€м (parent), классом наследником(child)
class Warrior : virtual public Npc //наследование с модификатором public (неизменное)
{
protected:  //модификатор доступа (приватный - защищенный, доступ к пол€м, только внутри класса)
    unsigned short strenght{ 31 };
    string weapons[4] = { "кастет", "дубинка", "клинок", "меч" };
public:
    //конструктор - метод, который вызываетс€ в момент создани€ экземпл€ра
    //класса (вручную вызвать в основном потоке программы не можем)

    //конструктор по умолчанию, когда нет аргументов
    Warrior();
    //кастомный конструктор
    Warrior(string name, unsigned int health, float damage);

    void GetWeapons();
    void GetInfo() override; //полиморфизм (перегрузка дл€ метода)
    void Create() override;
    //деструктор - метод, который вызываетс€ автоматически при высвобождении пам€ти
    //при окончании работы с экземпл€ром класса (нельз€ вызвать вручную)

    //перегрука операоров
    //перегрузка оператора сравнени€(==)
    bool operator == (const Warrior& warrior) const
    {
        return ((warrior.damage == this->damage)
            && (warrior.health == this->health)
            && (warrior.strenght == this->strenght));
    };
    
    //деструктор всегда без аргументов
    ~Warrior();
};

#endif // !WARRIOR_H