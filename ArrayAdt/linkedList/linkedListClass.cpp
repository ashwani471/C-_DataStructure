#include<iostream>
using namespace std;

class Node{
  public:
    int data;
    Node *next;
    
    Node(int n){
        this->data = n;
        next = NULL;
    }

};