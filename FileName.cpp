#include <iostream>
#include "windows.h"
//���������� ��� ������ � ������ ���������� � �����
#include <fstream> 
using namespace std;

//������������ �������:
// private - ���������, ��������� ������ � ��������� � �������
//           �� ��������� ������ ������
// protected - ����������, ����� ���������� �������� � ������
//        � ������ ����������, �� ��� ��� ������ ������������
//        � �������� ������ ���������
// public - ���������, �������������, ����� ������������ �����

//������� ����� - ����������� (����� � �������� ��� ������ �����������)
class Npc
{
protected: //����������� 0 ���������� (���� ������ ������ ������ �������� � ����������)
    //�� ��� ��� �� ���� ������ � �������� ������ ���������
    string name{ "��������" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };
public: //��������� ����������� ������ (������������ ����� ����� � ����� �����)
    virtual void GetInfo() //����� ������
    {
        cout << "��� - " << name << endl;
        cout << "�������� - " << health << endl;
        cout << "���� - " << damage << endl;
    }
    virtual void Create() {};
    void Save() {
        ofstream saveSystem("save.txt");
        if (!saveSystem.is_open())
        {
            cout << "������ ����������\n���������� �����\n";
        }
        else
        {
            saveSystem.write(reinterpret_cast<const char*>(&(name)), sizeof(name));

            saveSystem.write(reinterpret_cast<const char*>(&(lenght)), sizeof(lenght));
            saveSystem.write(reinterpret_cast<const char*>(&(health)), sizeof(health));
            saveSystem.write(reinterpret_cast<const char*>(&(damage)), sizeof(damage));
            saveSystem.write(reinterpret_cast<const char*>(&(>lvl)), sizeof(lvl));
        }
    };
    void  Load() {
        ifstream loadSystem("save.txt", ios::binary);
        Npc npc; //��������� �������� ��� ���������� �� �����
        if (!loadSystem.is_open())
        {
            cout << "����� � �������� ��������\n������ � ����� ������� ������������ ����������\n";
            return npc;
        }
        else
        {
            loadSystem.read(reinterpret_cast<char*>(&(npc.name)), sizeof(npc.name));
            loadSystem.read(reinterpret_cast<char*>(&(npc.health)), sizeof(npc.health));
            loadSystem.read(reinterpret_cast<char*>(&(npc.damage)), sizeof(npc.damage));
            loadSystem.read(reinterpret_cast<char*>(&(npc.lvl)), sizeof(npc.lvl));
            return npc;
        }
    }
};

//������������ - ������������� ��������� �������
// � ������� ������ ��������� (parent), ������� �����������(child)
class Warrior : public virtual Npc //������������ � ������������� ������� public
{
protected:  //����������� 0 (��������� - ����������, ������ � �����, ������ ������ ������)
    unsigned short strenght{ 31 };
    string weapons[4] = { "������", "�������", "������", "���" };
public:
    //����������� - �����, ������� ���������� � ������ �������� ����������
    //������ (������� ������� � �������� ������ ��������� �� �����)

    Warrior() //����������� �� ���������, ����� ��� ����������
    {
        name = "����";
        health = 35;
        damage = 10;
    }
    //��������� �����������
    Warrior(string name, unsigned int health, float damage)
    {
        cout << "��������� ����������� �����" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }

    void GetWeapons()
    {
        cout << name << " ���� � ���� " << weapons[lvl - 1];
    }
    void GetInfo() override  //����������� (���������� ��� ������)
    {
        Npc::GetInfo();
        cout << "���� - " << strenght << endl;
        cout << "��������� ������ - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << weapons[i] << endl;
        }
    }
    void Create() override
    {
        cout << "�� ������� �����" << endl;
        cout << "������� ��� ���������\t";
        cin >> name;
        GetInfo();
        GetWeapons();
    }
    //���������� ����������
    //���������� ��������� ��������� (==)
    bool operator == (const Warrior& warrior) const
    {
        return ((warrior.damage == this->damage) && (warrior.health == this->health)
            && (warrior.strenght == this->strenght));
    }


    //���������� - �����, ������� ���������� ������������� ��� ������������� ������
    //��� ��������� ������ � ����������� ������ (������ ������� �������)
    ~Warrior() //���������� ������ ��� ����������
    {
        cout << name << " ��� ������� �������" << endl;
    }
};
        


        //virtual - ������� ������������� �������, �������
        //��� ���� ��� ����� �������� �� ���������
        class Wizard : public virtual Npc
        {
        protected:
            unsigned short intellect = 27;
            string spell[4] = { "�������", "����������� ������", "�������� ���", "����������� �����" };
        public:
            Wizard()
            {
                name = "���������";
                health = 23;
                damage = 15;
            }
            Wizard(string name, unsigned int health, float damage)
            {
                cout << "��������� ����������� ����������" << endl;
                this->name = name;
                this->health = health;
                this->damage = damage;
            }
            void GetInfo() override  //����������� (���������� ��� ������)
            {
                Npc::GetInfo();
                cout << "��������� - " << intellect << endl;
                cout << "��������� ���������� � ����� ���������� - ";
                for (int i = 0; i < lvl; i++)
                {
                    cout << spell[i] << endl;
                }
            }
            void CastSpell()
            {
                cout << name << " ��������� " << spell[lvl - 1] << endl;
            }
            void Create() override
            {
                cout << "�� ������� ����������" << endl;
                cout << "������� ��� ���������\t";
                cin >> name;
                GetInfo();
                CastSpell();
            }
            //���������� ��������� ������������
            Wizard operator + (const Wizard& wizard) const
            {
                return Wizard(
                    this->name,
                    (this->health + wizard.health),
                    (this->damage + wizard.damage)
                );
            }

            ~Wizard() //���������� ������ ��� ����������
            {
                cout << name << " �������� ���" << endl;
            }
        };

        //������������� ������������
        class Paladin : public Warrior, public Wizard
            //��������� ���������������� ����� ����������� ����� �������
        {
        public:
            Paladin()
            {
                name = "�������";
                health = 25;
                damage = 12;
                strenght = 27;
            }
            void GetInfo() override
            {
                Warrior::GetInfo();
                cout << "��������� - " << intellect << endl;
                cout << "��������� ���������� � ����� ���������� - ";
                for (int i = 0; i < lvl; i++)
                {
                    cout << spell[i] << endl;
                }
            }
            void Create() override
            {
                cout << "�� ������� ��������" << endl;
                cout << "������� ��� ���������\t";
                cin >> name;
                GetInfo();
                CastSpell();
                GetWeapons();
            }
        };

        class Player
        {
        public:
            void Create(Npc* player)
            {
                player->Create();
            }
            void Save(Npc* player)
            {
                player->save();
            }
            Npc Load(Npc* player)
            {
                player->load();
            }
        };

        int main()
        {
            setlocale(LC_ALL, "Rus");
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);

            Warrior* warrior = new Warrior();
            Warrior* warrior2 = new Warrior();

            cout << (*warrior == *warrior2) << endl;

            Wizard* wizard1 = new Wizard();
            Wizard* wizard2 = new Wizard();
            Wizard* megaWizard = new Wizard();
            *megaWizard = *wizard1 + *wizard2;
            megaWizard->GetInfo();

            *megaWizard = *wizard1 + *wizard2;
            megaWizard->GetInfo();


            Paladin* paladin = new Paladin();
            Player* player = new Player();

            cout << "������, ������\n������� � ������ � �������� � ����\n";
            cout << "�� ������� ���? (1 - ����� ��������, 2 - ���������)\n";
            unsigned short choise = 1;
            //������� ���������� ������� ��� �������� ������� ������
            cin >> choise;
            while (choise > 2 || choise < 1)
            {
                cout << "�������� �� ������, ������� �����\n";
                cin >> choise;
            }
            if (choise == 1)
            {
                cout << "�������� � ����� �������\n\t1 - ����\n\t2 - ���������\n\t3 - �������)";
                //-----------
                // ��� ��� ����� ������� ���� �������� �������
                cin >> choise;
                while (choise > 3 || choise < 1)
                {
                    cout << "������ ��� �� ���� � ����� �����\n�� ��� �� �� ���������\n";
                    cin >> choise;
                }
                //____________

                /*switch (choise)
                {
                case 1: {
                  player->Create(&warrior);
                  delete wizard;
                  delete paladin;
                  break; }
                case 2: {
                  player->Create(&wizard);
                  delete warrior;
                  delete paladin;
                  break; }
                case 3: {
                  player->Create(&paladin);
                  delete warrior;
                  delete wizard;
                  break; }
                }*/
            }
            else
            {
                ifstream loadSystem("save.txt", ios::binary);
                if (!loadSystem.is_open())
                {
                    cout << "����� � �������� ��������\n������ � ����� ������� ������������ ����������\n";
                }
                else
                {
                    loadSystem.read(reinterpret_cast<char*>(&(paladin->name)), sizeof(paladin->name));
                    loadSystem.read(reinterpret_cast<char*>(&(paladin->health)), sizeof(paladin->health));
                    loadSystem.read(reinterpret_cast<char*>(&(paladin->damage)), sizeof(paladin->damage));
                    loadSystem.read(reinterpret_cast<char*>(&(paladin->lvl)), sizeof(paladin->lvl));
                    paladin->GetInfo();
                }
            }
            else
            {
                player->load(warrior);
                
            }
            cout << "������� ��������� ���?\n\t1 - ��������� ����\n\t2 - ����������\n";
            cin >> choise;
            while (choise > 2 || choise < 1)
            {
                cout << "����� ����� ������������ � ��������\n������� ���� �����\n";
                cin >> choise;
            }
            if (choise == 1)
            {
                player
            }

            

            return 0;
        }
