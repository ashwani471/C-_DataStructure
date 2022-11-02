#include<iostream>
using namespace std;

struct Rectangle
{
    int len ;
    int bredth;
}r1,r2;   //this is the one type to declare a variable


struct Rectangle r3;

int main(){
    struct Rectangle r4;
    r4.len = 4;
    r4.bredth =8;
    cout<<"Area of Rect r4 is:"<<r4.len*r4.bredth<<endl;
    cout<<sizeof(r4)<<endl;
}