#include<iostream>
using namespace std;
#include"cstring"

class student{
    int age;
    char *name;
    public:
      int const rollNo;
      
      //initialization list 
      student(int r) : rollNo(r){

      }

      student(int age , char *name){
        this->age = age;
        //shallowCopy
        // this->name = name;
        // deep copy
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
      }

      student(student const &s){
        //shallowcopy
        // this->name = s.name;
        this->age=s.age;

        //deepCopy
        this->name = new char[strlen(s.name)+1];
        strcpy(this->name,s.name);
      }

      

      void display(){
        cout<<this->age<<" "<<this->name;
      }
};
