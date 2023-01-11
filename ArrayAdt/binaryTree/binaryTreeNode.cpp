#include<iostream>
using namespace std;
#include<queue>
#include"binaryTree.h"

void printBinaryTree(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
cout<<root->data<<":";
if(root->left != NULL){
  cout<<root->left->data<<"L,";
}
if(root->right != NULL){
    cout<<root->right->data<<"R";
}
cout<<endl;
printBinaryTree(root->left);
printBinaryTree(root->right);
}

BinaryTreeNode<int>* takeInput(){
   int rootData;
   cout<<"Enter rootData:"<<endl;
   cin>>rootData;
   if(rootData == -1){
    return NULL;
   }

   BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
   BinaryTreeNode<int>* leftChild = takeInput();
   BinaryTreeNode<int>* rightChild = takeInput();
   root->left = leftChild;
   root->right = rightChild;
   return root;   
}

BinaryTreeNode<int>* takeInputlvlwise(){
    int rootData;
    cout<<"Enter rootData:";
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while(pendingNodes.size() != NULL){
      BinaryTreeNode<int>* front = pendingNodes.front();
      pendingNodes.pop();
      cout<<"Enter left child of : "<<front->data;
      int leftchild;
      cin>>leftchild;
      if(leftchild!=-1){
        BinaryTreeNode<int>* child =new BinaryTreeNode<int>(leftchild);
        front->left = child;
        pendingNodes.push(child);
      }
      cout<<"Enter right child of : "<<front->data;
      int Rightchild;
      cin>>Rightchild;
      if(Rightchild!=-1){
        BinaryTreeNode<int>* child =new BinaryTreeNode<int>(Rightchild);
        front->right = child;
        pendingNodes.push(child);
      }
    }
    return root;

}

int main(){
    BinaryTreeNode<int> *root = takeInputlvlwise();
    printBinaryTree(root);
}
