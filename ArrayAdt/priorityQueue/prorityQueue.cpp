#include<iostream>
using namespace std;

void inplaceHeapSort(int pq[] ,int n){
  //Build the heap in input array
   for(int i=1 ; i<n ;i++){
    int childIndex = i;
    while(childIndex > 0){
      int parentIndex = (childIndex-1)/2;
      if(pq[childIndex]<pq[parentIndex]){
        int temp = pq[childIndex];
        pq[childIndex] = pq[parentIndex];
        pq[parentIndex] = temp;
      }else{
        break;
      }
      childIndex = parentIndex;
    }
   }

   //remove element
   int size = n;
   int temp = pq[0];
   pq[0] = pq[n-1];
   pq[n-1] = temp;

   size--;
   int parentIndex = 0;
   int leftchildIndex = (2*parentIndex)+1;
   int rightchildIndex = (2*parentIndex)+2;

   while(leftchildIndex < size){
            int minIndex = parentIndex;
            if(pq[leftchildIndex]<pq[minIndex]){
                if(rightchildIndex<size&& pq[rightchildIndex]<pq[minIndex]){
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
}

int main(){

}


