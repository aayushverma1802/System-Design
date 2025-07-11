#include <iostream>
using namespace std;

// Step 1: Base Class
class Burger
{
public:
    virtual string getDescription()
    {
        return "Plain Burger";
    }
    virtual int getCost()
    {
        return 50;
    }
};

// Step 2: Decorator Base class(optinal)

class BurgerDecorator : public Burger
{
protected:
    Burger *burger;

public:
    BurgerDecorator(Burger *b)
    {
        burger = b;
    }
};
// Step 3: Cheese Decorator
class Cheese : public BurgerDecorator
{
public:
    Cheese(Burger *b) : BurgerDecorator(b) {}
    string getDescription() override
    {
        return burger->getDescription() + " + Cheese";
    }
    int getCost() override
    {
        return burger->getCost() + 20;
    }
};
// Step 4: Egg Decorator
class Egg : public BurgerDecorator
{
public:
    Egg(Burger *b) : BurgerDecorator(b) {}

    string getDescription() override
    {
        return burger->getDescription() + " + Egg";
    }

    int getCost() override
    {
        return burger->getCost() + 30;
    }
};

// Step 5:- Client Cpde
int main()
{
    Burger *myBurger = new Burger(); // Plain Burger
    myBurger = new Cheese(myBurger); // Add cheese
    myBurger = new Egg(myBurger);    // Add egg

    cout << myBurger->getDescription() << endl;
    cout << "Total: $" << myBurger->getCost() << endl;
    delete myBurger;
    return 0;
}