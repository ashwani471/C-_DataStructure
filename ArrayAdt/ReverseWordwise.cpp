#include<iostream>
#include <bits/stdc++.h>

using namespace std;

void ReverseWordWise(string* str[]){
  int len = str.length();
  cout<<str[len-1]<<endl;
   cout<<str[0]<<endl;
   int i=0, j=len-1;
  for( ; i<j ;i++,j--){
    char temp = str[len-1];
    str[len-1] = str[i];
    str[i]=temp;
  }
  cout<<str;
}

int main(){
    string str[] = "Became A good Programmer need lots of practice";

    // cin.getline(str,100);
    ReverseWordWise(str);

    cout<<str;
}