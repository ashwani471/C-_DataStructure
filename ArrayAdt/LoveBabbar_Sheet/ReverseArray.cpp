#include<iostream>
using namespace std;
//iterative methode
// int* reverseArray(int *arr,int n){
//     int i=0;
//     int j=n-1;
//     while (i<=j)
//     {
//         int temp = arr[i];
//         arr[i]=arr[j];
//         arr[j]=temp;
//         i++;
//         j--;
//     }

//     // for(int k = 0 ; k<n ; k++){
//     //     cout<<arr[k]<<" ";
//     // }
//     // cout<<endl;
//     return arr;
// }

// int main(){
//     int n;
//     cout<<"Enter the size of an Array:";
//     cin>>n;
//     int *arr = new int[n];

//     for(int i=0 ; i<n ;i++){
//         cin>>arr[i];
//     }

//     int *arr2 = reverseArray(arr,n);
     
//     for(int k = 0 ; k<n ; k++){
//         cout<<arr[k]<<" ";
//     }
     
// }

//reverse Array using recursion

void helpReverseArray(int *arr,int start,int end){
     if(start >= end){
      return;
    }
    int temp = arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
    helpReverseArray(arr,start+1,end-1);
}

void reverseArray(int *arr , int n){
    int start = 0 ;
    int end = n-1;
   
    helpReverseArray(arr,start,end);
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0 ; i< n ;i++){
        cin>>arr[i];
    }

    reverseArray(arr,n);

    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }

}