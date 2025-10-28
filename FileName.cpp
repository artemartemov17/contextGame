#include <windows.h>
#include <iostream>
#include "Header.h"
#include <cmath>
#include "npc.h"
#include "warrrior.h"
#include "Wizard.h"
#include "Paladin.h"
#include "worldevil.h"
//#include "nililay.h"


//модификаторы доступа:
//private - приватный, можно использовать только внутри самого класса
//protected - защищенный, внутри класса основного и классов наследников
//public - общедоступный, можно использовать везде, в том числе в основном потоке программы

using namespace std;

class Player
{
    public:
        void Create(Npc* player)
        {
            player->Create();
        }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Warrior* warrior = new Warrior();
    Warrior* warrior2 = new Warrior();

    cout << "\nравны ли войны?(1-да,0-нет)\n" << (*warrior == *warrior2) << endl << endl;

    Wizard* wizard = new Wizard();
    Wizard* wizard1 = new Wizard();
    Wizard* wizard2 = new Wizard();
    Wizard* megaWizard = new Wizard();
    *megaWizard = *wizard1 + *wizard2;
    cout << "\n\n***Мегавизард***\n";
    megaWizard->GetInfo();
    cout << "***Мегавизард***\n\n";
    
    /*
    Paladin* paladin = new Paladin();
    *paladin = *wizard + *warrior;
    cout << "\n\n***Paladin***\n";
    paladin->GetInfo();
    cout << "***Paladin***\n\n";*/

    Player* player = new Player();

    cout << "привет, путник\nприсядь у костра и расскажи о себе\n";
    cout << "Ты в первые тут?(1 - новый персонаж, 2 - загрузить)\n";
    unsigned short choise = 1;
    //создать уникальную функцию для проверки условия выбора
    cin >> choise;
    while (choise > 2 || choise < 1)
    {
        cout << "Наверное, ты ошибся, повтори снова\n";
        cin >> choise;
    }

    if (choise == 1)
    {
        cout << "расскажи о себе\n\t1 - Воин\n\t2 - Волшебник\n\t3 - Паладин";
        //______________________________
        //вызвать ту самую функцию для проверки условия выбора
        cin >> choise;
        while (choise > 3 || choise < 1)
        {
            cout << "Наверное, ты ошибся, повтори снова\n";
            cin >> choise;
        }

        //__________________________
        /*switch (choise)
        {
        case 1: {
        player.Create(&warrior); 
        delete wizard;
        delete paladin;
        }
        case 2: { 
        player.Create(&wizard);
        delete warrior;
        delete paladin;
        }
        case 3: { 
        player.Create(&paladin); 
        delete warrior;
        delete wizard;
        }
        }*/

    }


    //Paladin* player3 = new Paladin();
    //player3->Create();
    //delete player3;

    //cout << "Функция из другого файла " << sum(5, 6) << endl;
    //Nililay* Abcd = new Nililay("Bvz");
    //Abcd->HI();
    //delete Abcd;




    return 0;
}