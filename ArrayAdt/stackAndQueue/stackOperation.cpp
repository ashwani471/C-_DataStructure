#include<iostream>
using namespace std;
// #include "stackClassusingArray.cpp"
#include "stackusingLL.cpp"

int main(){
    int n;
    cout<<"Enter size:";
    cin>>n;
    stackLL<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.getSize()<<endl;
    cout<<s.isEmpty()<<endl;

}