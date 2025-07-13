// The Strategy Pattern lets you select one of many algorithms (strategies) at runtime, 
// without changing the code that uses them.
#include<iostream>
using namespace std;
//Strategy interface
class FightStrategy{
    public:
    virtual void fight()=0;

};
//Concrete Strategies
class Knife:public FightStrategy{
    public:
    void fight() override{
        cout<<"Fighting with a knife !\n";
    }
};
class Gun:public FightStrategy{
    public:
    void fight() override{
        cout<<"Fighting with a Gun !\n";
    }
};
class Bow:public FightStrategy{
    public:
    void fight() override{
        cout<<"Fighting with a bow and an arrow !\n";
    }
};
//Context: The character using the strategies
class Character{
    FightStrategy* strategy;
    public:
    void setStrategy(FightStrategy* s){
        strategy=s;
    }
    void attack(){
        if(strategy){
            strategy->fight();
        }
        else{
            cout<<"No weapon selected\n";
        }
    }
};
int main(){
    Character hero;
    Knife knife;
    Gun gun;
    Bow bow;
    hero.setStrategy(&knife);
    hero.attack();
    hero.setStrategy(&gun);
    hero.attack();
    hero.setStrategy(&bow);
    hero.attack();
    return 0;

    return 0;
}