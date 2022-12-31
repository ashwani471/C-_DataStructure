#include<iostream>
#include<cstring>
using namespace std;
// #include "stackClassusingArray.cpp"
#include "stackusingLL.h"

bool checkBalanced(char str[]){
  int len = strlen(str);
  cout<<len;
  stackLL<char> s;
  for(int i=0 ; i<len ;i++){
    if(str[i]=="{" || str[i]=="(" || str[i]== "["){
        s.push(str[i]);
    }
    else if(str[i]=="}"){
        if(s.top() == "{"){
            s.pop();
        }
    }else if(str[i]==')'){
        if(s.top()=="("){
            s.pop();
        }
    }else if(str[i]=="]"){
        if(s.top()=="["){
            s.pop();
        }
    }
  }
  if(s.isEmpty()){
    return true;
  }else{
    return false;
  }
}

int main(){
    // int n;
    // cout<<"Enter size:";
    // cin>>n;

    string str;
    cin>>str;

    int len = strlen(str);
    
    checkBalanced(str);

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