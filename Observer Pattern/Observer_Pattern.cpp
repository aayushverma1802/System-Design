// When one object (subject) changes its state,
// it notifies many other objects (observers) automatically.

#include<iostream>
#include<vector>
using namespace std;

//Observer interface 
class Observer{
    public:
    virtual void update(int value)=0;
};
//Subject Class
class Subject{
    vector<Observer*>observers;
    int state;
    public:
    void attach(Observer* obs){
        observers.push_back(obs);
    }
    void setState(int val){
        state=val;
        notifyAll();
    }
    void notifyAll(){
        for(auto obs:observers){
            obs->update(state);
        }

    }


};

//Concrete Observer 1
class ObserverA:public Observer{
    public:
    void update(int value) override{
        cout<<"ObserverA: State updated to "<<value<<endl;
    }
};
// Concrete Observer 2
class ObserverB:public Observer{
    public:
    void update(int value) override{
        cout<<"ObserverB: State updated to "<<value<<endl;
    }
};

int main(){
    Subject subject;
    ObserverA a;
    ObserverB b;
    subject.attach(&a);
    subject.attach(&b);
    subject.setState(10);  // Changes state, notifies observers
    subject.setState(20);  // Notifies again
    return 0;
}