#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>

vector<int> removeDuplicate(int *a ,int n){
    vector<int> output;
    unordered_map<int , bool> seen;
    for(int i=0 ; i<n ;i++){
        if(seen.count(a[i])>0){
            continue;
        }
        seen[a[i]]= true;
        output.push_back(a[i]);
    }
    return output;
}

int highestFrequencyNum(int *arr , int n){
    unordered_map<int,int> freq;
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    int maxFreq = freq[arr[0]];
    int max = arr[0];
    for(int i =1;i<n;i++){
        if(freq[arr[i]]>maxFreq){
            max=arr[i];
            maxFreq=freq[arr[i]];
        }
    }
    return max;
}

vector<int> arrayIntersection(int *arr1 , int *arr2 , int size1 , int size2){
    vector<int> output1;
    unordered_map<int , int> intersection;

    for(int i=0 ; i<size1 ; i++){
        intersection[arr1[i]]++;
    }
    
    for(int i=0; i<size2 ;i++){
        if(intersection[arr2[i]]>0){
            output1.push_back(arr2[i]);
            intersection[arr2[i]]--;
        }
    }
    return output1;
}

int main(){
    int arr[] = {1,2,3,1,2,3,4,10};
    int arr1[]={1,2,3,1,6,10};
    // vector<int>output = removeDuplicate(arr , 7);
    // for(int i=0 ; i<output.size() ;i++){
    //     cout<<output[i]<<endl;
    // }
    // int max = highestFrequencyNum(arr , 8);
    // cout<<max;
    vector<int> output = arrayIntersection(arr,arr1,8,6);
    for(int i=0 ; i<output.size() ;i++){
        cout<<output[i]<<endl;
    }
}