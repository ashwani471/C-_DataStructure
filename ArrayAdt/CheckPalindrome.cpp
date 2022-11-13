#include<iostream>
using namespace std;

bool checkPalindrome(char str[]){
int len=0;
for(int i=0;str[i]!='\0';i++){
    len++;
}
int i=0;
int j=len-1;
for(;i<j;i++,j--){
    if(str[i]!=str[j]){
return false;
    }

}
return true;
}

int main(){
    int n;
    cin>>n;
    char str[n];
    cin>>str;
    cout<<checkPalindrome(str);
}