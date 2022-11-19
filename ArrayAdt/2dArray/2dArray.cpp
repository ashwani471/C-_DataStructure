#include<iostream>
using namespace std;

void transposeArray(int arr[][5],int m,int n){
    cout<<"Column Wise:"<<endl;
 for(int i=0 ; i<n;i++){
    for(int j=0 ; j<m ;j++){
        cout<<arr[j][i]<<" ";
    }
    cout<<endl;
 }
}

void columnswiseSum(int arr[][5],int m , int n){
   
    for(int i=0 ;i<n;i++){
         int sum=0;
        for(int j=0;j<m ;j++){
           sum=sum+arr[j][i];
        }
        cout<<sum<<" ";
    }
}

void printWavewise(int arr[][5],int m,int n){
   for(int j=0 ; j<n ;j++){
    if(j%2==0){
    for(int i=0 ; i<m ;i++){
        cout<<arr[i][j]<<" ";
    }
    }else{
        for(int i=m-1 ; i>=0 ;i--){
            cout<<arr[i][j]<<" ";
        }
    }
   }
}





int main(){
    int m;
    cout<<"Enter no of rows:";
    cin>>m;
    int n;
    cout<<"Enter no of columns:";
    cin>>n;

    int arr[5][5];
    
    for(int i = 0;i<m;i++){
          for(int j=0;j<n;j++){
            cin>>arr[i][j];
          }
          cout<<endl;
    }
    cout<<"Row Wise:"<<endl;
    for(int i = 0; i<m; i++){
          for(int j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
          }
          cout<<endl;
    }

    // transposeArray(arr,m,n);
    // columnswiseSum(arr,m,n);
    printWavewise(arr,m,n);
}