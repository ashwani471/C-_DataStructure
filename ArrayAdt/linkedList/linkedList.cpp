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
        // cout<<"enter data:";
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
            tail= newNode;
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

int lengthLLRec(Node *head){
    Node *temp = head;
    if(temp->next == NULL){
        return 1;
    }
    int len = lengthLLRec(head->next);
    return len+1;
}

Node *insertNodeRec(Node *head,int i , int data){
Node *temp = head;
Node *newNode = new Node(data);
if(head == NULL ){
  return head;
}
if(i == 0){
    newNode->next=head;
    head=newNode;
    return head;
}
temp = insertNodeRec(head->next,i-1,data);
head->next = temp;
return head;
}

int findNodeLL(Node *head , int n){
    Node *temp = head;
    int cnt =0;
    while(temp!=NULL){
        if(temp->data == n){
            return cnt;
        }temp=temp->next;
        cnt++;
    }
    return -1;
}

Node *appendLast(Node *head , int n){
    Node *temp = head;

    int cnt =0;
    while(cnt<n){
        Node *a = head;
        Node *b=head->next;
        while(temp->next!=NULL){
            temp=temp->next;
            if(temp->next == NULL){
                temp->next=a;
                head=b;
                a->next = NULL;
                temp=b;
            }
        }
        cnt++;
        delete a;
        delete b;
    }
    return temp;
}

Node *appendLast2(Node *head , int n){
    Node *temp = head;
    int cnt=1;
    if(n==0){
        return head;
    }
    while(cnt<n){
        cnt++;
        temp=temp->next;
    }
    Node *newHead = temp->next;
    temp->next = NULL;

    Node *temp1 = newHead;
    while(temp1->next!=NULL){
        temp1 = temp1->next;
    }
    temp1->next = head;
    return newHead;
    
}

Node *removeDuplicate(Node *head){
    Node *t1 = head;
    Node *t2 = head->next;
    while(t2!=NULL){
        if(t1->data == t2->data){
            t2=t2->next;
        }
        else{
            t1->next = t2;
            t1 = t1->next;
            t2 = t2->next;
        }
    }
    t1->next=NULL;
    return head;

}

void reverseLL(Node *head){
    Node *temp = head;
    if(temp->next == NULL){
        cout<<temp->data;
    }
     reverseLL(temp->next);
}

Node *midLL(Node *head){
    Node *slow = head;
    Node *fast = head;
    while (fast->next!=NULL && fast!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node *merge2LL(Node *head1 , Node *head2){
    Node *fHead = NULL;
    Node *fTail = NULL;
    if(head1->data < head2->data){
        Node *fHead = head1;
        Node *fTail = head1;
        head1 = head1->next;
    }else{
        Node *fHead = head2;
        Node *fTail= head2;
        head2 = head2->next;
    }
    while(head1!=NULL && head2!=NULL){
        if(head1->data <= head2->data){
            fTail->next=head1;
             fTail = head1;
            head1=head1->next;
           
        }else{
            fTail->next = head2;
             fTail = head2;
            head2 = head2->next;
            // fHead->next = head1;
           
        }
    }
    if(head1!=NULL && head2==NULL){
        while(head1!=NULL){
            fTail=head1;
            head1 = head1->next;
        }
        head1->next=NULL;

    }
    else{
         while(head2!=NULL){
            fTail=head2;
            head2 = head2->next;
        }
        head2->next=NULL;
    }
    return fHead;
}

Node *mergeSort(Node *head){
    if(head == NULL || head->next == NULL){
      return head;
    }
    Node *middle = midLL(head);
    Node *p = middle->next;
    middle->next = NULL;

    Node *firstLL = mergeSort(head);
    Node *secondLL = mergeSort(p);

    Node *sortedList=merge2LL(firstLL,secondLL);
    return sortedList;

}

Node *reverseLL2(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *smallAns = reverseLL2(head->next);

    Node *temp = smallAns;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next=head;
    head->next=NULL;
    return smallAns;
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

    Node *head1 = takeInput_better();
    Node *head2 = takeInput_better();
    // reverseLL(head);
    // midLL(head);
    Node *fh=merge2LL(head1,head2);
    // cout<<mid;
    // print(head);
    // int i,data;
    // cin>>i>>data;
    // int n;
    // cout<<"How many elements you want to shift:";
    // cin>>n;
    // head = insertNode(head , i, data);
    // head = appendLast2(head,n);
    // head = removeDuplicate(head);
    print(fh);


}