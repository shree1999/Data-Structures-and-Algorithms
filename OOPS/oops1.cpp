#include<iostream>
//#include "hero.cpp"
using namespace std;

class Hero{
    //Properties

    private: // we can use this globally..
        //char name[100];
        int health;


    // In case of private we access this in the class only..
    public:
        char level;
        
    Hero(){
        cout << "Constructor called" <<endl;
    }

    // Parameterized Constructor
    Hero(int health)
    {
        //cout<<"This -> "<<&health<<endl;
        this->health = health;
    }
    Hero(int health,char level)
    {
        this->level = level;
        this->health = health;
    }
    void print()
    {
        cout<<"Health is : "<<this->health<<endl;
        cout<<"Level is : "<<this->level<<endl;
    }
    
    int getHealth(){
        return health;
    }
    char getLevel(){
        return level;
    }
    void setHealth(int h){
        health = h;
    }
    void setLevel(char ch){
        level =ch;
    }
};

int main()
{

    Hero suresh(70,'C');
    suresh.print();

    // Copy Constructor
    Hero R(suresh);
    R.print();

    /*
    // Object created Statically
    cout << "Hi"<<endl;
    Hero sutam(10);
    cout<<"Hello"<<endl;

    cout<<"Address of Sutam : "<< &sutam <<endl;

    sutam.print();

    //Dynamically
    Hero *h = new Hero(11);
    h->print();

    Hero temp(22,'B');
    h->print();*/

    //Creation of Object
    /*Hero h1;
    h1.level = 'A';
    cout << "size : "<<sizeof(h1)<<endl;

    h1.setHealth(70); 
    
    cout<<"Level is : "<< h1.level<<endl; //As Private
    cout<<"Health is : "<< h1.getHealth()<<endl;*/

/*
    //Static Allocation
    Hero a;

    a.setHealth(70);
    a.setLevel('A');

    cout<<"Level is : "<<a.level<<endl;
    cout<<"Health is : "<<a.getHealth()<<endl;

    // Dynamic Allocation
    Hero *b = new Hero; // Memory allocation in Heap

    b->setHealth(80);
    b->setLevel('B');

    cout<<"Level is : "<<(*b).level<<endl;
    cout<<"Health is : "<<(*b).getHealth()<<endl;
    // OR
    cout<<"Level is : "<<b->level<<endl;
    cout<<"Health is : "<<b->getHealth()<<endl;

*/

    return 0;
}