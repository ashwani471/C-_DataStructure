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

  ~treeNode(){
    for(int i=0 ;i<children.size() ; i++){
        delete children[i];
    }
  }
};
template<typename T>
class maxSumNode{
    public:
    int max;
    treeNode<T>* root;

    // maxSumNode(int data){
    //  this->max = data;
    // }
};