#include<iostream>
using namespace std;

int main(){
    // int a = 10;
    // cout<<"a:"<<a<<endl;
    // int *p;
    // cout<<"*p:"<<*p<<endl;
    // p=&a;
    // cout<<"p:"<<p<<endl;
    // cout<<"*p:"<<*p<<endl;
    // cout<<"&a:"<<&a<<endl;
    // cout<<"*(p+1):"<<*(p++)<<endl;

     int *p = new int[5];
    //  cout<<'*p:'<<*p<<endl;
     cout<<"p:"<<p<<endl;
     p[0] = 1;
     p[1] = 2; p[2] = 3;

    //  cout<<"p[0]"<<p[0]<<endl;
    //  cout<<"p[1]"<<p[1]<<endl;

    for(int i=0 ; i<5 ; i++){
        cout<<p[i]<<endl;
    }

    cout<<sizeof(p);
}