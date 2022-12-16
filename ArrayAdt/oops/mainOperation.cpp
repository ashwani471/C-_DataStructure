#include<iostream>
using namespace std;
// #include"fraction.cpp"
#include"student.cpp"

int main(){
    // Fraction f1(10,2);
    // Fraction f2(15,4);

    // f1.add(f2);
    //  cout<<endl;
    // f1.print();
    // cout<<endl;
    // f2.print();
    //      cout<<endl;
    // // cout<<"hi";
    // f1.miltiplication(f2);
    // f1.print();

    // Complex c1(3,4);
    // Complex c2(5,1);

    // c1.add(c2);

    // c1.printComplex();
    // cout<<endl;
    // c2.printComplex();
    // c1.multiple(c2);
    // cout<<endl;
    // c1.printComplex();
     char name[]="Ashwani";
        student s1(24,name);
        s1.display();
        name[3]='v';
        student s2(24,name);
        
        s2.display();


}