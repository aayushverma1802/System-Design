// The Prototype Pattern is used to create a duplicate (clone) of an existing object.
// Instead of creating a new object from scratch, you copy an existing object 
// especially useful when object creation is costly or complex.

#include<iostream>
#include<string>
using namespace std;
//Step 1:- Prototype Interface
class Shape{
    public:
    virtual Shape* clone()=0;//Pure virtual
    virtual void draw()=0;
    virtual ~Shape(){}

};

//Step 2:- Concrete Class 
class Circle: public Shape{
    private:
    int radius;
    public:
    Circle(int r){
        radius=r;

    }
    Circle(const Circle& other){ //copy constructor
        radius=other.radius;

    }
    Shape* clone() override{
        return new Circle(*this); //Clone via copy constructor
    }
    void draw()override{
        cout<<"Drawing Circle with radius "<<radius<<endl;
    }
};

//Step 3:- Client
int main(){
Circle original(10);
Shape* copy=original.clone();

original.draw();//Original
copy->draw(); //Cloned
delete copy;
return 0;

}

