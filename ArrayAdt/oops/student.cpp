#include<iostream>
using namespace std;
#include"cstring"

class student{
    int age;
    char *name;

    public:
      student(int age , char *name){
        this->age = age;
        //shallowCopy
        // this->name = name;
        // deep copy
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
      }

      void display(){
        cout<<this->age<<" "<<this->name;
      }
};
