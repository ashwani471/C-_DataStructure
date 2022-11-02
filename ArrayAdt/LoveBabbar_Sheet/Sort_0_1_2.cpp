#include<iostream>
using namespace std;

void swaps(int a,int b){
    int temp = b;
     b=a;
    a=temp;
}

void SortInOrder(int *arr,int n){
    int lo=0,mid=0,high = n-1;
    while(mid<=high){
        if(mid==0){
            swaps(arr[mid],arr[lo]);
            mid++;
            lo++;
        }else if(mid==1){
            mid++;
        }else if(mid==2){
            swaps(arr[mid],arr[high]);
            mid=mid-1;
            high=high+1;
        }
    }
}

int main(){
    int n;
    cout<<"Enter tyhe size of an array";
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SortInOrder(arr,n);
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
}