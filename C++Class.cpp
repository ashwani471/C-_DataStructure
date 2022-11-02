#include<iostream>
using namespace std;

class Rectangle{
private:
   int length;
   int bredth;

public:
    Rectangle(int l,int b){
        length = l;
        bredth = b;
    }   

    int area(){
        return length * bredth;
    }

    void changeLength(int l){
         length = l;
    }
};

int main(){
    Rectangle r={10,5};

    r.area();

    r.changeLength(20);

    cout<<r.area();
}