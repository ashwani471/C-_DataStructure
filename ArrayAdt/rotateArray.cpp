#include<iostream>
using namespace std;

// void rotateArray(int *arr , int n, int d){
//    for(int i=0 ; i<=d ; i++){
//     int temp = arr[0];
//     for(int j = 0;j<n-1;j++){
//         arr[j] =arr[j+1];
//     }
//     arr[n]=temp;
//    }
// }

void rotate(int *arr, int d, int n)
{
      d=d%n;
      for(int i=0 ;i<n;i++){
        if(i<d){
          cout<<arr[n+i-d]<<" ";
        }else{
          cout<<arr[i-d]<<" ";
        }
      }
}

int main(){
    int n;
    cout<<"Enter the size of an array:";
    cin>>n;

    int d;
    cout<<"Enter how many element you wants to rotate:";
    cin>>d;

    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // rotateArray(arr,n,d);

    rotate(arr,d,n);

    //  for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    //  }

}