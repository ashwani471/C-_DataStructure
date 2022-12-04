#include<iostream>
using namespace std;

void removeConsecutiveDuplicates(char str[]){
    if(str[0]=='\0'|| str[1]=='\0'){
       return;
    }
    if(str[0]==str[1]){
        int i=1;
        for(;str[i]!='\0';i++){
            str[i-1]=str[i];
        }
        str[i-1]=str[i];
        removeConsecutiveDuplicates(str);
    }else{
        removeConsecutiveDuplicates(str+1);
    }
}

void merge(int input[],int si,int mid,int ei){
    int i=si;
    int j=mid+1;
    int output[ei-si+1];
    int k=0;
    while(i<=mid&& j<=ei){

        if(input[i]<input[j]){
            output[k]=input[i];
            i++;
            k++;
        }else{
             output[k]=input[j];
             k++;
             j++;    
        }

        if(i<=mid){
            output[k]=input[i];
            i++;
            k++;
        }
        if(j<=ei){
            output[k]=input[i];
            j++;
            k++;
        }
   }
   int l=0;
   for(;i<=ei;i++){
    input[i]=output[l];
    l++;
   }
}

void mergeSort(int input[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid = (si+ei)/2;
    mergeSort(input,si,mid);
    mergeSort(input,mid+1,ei);
    merge(input,si,mid,ei);
}

void swap(int *a , int *b){
  int temp = *a;
    *a=*b;
    *b = temp;
}

int partition(int arr[],int s , int e){
    int pivot = arr[s];
    int cnt = 0;
    for(int i=s+1 ; i<=e ; i++){
      if(arr[i]<pivot){
        cnt++;
      }
    }
    int pivotIndex = s+cnt;
    swap(&arr[s],&arr[pivotIndex]);
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex){
        if(arr[i]>pivot && arr[j]<pivot){
            swap(&arr[i],&arr[j]);
            i++;
            j--;
        } else if(arr[i]<pivot){
            i++;
        }else if(arr[j]>pivot){
            j--;
        }
    }
    return pivotIndex;
}

void quickSort(int arr[] , int s , int e){
    if(s>=e){
        return ;
    }
    int p = partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
}

int substring(string input , string output[]){
    if(input.empty()){
        output[0]="";
        return 1;
    }
    string smallString = input.substr(1);
    int smallOutput = substring(smallString,output);
    for(int i = 0;i<smallOutput ; i++){
        output[i+smallOutput] = input[0]+output[i];
    }
    return 2*smallOutput;
}

int main(){
// int n;
// cout<<"Enter a number:";
// cin>>n;
// int *input = new int[n];
// for(int i=0;i<n;i++){
//     cin>>input[i];
// }
// // mergeSort(input,0,n-1);
// // for(int i=0;i<n;i++){
// //     cout<<input[i]<<" ";
// // }
// quickSort(input,0,n-1);
// for(int i=0 ; i<n ; i++){
//     cout<<input[i]<<" ";
string str;
cin>>str;
string *output = new string[100];
int count = substring(str,output);
for(int i=0;i<count;i++){
cout<<output[i]<<endl;
}
}

