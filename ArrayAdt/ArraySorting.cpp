#include<iostream>
using namespace std;

void bubbleSort(int *arr , int n){
    for(int i=0;i< n-1;i++){
        int flag = 0;
        for(int j = 0 ; j < n-1-i; j++){
            
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
            if(flag == 0){
                // return *arr;
                break;
            }
        }
    }
    // return *arr;
   
}

void insertionSort(int *arr, int n){
for(int i=1 ; i<n ;i++){
    int j = i-1;
    int x = arr[i];
    while(j>-1 && arr[j]>x){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1] = x;
}
}

void selectionSort(int *arr, int n){
    for(int i=0 ; i<n-1; i++){
      int j=i,k=i;
      for(;j<n;j++){
        if(arr[j]<arr[k]){
            k=j;
        }
        int temp = arr[i];
        arr[i]=arr[k];
        arr[k]=arr[i];
      }
    }
}

int *mergeSort(int arr1[],int &m, int arr2[],int &n ){
   int *arr3 = new int[m+n];
   int i=0,j=0;
   int k=0;
    while(i<m && j<n){
       if(arr1[i]<arr2[j]){
        arr3[k]=arr1[i];
        i++;
        k++;
       }else{
        arr3[k]=arr2[j];
        j++;
        k++;
       }
    }
    if(i<k){
        while(i<m){
            arr3[k]=arr1[i];
            i++;
            k++;
        }
    }else if(j<k){
        while(j<n){
          arr3[k]=arr2[j];
          j++;
          k++;
        }
    }
    return arr3;

}

int main(){
    int n;
    cout<<"Enter the size of an Array:" ;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int m;
    cout<<"enter the size of an second array:";
    cin>>m;

    int *arr1 = new int[m];
    for(int j=0;j<m;j++){
        cin>>arr1[j];
    }

    //  bubbleSort(arr,n);

    // insertionSort(arr,n);

    // selectionSort(arr,n);

    int *arr2 = mergeSort(arr,n,arr1,m);
    // cout<<arr2;
    int bigSize=m+n;
    for(int i=0 ; i<bigSize ; i++){
        cout<<arr[i]<<" ";
    }
    // cout<<arr;

    // for(int i = 0 ; i<n ;i++){
    //     cout<<arr[i]<<" ";
    // }
}