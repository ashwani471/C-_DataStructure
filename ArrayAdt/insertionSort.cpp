#include<iostream>
using namespace std;

void insertionSort(int *arr , int n){
    for(int i=0 ; i<n-1 ;i++){
        for(int j=i+1 ; j>0 ; j--){
            if(arr[j]<arr[j-1]){
                int temp =arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}

int main(){
    int n;
    cout<<"Enter the size of an array:";
    cin>>n;

    int *arr = new int[n];
    for(int i=0 ;i<n ;i++){
        cin>>arr[i];
    }

    insertionSort(arr , n);

    for(int i =0 ; i<n ;i++){
        cout<<arr[i]<<" ";
    }
}