#include <vector>

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
        pq.push(element);
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
};