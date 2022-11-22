#include<iostream>
using namespace std;

int Power(int x , int n){

    if(x>0){
        if(n==0){
            return 1;
        }
        int smallPower = x*Power(x,n-1);
        return smallPower;
    }
}

int Count(int n){
    if(n==0){
        return 0;
    }
    int smallNumber = Count(n/10);
    return smallNumber+1;
}

int Fibo(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    int smalloutput1 = Fibo(n-1);
    int smalloutput2 = Fibo(n-2);
    return smalloutput1+smalloutput2;
}

bool is_Sorted(int arr[] , int n){
    if(n==0 || n==1 ){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    bool smallOutput = is_Sorted(arr+1 , n-1);
    return smallOutput;
}

int arraySum(int arr[],int n){
    if(n==1){
        return arr[0];
    }
    int smallOutput = arraySum(arr+1,n-1);
    return smallOutput+arr[0];
}

bool searchElement(int arr[] , int n , int x){
    if(n==0){
        return false; 
    }
    if(arr[0]==x){
        return true;
    }
   bool smallOutput = searchElement(arr+1, n-1, x);
    return smallOutput;
}

int firstIndex(int arr[],int n,int x){
    if(n==0){
        return -1;
    }
    if(arr[0]==x){
        return 0;
    }
    int smallOutput = firstIndex(arr+1,n-1,x); 
    // return smallOutput+1;
    if(smallOutput==-1){
        return -1;
    }else{
        smallOutput+1;
    }
}

int lastIndex(int arr[],int n,int x){
    if(n==0){
        return -1;
    }
    int smalloutput = lastIndex(arr+1,n-1,x);
    if(smalloutput!=-1){
        return smalloutput+1;
    }
    if(arr[0]==x){
        return 0;
    }else{
        return smalloutput;
    }
}


void TreeRecursion(int n){
    if(n>0){
        cout<<n<<" ";
        TreeRecursion(n-1);
        TreeRecursion(n-1);

    }
}

int nestedRecursion(int n){
    if(n>100){
        return n-10;
    }else{
        return nestedRecursion(nestedRecursion(n+11));
    }
}

int SumOfNaturalNumber(int n){
    if(n==0){
      return 0;
    }
    int smallOutput = SumOfNaturalNumber(n-1)+n;
    return smallOutput;
}

int main(){
    int n;
    cout<<"Enter a number:";
    // cout<<"Enter the power:";
    cin>>n;
    // int *arr = new int[n];
    // for(int i=0 ; i<n ; i++){
    //     cin>>arr[i];
    // } 
    // int x;
    // cout<<"Enter a Element that you want to search:";
    // cin>>x;
    // TreeRecursion(n);
    // cout<<nestedRecursion(97);
    cout<<SumOfNaturalNumber(n);
    // cout<<is_Sorted(arr, n);
    // cout<<arraySum(arr,n);
    // cout<<searchElement(arr,n,x);
    // cout<<firstIndex(arr,n,x);
    // cout<<lastIndex(arr,n,x);
    // int x;
    // cout<<"Enter the value:";
    // cin>>x;
    // cout<<Power(x,n);

    //  cout<<Count(n);
    // cout<<Fibo(n);
}






