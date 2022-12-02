#include<iostream>
using namespace std;


//by using extra space 
void mergeSort(int arr[],int l,int mid , int h){
    int i=l;
    int j= mid+1;
    int k=0;
    int output[h+1];
   while(i<=mid && j<=h){
    if(arr[i]<arr[j]){
        output[k++]=arr[i++];
    }else{
        output[k++]=arr[j++];
    }
    }
    // if(i!=mid){
    while(i<=mid){
        output[k]=arr[i];
        i++;
        k++;
    }
    // }else if(j!=h){
    while(j<=h){
        output[k]=arr[j];
        j++;
        k++;
    }

   int x=0;
   while(x<=h){
    arr[x]=output[x];
    x++;
   }
}
//without using any extra space

void imergeSort(int a[],int n){
    int p,l,mid,h;
    int i=0;
    for(int p=2 ; p<=n;p=p*2){
        for(;i+p-1<n;i=i+p){
          l=i;
          h=i+p-1;
          mid=(l+h)/2;
          mergeSort(a,l,mid,h);
        }
    }
    if(p/2<n){
        mergeSort(a,0,p/2,n-1);
    }
}

void recMerge(int a[],int l,int h){
    int mid;
    if(l<h){
        mid=(l+h)/2;
        recMerge(a,l,mid);
        recMerge(a,mid+1,h);
        mergeSort(a,l,mid,h);
    }
}


int main()
{
    int n;
    cout<<"Enter a number:";
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int mid=(0+(n-1))/2;
    // cout<<"mid:"<<mid<<endl;
    // mergeSort(arr,0,mid,n-1);
    recMerge(arr,0,n-1);

    for(int j=0;j<n;j++){
        cout<<arr[j]<<" ";
    }
}