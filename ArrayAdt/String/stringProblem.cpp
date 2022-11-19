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
    int i =len-1;
    int j= len-1;
    cout<<str[i];
    while(i>0){
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

    cout<<str<<endl;
    reverseString(str);
    cout<<str;
}

void printallPrefix(char str[]){
    int len = lengthString(str);
    for(int i=0 ; i<len-1;i++){
        for(int j = 0 ; j<=i ;j++){
            cout<<str[j];
        }
        cout<<endl;
    }
}

void subString(char str[]){
   
}

bool checkPermutation(char str1[],char str2[]){
    int A[26]={0};

    int i=0;
    while(str1[i] != '\0'){
        A[str1[i]-97] += 1;
        i++;
    }
    int j=0;
    while(str2[j]!='\0'){
        A[str2[j]-97]-=1;
        j++;
    }
    for(int k=0;k<26;k++){
        if(A[k]!= 0){
            return false;
        }
    }
    return true;
}

void removeConsecutiveDuplicates(char input[]) {
   int i =0,j=0;
   while(input[j]!='\0'){
    // j=i+1;
    if(input[i]==input[j]){
        j++;
    }else{
        cout<<input[i];
        i=j;
        j=j+1;
    }
   }
   cout<<input[i];
}

void removeConsecutiveDupl(char str[]){
    for(int i=1 ; str[i]!='\0' ; i++){
        if(str[i-1] == str[i]){
            str[i-1]=' ';
        }
    }
    int space = 0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!=' '){
            int temp = str[i];
            str[i]=str[space];
            str[space]=temp;
            space++;
        }
    }
}

void reverseEachWord(char str[]) {
    int i =0;
    int j=0;
    int k=0;
    while(str[j]!='\0'){
        if(str[j]==' '){
             k=j-1;
            while(i<k){
                int temp=str[i];
                str[i]=str[k];
                str[k]=temp;
                i++;
                k--;
            }
            j=j+1;
            i=j;
        }else{
            j++;
        }
  
    }
    int len=lengthString(str);
     i=len-1;
     j=len-1;
     int space = 0;
    while(i>0){
        if(str[i]!=' '){
            i--;
        }else{
            int k=i+1;
            space=1;
            for(;k<j;j++,k--){
                int temp=str[k];
                str[k]=str[j];
                str[j]=temp;
                break;
            }
            break;
        }
    }
   
}

int main(){
 char str[100];
//  char str1[100];
 cout<<"Enter a string1:";
 cin.getline(str,100);
//  removeConsecutiveDupl(str);
reverseEachWord(str);
 cout<<str;
//  cout<<"Enter a string2:";
//  cin.getline(str1,100);

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
// ReverseWordwise(str);
// bool output = checkPermutation(str,str1);
// cout<<output;
// printallPrefix(str);
// cout<<str;

}