#pragma once
#ifndef PALADIN_H
#define PALADIN_H
#include "warrrior.h"
#include "Wizard.h"
#include <iostream>

using namespace std;

//2 уникальных свойства и 2 метода для класса паладин. Обязательно продублировать их в архитектуру (draw.io)
class Paladin : public Warrior, public Wizard //множественное наследование
    //классы родители перечисляются через 
{
public:
    Paladin();
    void GetInfo() override;
    void Create() override;
    ~Paladin();
};

#endif // !PALADIN_H