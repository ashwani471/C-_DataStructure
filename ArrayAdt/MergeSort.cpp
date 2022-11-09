#include<iostream>
using namespace std;

void mergeSort(int *arr1 , int n , int *arr2 , int m,int *arr3){
     
     int i =0,j =0,k=0;
     while(i<n&&j<m){
        if(arr1[i]>arr2[j]){
            arr3[k]=arr2[j];
            j++;
            k++;
        }else if(arr1[i]<arr2[j]){
            arr3[k]=arr1[i];
            i++;
            k++;
        }
     }
     if(i<n){
        for(int l=i;l<n;l++){
            arr3[k]=arr1[l];
            k++;
        }
     }else{
        for(int l=j ; l<m; l++){
            arr3[k]=arr2[l];
            k++;
        }
     }
    //  return arr3;
}

int main(){
    int n;
    cout<<"Enter the size of an array1:";
    cin>>n;

    int *arr1 = new int[n];
    for(int i=0 ; i<n ;i++){
        cin>>arr1[i];
    }

    int m;
    cout<<"Enter the size of array2:";
    cin>>m;

    int *arr2 = new int[m];
    for(int j = 0 ; j<m ; j++){
        cin>>arr2[j];
    }

    int size = m+n;
    int *arr3 = new int[size];

    mergeSort(arr1,n,arr2,m,arr3);

    for(int k = 0 ; k<m+n ; k++){
        cout<<arr3[k]<<" ";
    }
}