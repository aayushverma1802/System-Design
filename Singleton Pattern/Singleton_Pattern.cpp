// What is the Singleton Pattern?
// The Singleton pattern ensures that a class has only one object (instance) in the entire program — and it gives you a global point to access it.

#include <iostream>
using namespace std;
class Singleton
{
private:
    static Singleton *instance; // Static instance pointer
    Singleton()
    {
        cout << "Singleton Created\n";
    }

public:
    // Static functions belong to the class itself, not to any object.
    // So you call them using the class name, like Singleton::getInstance().
    // You do not need an object to call static functions.
    // Trying to call a static function through an object pointer or reference that doesn’t exist yet (s->getInstance()) is invalid and unsafe.
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }
    void showMessage()
    {
        cout << "I am the only instance\n";
    }
};
// Initialize the static instance
Singleton *Singleton::instance = nullptr;
int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();
    s1->showMessage();
    s2->showMessage();

    cout << "Are both instances same? " << (s1 == s2 ? "Yes" : "No") << "\n";

    return 0;
}