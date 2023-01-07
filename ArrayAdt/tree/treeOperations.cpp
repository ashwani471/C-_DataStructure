#include<iostream>
using namespace std;
#include<queue>
#include "treeClass.h"

treeNode<int> *takeInputlvelwise(){
    int rootdata;
    cout<<"enter root data:";
    cin>>rootdata;
    treeNode<int> *root = new treeNode<int>(rootdata);
    queue<treeNode<int>*> pendingNode;
    pendingNode.push(root);

    while(pendingNode.size() != 0){
     treeNode<int> *front = pendingNode.front();
     pendingNode.pop();
     int n;
     cout<<"Enter Num of children of "<<front->data<<":";
     cin>>n; 

     for(int i= 0 ; i<n; i++){
        int childData;
        cout<<"Enter "<<i+1 << "th child of "<<front->data<<":";
        cin>>childData;
        treeNode<int> *child = new treeNode<int>(childData);
        front->children.push_back(child);
        pendingNode.push(child);
     }
    }
    return root;
}

treeNode<int> *takeInput(){
    int rootData;
    cout<<"Enter data:";
    cin>>rootData;
    treeNode<int>* root = new treeNode<int>(rootData);

    int n;
    cout<<"Enter num of children of: "<<rootData<<endl;
    cin>>n;
    for(int i=0 ; i<n ;i++){
        treeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTreeLvlwise(treeNode<int>* root){
    if (root==NULL){
        return;
    }
    queue<treeNode<int>*> pendingNum;
    pendingNum.push(root);
    while(pendingNum.size()!=0){
    treeNode<int> *front = pendingNum.front();
    cout<<front->data<<":";
    pendingNum.pop();
    for(int i=0 ;i<front->children.size();i++){
        if(i==front->children.size()-1){
            cout<<front->children[i]->data;
        }else{
            cout<<front->children[i]->data<<",";
        }
        pendingNum.push(front->children[i]);
    }
    cout<<endl;
    }
    
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

int countNode(treeNode<int>* root){
    int size=1;
    for(int i=0 ; i<root->children.size() ; i++){
        size+=countNode(root->children[i]);
    }
    return size;
}

int sumofNode(treeNode<int>* root){
    int sum=root->data;
    for(int i=0 ;i<root->children.size();i++){
        sum+=sumofNode(root->children[i]);
    }
    return sum;
}

treeNode<int>* maxdataNode(treeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    treeNode<int>* max = root;
    for(int i=0 ; i<root->children.size() ; i++){
        treeNode<int> *temp = maxdataNode(root->children[i]);
        if(max->data<temp->data){
            max= temp;
        }
    }
    return max;

}

int height(treeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int max = 0;
    for(int i=0;i<root->children.size();i++){
       int smallHeight = height(root->children[i]);
       if(smallHeight>max){
        max=smallHeight;
       }
    }
    return max+1;
}

void printAtlvlK(treeNode<int>* root , int k)
{
if(root == NULL){
    return;
}
if(k==0){
    cout<<root->data<<endl;
    return ;
}
for(int i=0;i<root->children.size() ;i++){
    printAtlvlK(root->children[i] ,k-1);
}
}

int countLeafNode(treeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    if(root->children.size()==0){
        return 1;
    }
    int count = 0;
    for(int i=0;i<root->children.size();i++){
      int leafnode = countLeafNode(root->children[i]);
      count += leafnode;
    }
    return count;
}

void preOrder(treeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i=0 ; i<root->children.size() ;i++){
        preOrder(root->children[i]);
    }
}

void postOrder(treeNode<int>* root){
    if(root == NULL){
        return;
    }
    for(int i = 0 ;i<root->children.size() ;i++){
        postOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}

bool containX(treeNode<int>* root , int x){
    if(root = NULL){
        return 0;
    }
    if(root->data == x){
        return true;
    }
    for(int i = 0 ; i<root->children.size() ;i++){
        bool ans = containX(root->children[i] , x);
        if(ans){
            return true;
        }
    }
    return false;
}

int nodesGreaterthenX(treeNode<int> * root , int x){
    if(root == NULL){
        return 0;
    }
    int cnt = 0;
    if(root->data > x){
     cnt++;
    }
    for(int i =0 ; i<root->children.size() ; i++){
        int smalloutput = nodesGreaterthenX(root->children[i],x);
        cnt+=smalloutput;
    }
    return cnt;
}

maxSumNode<int>* maxchildRootSum(treeNode<int>* root){
    if(root == NULL){
        maxSumNode<int>* pair = new maxSumNode<int>();
        pair->root = NULL;
        pair->max = INT16_MIN;
        return pair;
    }
    int sum = root->data;
    for(int i=0 ; i<root->children.size() ; i++){
       sum+=root->children[i]->data;
    }
    maxSumNode<int>* ans = new maxSumNode<int>();
    ans->root = root;
    ans->max = sum;

    for(int i=0 ; i<root->children.size() ; i++){
        maxSumNode<int>* childsum = maxchildRootSum(root->children[i]);
        if(childsum->max>ans->max){
          ans=childsum;
        }
    }
    return ans;
}

bool isIdentical(treeNode<int>* root1 , treeNode<int>* root2){
    if(root1 == NULL && root2 == NULL){
        return false;
    }
    if(root1->data != root2->data || (root1->children.size()!=root2->children.size())){
        return false;
    }
    if((root1 == NULL && root2!=NULL ) || root1 != NULL && root2 == NULL){
       return false;
    }
    int i=0;
    while(i<root1->children.size()){
        treeNode<int>* child1 = root1->children[i];
        treeNode<int>* child2 = root2->children[i];
        if(isIdentical(child1,child2)){
            return i++;
        }else{
            return false;
        }
    }
    return true;
}

treeNode<int>* nextBiggerValue(treeNode<int>* root ,int n){
    if(root == NULL){
        return root;
    }
    treeNode<int>* ans = NULL;
    if(root->data > n){
        ans = root;
    }
    for(int i=0; i<root->children.size() ;i++){
        treeNode<int>* temp = nextBiggerValue(root->children[i] , n);
        if(ans == NULL){
            ans = temp;
        }else{
            if(temp!=NULL && ans->data > temp->data){
                ans = temp;
            }
        }
    }
    return ans;
}

int main(){
    // treeNode<int> *root = new treeNode<int>(1);
    // treeNode<int> *node1 = new treeNode<int>(2);
    // treeNode<int> *node2 = new treeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    treeNode<int> *root = takeInputlvelwise();
    printTreeLvlwise(root);
    // cout<<countNode(root);
    int x;
    cout<<"nodeData:";
    cin>>x;
    cout<<nodesGreaterthenX(root,x);

    // cout<<sumofNode(root);
    delete root;
  }