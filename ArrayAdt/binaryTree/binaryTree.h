template<typename T>
class BinaryTreeNode{
    public:
     int data;
     BinaryTreeNode<int>* left;
     BinaryTreeNode<int>* right;

    BinaryTreeNode(T data){
       this->data = data;
       left = NULL;
       right = NULL;
    } 

    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};