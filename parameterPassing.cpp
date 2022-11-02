#include<iostream>
using namespace std;

// call by Address
// void swap(int *x, int *y){
//    int temp;
//    temp = *x;
//    *x = *y;
//    *y = temp;
// }


// call by reference

void swap(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y=temp;
}

int main(){
    int a = 10,b = 20;
    swap(a,b);
    cout<<"a:"<<a<<" "<<"b:"<<b<<endl;
}


