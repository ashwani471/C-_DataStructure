#include<iostream>
using namespace std;
#include"linkedListClass.cpp"

Node *takeInput(){
    int data;
    cout<<"Enter data:";
    cin>>data;
    Node* head = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
        }else{
            Node *temp = head;
            while(temp != NULL){
                temp=temp->next;
            }
            temp->next = newNode;
        }
        cout<<"enter data:";
        cin>>data;
    }
    return head;
}

Node *takeInput_better(){
    int data;
    cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL){
            head = newNode;
        }else{
            // Node *temp = head;
            // while(temp != NULL){
            //     temp=temp->next;
            // }
            // temp->next = newNode;
            tail->next = newNode;
            tail = newNode;
            
        }
        cin>>data;
    }
    return head;
}

void print(Node *head){
   while (head!=NULL)
   {
     cout<<head->data<<" ";
     head=head->next;
   }
   
}

int length(Node *head){
    int len = 0;
    while(head != NULL){
        len = len+1;
    }
    return len;
}

void printithNode(Node *head , int n){
    int cnt = 0;
    while(head!=NULL){
        if(cnt == n){
            cout<<head->data;
        }else{
            head=head->next;
        }
    }
}

Node* insertNode(Node *head , int i , int data){
    Node *newnode = new Node(data);
    Node *temp = head;
    int count = 0;

      if(i==0){
        newnode->next = head;
        head = newnode;
        return head;
    }

    while(temp!=NULL && count<i-1){
        temp = temp->next;
        count++;
    }
    if(temp != NULL){
    newnode->next = temp->next;
    temp->next = newnode;
    }
    return head;
}

Node *deleteNode(Node *head , int data , int i){
    Node *temp = head;
    int count =0;

    if(i==0){
        Node *newHead = head->next;
        return newHead;
    }

    while(count<i){
        temp = temp->next;
    }
    Node *a = temp->next;
    Node *b = a->next;
    temp->next = b;
    return head;
}

int main(){
    // Node n1(1);
    // Node n2(2);

    // n1.next = &n2;
    // cout<<n1.data<<" "<<n2.data;
    // cout<<n1.next;
   
	// int t;
	// cin >> t;
	// while (t--)
	// {
	// 	Node *head = takeInput_better();
	// 	// cout << length(head) << endl;
    //     int pos;
    //     cin>>pos;
    //     printithNode(head,pos);
	// }
	// return 0;

    Node *head = takeInput_better();
    print(head);
    int i,data;
    cin>>i>>data;
    head = insertNode(head , i, data);
    print(head);


}