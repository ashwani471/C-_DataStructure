#include<iostream>
using namespace std;

void pushZero(int *arr , int n){
   int i=0 , j=n-1;
   while(i<=j){
    if(arr[i]!=0 && arr[j]!=0){
     i++;
    }
    else if( arr[i] == 0 && arr[j]!=0){
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }else if(arr[i]==0 && arr[j]==0){
        j--;
    }
   }
}

int main(){
    int n;
    cout<<"enter the size of an array:";
    cin>>n;

    int *arr = new int[n];
    for(int i=0 ;i<n;i++){
        cin>>arr[i];
    }
    pushZero(arr,n);

    for(int i=0 ; i<n ;i++){
        cout<<arr[i]<<" ";
    }
}