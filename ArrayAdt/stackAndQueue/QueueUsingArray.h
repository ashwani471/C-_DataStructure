#include<iostream>
using namespace std;
template<typename T>

class QueueArray{
   private:
    T *data;
    int firstIndex;
    int nextIndex;
    int capacity;
    int size;

   public: 
     QueueArray(int s){
       data = new T[s];
       firstIndex = -1;
       nextIndex = 0;
       capacity = s;
       size = 0;
     } 

     int getsize(){
        return size;
     }

     bool isEmpty(){
       return size == 0;
     }
     // ------------static Queue-----------------------------------//
    //  void enqueue(T element){
    //     if(size == capacity){
    //       cout<<"Queue Full"<<endl;
    //       return;
    //     }
    //     data[nextIndex] = element;
    //     nextIndex = (nextIndex+1)%capacity;
    //     if(firstIndex == -1){
    //         firstIndex == 0;
    //     }        
    //     size++;
    //  }

    //-------------------Dynamic Queue ---------------------//

     void enqueue(T element){
        if(size == capacity){
          T *newData = new T[*capacity];
          int j=0;
          if(firstIndex == 0){
            for(int i = firstIndex ; i<capacity ;i++){
                newData[j]=data[i];
                j++;
            }
          }else{
            for(int i = firstIndex ; i<capacity ;i++){
                newData[j] = data[i];
                j++;
            }
            for(int i = 0 ; i< firstIndex ;i++){
                newData[j] = data[i];
                j++;
            }
          }
          data =newData;
          firstIndex =0;
          nextIndex = capacity;
          capacity*=2;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex+1)%capacity;
        if(firstIndex == -1){
            firstIndex == 0;
        }        
        size++;
     }


     T front(){
        if(isEmpty()){
            cout<<"Queue Empty";
            return 0;
        }
        return data[firstIndex];
     }

     T dequeue(){
         if(isEmpty()){
            cout<<"Queue Empty"<<endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        size--;
        if(size==0){
            firstIndex=-1;
            nextIndex =0;
        }
        return ans;
     }
};