#pragma once
#ifndef WORLDEVIL_H
#define WORLDEVIL_H
#include <iostream>

using namespace std; 

class worldevil {
protected: //модификатор доступа защищенный (дает доступ внутри класса родителя и наследника)
    //но все еще не дает доступ в основном потоке программы
    string name{ "персонаж" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };
    bool isAlive{ true };
public:

    // Конструктор 
    worldevil(string n, int h, float d, unsigned short l, bool isA);
    // делегрование  
    worldevil();
    worldevil(string n);
    worldevil(string n, int h);

    // НАПИСАТЬ Метод info

    ~worldevil();


};


#endif // !WORLDEVIL_H