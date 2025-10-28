#include "npc.h"
#include <iostream>


Npc::Npc()//конструктор не private
{
    std::cout << "Вы создали Npc" << endl;
}

void Npc::GetInfo() //метод класса
{
    std::cout << "Имя - " << name << endl;
    std::cout << "Здоровье - " << health << endl;
    std::cout << "Урон - " << damage << endl;
}

void Npc::Create() 
{

} 

Npc::~Npc() //деструктор не private
{
    std::cout << "Npc удален" << endl;
}