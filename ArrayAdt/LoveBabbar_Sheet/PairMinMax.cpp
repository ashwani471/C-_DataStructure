#include<iostream>
using namespace std;


// void PairMinMax(int *arr , int n){
//     int min,max;
//     if(arr[0]<arr[1]){
//         min = arr[0];
//         max = arr[1];
//     }
//     for(int i=2 ; i<n ; i++){
//        if(arr[i]>max){
//         max = arr[i];
//        }else if(arr[i]<min){
//         min=arr[i];
//        }
//     }
//     cout<<"Max no:"<<max<<endl;
//     cout<<"Min no:"<<min;

// }

// int main(){
//     int n;
//     cout<<"Enter the size of an Array:";
//     cin>>n;
//     int *arr = new int[n];
//     for(int i=0 ; i<n ;i++){
//         cin>>arr[i];
//     }

//     PairMinMax(arr,n);
// }

// first how to return multiple values

struct Pair
{
   int min;
   int max;
};

// Pair getMinMax(int *arr , int n){

//   struct Pair pairminmax;
//   if(n==1){
//      pairminmax.max = arr[0];
//      pairminmax.min = arr[0];
//   }
//   if(arr[0]>arr[1]){
//     pairminmax.max = arr[0];
//     pairminmax.min = arr[1];
//   }else if(arr[0]<arr[1]){
//     pairminmax.max = arr[1];
//     pairminmax.min = arr[0];
//   }

//   for(int i=2 ; i<n ; i++){
//     if(arr[i]>pairminmax.max){
//         pairminmax.max = arr[i];
//     }else if(arr[i]<pairminmax.min){
//         pairminmax.min = arr[i];
//     }
//   }
//   return pairminmax;
// }

// int main(){
//     int n;
//     cout<<"Enter the size of an array";
//     cin>>n;

//     int *arr = new int[n];
//     for(int i=0 ; i<n ;i++){
//         cin>>arr[i];
//     }

//     struct Pair pairminmax = getMinMax(arr,n);
 
//     cout<<"min no is:"<<pairminmax.min;
//     cout<<"max no is:"<<pairminmax.max;

// }
Pair helpgetMinMax(int *arr, int st , int end){
    struct Pair mml,mmr;
    struct Pair MinMax; 
    if(st == end){
       MinMax.max = arr[0];
       MinMax.min = arr[0];
       return MinMax;
    }
    if(end == st+1){
        if(arr[0]>arr[1]){
            MinMax.max = arr[0];
            MinMax.min = arr[1];
        }else if(arr[0]<arr[1]){
            MinMax.max = arr[1];
            MinMax.min = arr[0];
        }
        return MinMax;
    }
    int mid = (st+end)/2;
    mml = helpgetMinMax(arr,0,mid);
    mmr = helpgetMinMax(arr,mid+1,end);

    if(mml.min < mmr.min){
        MinMax.min=mml.min;
    }else{
        MinMax.min = mmr.min;
    }
    if(mml.max>mmr.max){
        MinMax.max = mml.max;
    }else{
        MinMax.max = mmr.max;
    }
       return MinMax;
}

Pair getMinMax(int *arr , int n){
     
     Pair Minmax=helpgetMinMax(arr,0,n);
     return Minmax;
}

int main(){
    int n;
    cout<<"Enter the size of an array:";
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }

    struct Pair pairminmax = getMinMax(arr,n);

    cout<<"Min no is:"<<pairminmax.min;
    cout<<"Max no is:"<<pairminmax.max;
}