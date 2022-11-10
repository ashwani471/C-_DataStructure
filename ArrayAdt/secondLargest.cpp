#include<iostream>
using namespace std;

int secondLargest(int *arr ,int n){
    int m1,m2=-10;
    for(int i = 0; i<n;i++){
        if(arr[i]>m1 && arr[i]>m2){
            m1=arr[i];
            m2=m1;
        }else if(arr[i]<m1 && arr[i]>m2){
            m2=arr[i];
        }else{
            continue;
        }
    }
    return m2;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0 ; i<n ;i++){
        cin>>arr[i];
    }
   cout<<secondLargest(arr,n);
}