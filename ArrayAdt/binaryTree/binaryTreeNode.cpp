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

void printTreeLvlwise(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    // cout<<root->data<<":";
    queue<BinaryTreeNode<int>*> pendingNode;
    pendingNode.push(root);
    while(pendingNode.size()!=0){
        BinaryTreeNode<int>* front = pendingNode.front();
        pendingNode.pop();
        cout<<front->data<<":";
        if(front->left!=NULL){
            cout<<"L"<<front->left->data<<",";
            pendingNode.push(front->left);
        }
        if(front->right!=NULL){
            cout<<"R"<<front->right->data<<endl;
            pendingNode.push(front->right);
        }
    }
    // printTreeLvlwise(root->left);
    // printTreeLvlwise(root->right);
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

int numNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1+numNodes(root->left)+numNodes(root->right);
}

bool isPresent(BinaryTreeNode<int>* root , int x){
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }

    bool left = isPresent(root->left , x);
    if(left){
        return true;
    }
    bool right = isPresent(root->right, x);
        if(right){
            return true;
        }
}

int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int lH=height(root->left);
    int rH=height(root->right);
    if(lH<rH){
        return rH+1;
    }else{
        return lH+1;
    }
}

void inOrder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode<int>* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int heights(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return 1+(max(height(root->left),height(root->right)));
}

int diameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int option1 = height(root->left)+height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1 , max(option2,option3));
}

pair<int,int> heightDiameter(BinaryTreeNode<int>* root){
    if(root==NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;
    
    int height = 1+max(lh,rh);
    int diameter = max(lh+rh , max(rd,ld));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

pair<int,int> minMax(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int,int> p;
        p.first = INT32_MIN;
        p.second = INT32_MAX;
        return p;
    }
    pair<int,int> leftAns = minMax(root->left);
    pair<int,int> rightAns = minMax(root->right);
    int lMin = leftAns.second;
    int lmax = leftAns.first;
    int Rmin = rightAns.second;
    int Rmax = rightAns.first;

    int maximum = max(root->data,max(lmax,Rmax));
    int minimum = min(root->data,min(lMin,Rmin));

    pair<int,int> p;
    p.first = maximum;
    p.second = minimum;
}

int SumofNodes(BinaryTreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    return root->data+SumofNodes(root->left)+SumofNodes(root->right);
}

bool isBalanced(BinaryTreeNode<int>* root){
    if(root==NULL){
        return true;
    }
    int leftHeihght = heights(root->left);
    int rightHeight = heights(root->right);
    if(leftHeihght-rightHeight > 1 || rightHeight-leftHeihght >1){
        return false;
    }
    bool a = isBalanced(root->left);
    bool b = isBalanced(root->right);
    if(a&&b){
        return true;
    }
    return false;
}

void lvlordertraversal(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    BinaryTreeNode<int>* current;
    while(q.size()>1){
        current = q.front();
        q.pop();
        if(current== NULL){
            cout<<endl;
            // q.pop();
            q.push(NULL);
        }else{
        cout<<current->data<<",";
        if(current->left!=NULL){
            q.push(current->left);
        }
        if(current->right!=NULL){
            q.push(current->right);
        }
        }
        
    }
}

BinaryTreeNode<int>* removeLeafnode(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
}

int main(){
    BinaryTreeNode<int> *root = takeInputlvlwise();
    // printTreeLvlwise(root);
    lvlordertraversal(root);
    cout<<SumofNodes(root);
}
