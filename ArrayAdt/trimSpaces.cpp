#include<iostream>
// #include "string.h";
#include <cstring>
#include  <bits/stdc++.h>
using namespace std;

void trimspace(char str[],int n){
    int i=0;
    int j=0;

while(str[i]!='\0'){
    if(str[i] != ' '){
        str[i]=str[j];
          i++;
          j++;
    }else{
        i++;
    }
}
// return str;
}

int main(){
   
    char str[100];
    cin.getline(str,100);
    trimspace(str,100);
    cout<<str;
}