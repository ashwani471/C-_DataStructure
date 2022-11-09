#include<iostream>
using namespace std;


void swap(int *a , int *b){
            int temp = *a;
            *a = *b;
            *b = temp;
     }

void selectionSort(int *arr, int n){
    int j,k;
    for(int i=0 ; i<n-1;i++){
        int j,k;
        
        for(j= k = i; j<n; j++){
            if(arr[j]<arr[k]){
                k=j;
            }
        }
    //  swap(&arr[i],&arr[j]);
     int temp = arr[i];
     arr[i]=arr[k];
     arr[k]=temp;
    }
}

int main(){
    int n;
    cout<<"Enter the Size of an array:";
    cin>>n;

    int *arr = new int[n];

    for(int i=0 ; i < n ; i++){
        cin>>arr[i];
    }

    selectionSort(arr , n-1);

    for(int j = 0 ;j<n;j++){
        cout<<arr[j]<<' ';
    }
}