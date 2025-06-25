#include <iostream>
using namespace std;
class Base
{
public:
    virtual void func()
    {
        cout << "This is the base class\n";
    }
};
class Derived : public Base
{
public:
    void func() override
    {
        cout << "This is the Derived class\n";
    }
};
int main()
{
    Base *ptr;
    Derived obj;
    ptr = &obj;
    ptr->func();
}