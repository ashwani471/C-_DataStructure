#include<iostream>
using namespace std;

void sortinSortedManner(int * arr , int n){
    int max = arr[0];
    for(int i=1;i<n;i++){
        if(max<arr[i]){
            max=arr[i];
        }
    }
    int *A=new int[max];
    for(int j=0;j<max;j++){
        A[j]=0;
    }
}

int main(){
    int n;
    cout<<"Enter the size of an array:";
    cin>>n;

    int *arr = new int[n];
    for(int i = 0 ;i<n ;i++){
        cin>>arr[i];
    }
    sortinSortedManner(arr,n);
}