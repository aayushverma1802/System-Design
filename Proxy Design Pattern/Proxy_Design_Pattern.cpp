// A Proxy is a class that controls access to another class.
// It acts as a substitute or placeholder for the real object.

#include<iostream>
#include<string>
using namespace std;

//Subject Interface
class Image{
    public:
    virtual void display()=0;
};

//Real Object
class RealImage:public Image{
    private:
    string filename;
    void loadFromDisk(){
        cout<<"Loading "<<filename<<" from disk..."<<endl;

    }
    public:
    RealImage(string fname):filename(fname){
        loadFromDisk(); //costly operation
    }
    void display()override{
        cout<<"Displaying "<<filename<<endl;
    }
};

// Proxy Object
class ProxyImage:public Image{
    private:
    RealImage* realImage;
    string filename;
    public:
    ProxyImage(string fname):filename(fname),realImage(nullptr){}
    
    void display() override{
        if(realImage==nullptr){
            realImage=new RealImage(filename);//Lazy load
        }
        realImage->display();
    }
    ~ProxyImage(){
        delete realImage;
    }

};

//Client
int main(){
    Image* img=new ProxyImage("big_photo.png");
    cout<<"\nImage will be displayed when needed\n";
    img->display();//Loads only now

    cout<<"\nDisplaying again:\n";
    img->display();//No reloading
    delete img;
    return 0;
}
