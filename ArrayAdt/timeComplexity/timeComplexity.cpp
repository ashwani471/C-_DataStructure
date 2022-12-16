#include<iostream>
#include <bits/stdc++.h>
using namespace std;

// int findUnique(int arr[] , int n){
//     int unique = arr[0];
//     for(int i=1 ; i<n ;i++){
//         unique = unique^arr[i];
//     }
//     return unique;
// }

int findUnique(int arr[],int n){
    if(n==0){
        return arr[0];
    }
    int smallOutput = findUnique(arr+1,n-1);
     return smallOutput^arr[0];
}

int duplicateNum(int arr[], int n){
    for(int i=0,j=i+1;j<n;i++,j++){
        if(arr[i]==arr[j]){
            cout<<"Duplicate number Present on Index:"<<j<<endl;
        }
    }
}

void findIntersection(int arr[] , int n ,int arr1[] , int m){
    int *output = new int[100];
    int i=0,j=0;
    int k=0;
    int size=0;
    while(i<n && j<m){
      if(arr[i]<arr1[j]){
        i++;
      }else if(arr[i]>arr1[j]){
        j++;
      }else{
        
        output[k]=arr[i];
        size=size+1;
        k++;
        arr[i]=-1;
        arr1[j]=-1;
        i++;
        j++;
      }
    }
    for(int l=0 ; l<size;l++){
        cout<<output[l]<<" ";
    }
    cout<<endl;
}

void pairSum(int arr[] , int n ,int x){
    int i =0;
    int j=n-1;
    while(i<j){
        if(arr[i]+arr[j]>x){
            j--;
        }else if(arr[i]+arr[j]<x){
            i--;
        }else{
            cout<<i<<" "<<j<<endl;
            i++;
            j--;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the Length of an Array:";
    cin>>n;
    int *arr = new int[n];
    for(int i=0 ; i<n ;i++){
        cin>>arr[i];
    }
    // int m;
    // cout<<"Enter the length of second array:";
    // cin>>m;
    // int *arr1 = new int[m];
    // for(int j=0;j<m;j++){
    //     cin>>arr1[j];
    // }
    int x;
    cout<<"Give me pairSum value:";
    cin>>x;

    sort(arr, arr + n);
    // sort(arr1,arr1+m);
      pairSum(arr,n,x);
    // findIntersection(arr,n,arr1,m);
    // duplicateNum(arr,n);
    // int uniqueElm= findUnique(arr,n);
    // cout<<uniqueElm;
}