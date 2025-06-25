#include <iostream>
using namespace std;

class TwoPinSocket
{
public:
    void powerOn()
    {
        cout << "Power from two-pin socket\n";
    }
};

class USBCharger
{
public:
    void charge()
    {
        cout << "Charging with the USB power\n";
    }
};

class PlugAdapter
{
    TwoPinSocket *socket; // The incompatible class (Adaptee)

public:
    // Constructor: takes the existing incompatible object
    PlugAdapter(TwoPinSocket *s) : socket(s) {}
    //     PlugAdapter(TwoPinSocket* s) {
    //     socket = s;  // This also works
    // }
    void charge()
    {
        socket->powerOn(); // Use two-pin power for USB charger
        cout << "Adapter converts power for USB\n";
    }
};

int main()
{
    // Step 1: Create the original incompatible object
    TwoPinSocket socket;
    // Step 2: Create the Adapter and give it the socket
    PlugAdapter adapter(&socket);
    // Step 3: Call the USB-style function (charge), which internally uses the socket
    USBCharger charger;
    adapter.charge();
    return 0;
}
