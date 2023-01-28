#include <vector>
#include<iostream>
using namespace std;

class PriorityQueue{

    vector<int> pq;

    public:
     PriorityQueue(){

     }
     bool isEmpty(){
        return pq.size()==0;
     }

     int getSize(){
        return pq.size();
     }

     int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
     }

     void insert(int element){
        pq.push_back(element);
        int child_index = pq.size()-1;
        int parentIndex = (child_index -1)/2;

        while(child_index>0){
          int parentIndex = (child_index -1)/2;
          if(pq[parentIndex]<pq[child_index]){
            int temp = pq[child_index];
            pq[child_index] = pq[parentIndex];
            pq[parentIndex] = temp;
          }else{
            break;
          }
          child_index = parentIndex;
        }
     }

    int removeMin(){
        if(isEmpty()){
            return 0;
        }
        int ans = pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();

        int parentIndex = 0;
        int leftchildIndex = 2*parentIndex + 1;
        int rightchildIndex = 2*parentIndex + 2;

        while(leftchildIndex < pq.size()){
            int minIndex = parentIndex;
            if(pq[leftchildIndex]<pq[minIndex]){
                if(rightchildIndex<pq.size()&& pq[rightchildIndex]<pq[minIndex]){
                    if(pq[leftchildIndex] < pq[rightchildIndex]){
                        minIndex = leftchildIndex;
                    }else{
                        minIndex = rightchildIndex;
                    }
                }
        
            }
            if(minIndex == parentIndex){
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex]=pq[parentIndex];
            pq[parentIndex]=temp;

            parentIndex = minIndex;
            leftchildIndex = 2*parentIndex+1;
            rightchildIndex = 2*parentIndex+2;
        }
        return ans;
      
     }
};