#include<iostream>
#include<cstring>
using namespace std;

int lengthString(char str[]){
    int i;
    for( i=0 ; str[i]!='\0';i++){
        
    }
    return i;
}

bool isPalindrome(char str[]){
     int len = lengthString(str);
    //  cout<<"length:" << len <<endl;
     int i=0;
     int j=len-1;
     while(i<j){
        if(str[i]==str[j]){
            i++;
            j--;
        }else{
            false;
        }
     }
     return true;
}

void replaceCharacter(char str[],char a,char b){
    int i;
    for(i=0;str[i]!='\0';i++){
        if(str[i] == a){
            str[i]=b;
        }
    }
    cout<<str;
}

void reverseString(char str[]){
    int len = lengthString(str);
    int i=0;
    int j=len-1;
    while(i<j){
      char temp = str[i];
      str[i]=str[j];
      str[j]=temp;
      i++;
      j--;
    }
}

void ReverseWordwise(char str[]){
    int len = lengthString(str);
    int i ,j= len-1;
    cout<<str[i];
    while(i>=0){
        if(str[i] != ' '){
           i--;
        }else{
            int k=i+1;
            while(k<j){
                int temp = str[k];
                str[k]=str[j];
                str[j]=temp;
                k++;
                j--;
            }
            i--;
            j=i;
        }
    }
}

int main(){
 char str[100];
 cout<<"Enter a string:";
 cin.getline(str,100);
//   char a;
//  cout<<"Enter A charcter A:";
//  cin>>a;
//  char b;
//  cout<<"Enter a character B:";
//  cin>>b;

//  cout<<lengthString(str);
// cout<<isPalindrome(str);
//  replaceCharacter(str,a,b);
// reverseString(str);
ReverseWordwise(str);
cout<<str;

}