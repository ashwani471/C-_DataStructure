#include<iostream>
using namespace std;
template<typename T>

class stackUsingArray {
   private:
    T *data;
    T nextIndex;
    T capacity;
   public:
    stackUsingArray(T n){
        data = new int[n];
        nextIndex = 0;
        capacity = n;
    }

    T size(){
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex == 0;
    }

    void push(T element){
        if(nextIndex == capacity){
            // cout<<"stack Full"<<endl;
            // return;
            T *newData = new int[capacity*2];
            for(int i=0 ; i<capacity ;i++){
                newData[i]=data[i];
            }
            capacity*=2;
            delete [] data;
            data=newData;
        }
     data[nextIndex]=element;
      nextIndex++;
    }

    int pop(){
       if(isEmpty()){
          cout<<"Stack is empty:"<<endl;
          return INT16_MIN;
       }
        nextIndex--;
        return data[nextIndex];
    }

    int top(){
        if(isEmpty()){
          cout<<"Stack is empty:"<<endl;
          return INT16_MIN;
       }
        return data[nextIndex-1];
    }

};