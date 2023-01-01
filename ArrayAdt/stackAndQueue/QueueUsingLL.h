#include<iostream>
using namespace std;

template<typename T>

class Node{
 private:
  T data;
  Node<T> *next;

 public:
   Node(T element){
    this->data = element;
    next = NULL;
   }

};


template<typename T>

class QueueLL{
 private:
  Node<T> *head;
  Node<T> *tail;
  int size;

 public:
  head = NULL;
  tail = NULL;
  size = 0;

  void enqueue(T element){
    Node<T> *newNode = new Node<T>(element);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
    size++;
  }

  int getSize(){
    return size;

  } 

  bool isEmpty(){
    return size==0;
  }  

  T dequeue(){
    if(isEmpty()){
        return 0;
    }
    T ans = head->data;
    Node<T> *temp = head;
    head = head->next;
    delete temp;
    size--;
    return ans;
  }

  T front(){
    if(isEmpty()){
        return 0;
    }
    return head->data;
  }
};
