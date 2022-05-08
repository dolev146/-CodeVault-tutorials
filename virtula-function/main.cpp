// https://www.youtube.com/watch?time_continue=2&v=DudHooleNVg&feature=emb_title
// g++ -o main main.cpp ; ./main

#include <iostream>

using namespace std;

class Enemy
{

public:
    virtual void attack()
    {
    }

    // protected:
    //     int attackPower;

    // public:
    //     void setAttackPower(int a)
    //     {
    //         attackPower - a;
    //     }
};

class Ninja : public Enemy
{
public:
    void attack()
    {
        cout << "Ninja is attacking" << endl;
    }
    // void attack()
    // {
    //     cout << "I am a ninja I will chop you! - " << attackPower << endl;
    // }
};

class Monster : public Enemy
{
public:
    void attack()
    {
        cout << "Monster is attacking" << endl;
    }
    // void attack()
    // {
    //     cout << "I am a monster I will eat you! - " << attackPower << endl;
    // }
};

int main()
{
    Ninja n;
    Monster m;
    Enemy *enemy1 = &n;
    Enemy *enemy2 = &m;
    enemy1->attack();
    enemy2->attack();

    // Ninja n;
    // Monster m;
    // Enemy *enemy1 = &n;
    // Enemy *enemy2 = &m;
    // enemy1->setAttackPower(4);
    // enemy2->setAttackPower(26);
    // n.attack();
    // m.attack();

    return 0;
}
