#include<iostream>
#include<algorithm>
using namespace std;

void sumArray(int *arr1 , int n , int *arr2 , int m,int *output){
    int outsize = std::max(m,n)+1;

    int sum = 0;
    int carry =0;
    for(int i=n-1,j=m-1,k=outsize-1;i>=0||j>=0;i--,j--,k--){
        sum = arr1[i]+arr2[j]+carry;
        if(sum>9){
            int a = sum/10;
            sum=sum%10;
            output[k]=sum;
            carry=a;
            if(i>0 && j==0){
                k--;
                
                sum=arr1[i]+carry;
                
                if(sum>9){
                    carry=1;
                    output[k]=sum%10;
                    k--;
                    output[k]=carry;
                }else{
                    output[k]=sum;
                }
            }
            // if(i>=0&&j<0&& carry>0){    
            //     k--;
            //     output[k]=carry;
            // }else if(i<0&&j>=0 && carry>0){
            //     k--;
            //     output[k]=carry;
            // }
             
        }else if(sum<=9){
            output[k]=sum;
            carry=0;
        }
    }
    

}

int main(){
    int n;
    cout<<"enter the size of an array:";
    cin>>n;
    int *arr1 = new int[n];

     for(int j=0 ; j<n ;j++){
        cin>>arr1[j];
     }  
    int m;
    cout<<"Enter the size of second Array:";
    cin>>m;
    int *arr2 = new int[m];


    for(int i =0 ;i<m ;i++){
        cin>>arr2[i];
    }
    int outsize = std::max(m,n)+1;

    int * output = new int[outsize];


    sumArray(arr1,n,arr2,m,output);

    for (int i = 0; i < outsize; ++i)
		{
			cout << output[i] << " ";
		}
}