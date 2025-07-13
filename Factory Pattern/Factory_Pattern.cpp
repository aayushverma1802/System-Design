// The most used and loved design patterns in all of LLD:

// Factory Pattern lets you create objects based on some condition or input, without needing to know the exact
//  class at the time of writing the code.

#include <iostream>
using namespace std;

// Step 1:Product interface
class Shape
{
public:
    virtual void draw() = 0;
};
// Step 2: Concrete Products
class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing Circle\n";
    }
};
class Sqaure : public Shape
{
public:
    void draw() override
    {
        cout << "Drawing Square\n";
    }
};

class Triangle : public Shape
{
public:
    void draw() override
    {
        cout << "🔺 Drawing Triangle\n";
    }
};
// Step 3: Factory
class ShapeFactory
{
public:
    static Shape *createShape(string type)
    {
        if (type == "circle")

            return new Circle();
        else if (type == "square")
            return new Sqaure();
        else if (type == "triangle")
            return new Triangle();
        else
            return nullptr;
    }
};
// Step 4: Client Code
int main()
{
    Shape *shape1 = ShapeFactory::createShape("circle");
    Shape *shape2 = ShapeFactory::createShape("square");
    if (shape1)
        shape1->draw();
    if (shape2)
        shape2->draw();
    delete shape1;
    delete shape2;
    return 0;
}