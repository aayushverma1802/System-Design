// The Builder Pattern is used to construct complex objects step by step.
// It separates the construction logic from the actual object, 
// so the same building process can create different representations.

#include<iostream>
#include<string>
using namespace std;

//Step 1:- Product
class Car{
    public:
    string engine;
    string wheels;
    string body;
    void showCar(){
        cout<<"Car with "<<engine<<", "<<wheels<<", and "<<body<<endl;
    }
};

//Step 2:- Builder Interface
class CarBuilder{
    public:
    virtual void buildEngine()=0;
    virtual void buildWheels()=0;
    virtual void buildBody()=0;
    virtual  Car* getCar()=0;

};

//Step 3:- Concrete Builder
class SportsCarBuilder:public CarBuilder{
    private:
    Car* car;
    public:
    SportsCarBuilder(){
        car=new Car();
    }
    void buildEngine() override{
        car->engine="V8 Engine";
    }
        void buildWheels() override{
        car->wheels="Alloy Wheels";
    }
        void buildBody() override{
        car->body="Sports Body";
    }
        Car* getCar() override{
            return car;
    }
};

//Step 4:- Director
class CarDirector{
    private:
    CarBuilder* builder;
    public:
    CarDirector(CarBuilder* b){
        builder=b;
    }
    Car* buildCar(){
        builder->buildEngine();
        builder->buildWheels();
        builder->buildBody();
        return builder->getCar();
    }
};

//Step 5:- Client

int main(){
    SportsCarBuilder builder;
    CarDirector director(&builder);
    Car* car=director.buildCar();
    car->showCar();
    return 0;

}