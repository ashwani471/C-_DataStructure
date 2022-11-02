#include<iostream>
using namespace std;

// void fun(int A[],int n){    //Here A[] working as Pointer
//     A[0]=6;
//     cout<<sizeof(A)/sizeof(int) //outcome is 2 because A is a  pointer  to an array so sizeof(A)=8 int =4 so 8/4 = 2..   
// }

int * fun(int n){
    int *p;
    p= new int[n];
    for(int i=0;i<n;i++)
        p[i]=i+1;
    
    return p;
}

int main(){
    // int A[5] = {1,2,3,4,5};
    // fun(A,5);
    int *A;
    A=fun(5);
    for(int i=0;i<5;i++){
        cout<<A[i]<<" ";
    }
    // cout<<sizeof(A)/sizeof(int);  //outcome is 5
    // cout<<A[0]<<endl;
}