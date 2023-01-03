#include<iostream>
using namespace std;
#include"vector"
template<typename T>

class treeNode{
public:
 int data;
 vector<treeNode<T>*> children;

  treeNode(T data){
    this->data=  data;
  }
};