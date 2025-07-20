// The Composite Pattern is used when you want to treat individual objects 
// and groups of objects in the same way.

#include<iostream>
#include<vector>
using namespace std;

//Step 1:- Component Interface
class Graphic{
    public:
    virtual void draw()=0;
    virtual ~Graphic(){}
};

//Step 2:- Leaf Objects
class Circle:public Graphic{
    public:
    void draw()override{
        cout<<"Drawing Circle\n";
    }
};

class Square:public Graphic{
    public:
    void draw() override{
        cout<<"Drawing Sqaure\n";
    }
};

//Step 3:- Composite Object
class GraphicGroup:public Graphic{
    private:
    vector<Graphic*>children;
    public:
    void add(Graphic* g){
        children.push_back(g);
    }
    void draw() override{
        cout<<"Drawing Group:\n";
        for(Graphic* g:children){
            g->draw(); //Treating leaf and group the same
        }
    }
    ~GraphicGroup(){
        for(Graphic *g:children){
            delete g;
        }
    }
};

//Step 4:- Client

int main(){
    Graphic* circle = new Circle();
    Graphic* square = new Square();

    GraphicGroup* group = new GraphicGroup();
    group->add(circle);
    group->add(square);

    Graphic* bigGroup = new GraphicGroup();
    dynamic_cast<GraphicGroup*>(bigGroup)->add(group); // Nested group

    cout << "Drawing full structure:\n";
    bigGroup->draw();

    delete bigGroup;
    return 0;
}
 