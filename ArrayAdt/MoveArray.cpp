#include<iostream>
using namespace std;

// void printArray(int arr , int n)
// {
//     for(int i = 0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }
void MoveArray(int arr[], int n,int p,int d=0){

if(d==0){
    int i=0;
    while(i<p){
        int temp = arr[0];
        for(int j =0 ; j<n ;j++){
            arr[j]=arr[j+1];
        }
        arr[n-1]=temp;
        i++;
    }

}else{
    int i=0;
     while(i<p){
        int temp=arr[n-1];
        for(int j=n-1 ; j>0 ;j--){
            arr[j]=arr[j-1];
        }
        arr[0]=temp;
        // p++;                   
        i++;                         
     }
}

 for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n ;
    cout<<"Enter the No:";
    cin>>n;
    int *arr = new int[n];
    for(int i=0 ; i<n ;i++){
        cin>>arr[i];
    }
    int p;
    cout<<"Enter How may element you want to move:";
    cin>>p;
    int d;
    cout<<"Enter in which direction you want to move:";
    cin>>d;
    MoveArray(arr,n,p,d);
    // printArray(arr,n);
}