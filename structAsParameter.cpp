#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int bredth;
};

void fun(struct Rectangle &r){
    r.length = 15;
    r.bredth = 10;
}

int main(){

    struct Rectangle r;
    r.length = 10;
    r.bredth = 5;
    fun(r);
    // cout<<r<<endl;
    cout<<r.bredth<<endl;
    cout<<r.length<<endl;
}