#include<iostream>
using namespace std;
#include "treeClass.h"

treeNode<int> *takeInput(){
    int rootData;
    cout<<"Enter data:";
    cin>>rootData;
    treeNode<int>* root = new treeNode<int>(rootData);

    int n;
    cout<<"Enter num of children of"<<rootData<<endl;
    cin>>n;
    for(int i=0 ; i<n ;i++){
        treeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(treeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0 ; i<root->children.size() ; i++){
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size() ;i++){
        printTree(root->children[i]);
    }
}

int main(){
    treeNode<int> *root = new treeNode<int>(1);
    treeNode<int> *node1 = new treeNode<int>(2);
    treeNode<int> *node2 = new treeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);
  }