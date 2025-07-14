// The Visitor Pattern is a behavioral design pattern that lets you 
//add new operations to a group of existing classes without changing their code.


// Instead of modifying the classes, you create a separate “visitor” class that 
//performs the operation.

#include<iostream>
using namespace std;
//Forward Declare
class Dog;
class Cat;
//Step1 :- Visitor Interface
class AnimalTrainer{
    public:
    virtual void train(Dog* d)=0;
    virtual void train(Cat* c)=0;

};
//Step2:- Base Animal Class
class Animal{
    public:
    virtual void accept(AnimalTrainer* trainer)=0;

};
//Step3 :- Concrete animals
class Dog:public Animal{
    public:
    void accept(AnimalTrainer * trainer) override{
        trainer->train(this);//Dog lets trainer visit
    }
    void bark(){
        cout<<"Woof !!\n";
    }
};
class Cat:public Animal{
    public:
    void accept(AnimalTrainer * trainer) override{
        trainer->train(this);//cat lets trainer visit
    }
    void meow(){
        cout<<"Meow !!\n";
    }
};
//Step 4:- Concrete Visitor (Trainer)
class SimpleTrainer:public AnimalTrainer{
    public:
    void train(Dog* d)override{
        cout<<"Trainer teaches Dog to sit\n";
        d->bark();
    }
    void train(Cat* c)override{
        cout<<"Trainer teaches Cat to sit\n";
        c->meow();
    }

};
// STEP 5: Client
int main() {
    Dog dog;
    Cat cat;

    SimpleTrainer trainer;

    dog.accept(&trainer);  // Trainer visits Dog
    cat.accept(&trainer);  // Trainer visits Cat

    return 0;
}