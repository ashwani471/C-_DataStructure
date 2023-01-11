#include<iostream>
#include<cstring>
using namespace std;
// #include "stackClassusingArray.cpp"
#include "stackusingLL.h"
#include "QueueUsingArray.h"
#include<queue>

bool checkBalanced(char str[]){
  int len = strlen(str);
  cout<<len;
  stackLL<char> s;
  for(int i=0 ; i<len ;i++){
    if(str[i]=='{' || str[i]=='(' || str[i]== '['){
        s.push(str[i]);
    }
    else if(str[i]=='}'){
        if(s.top() == '{'){
            s.pop();
        }
    }else if(str[i]==')'){
        if(s.top() == '(' ){
            s.pop();
        }
    }else if(str[i]==']'){
        if(s.top()=='['){
            s.pop();
        }
    }
  }
  if(s.isEmpty()){
    return true;
  }else{
    return false;
  }
}

// ------------------- Reverse Stack -------------------//

void transfer(stackLL<int> &input , stackLL<int> &extra , int n){
 for(int i=0;i<n;i++){
    int temp = input.top();
    input.pop();
    extra.push(temp);
 }
}

void reverseStack(stackLL<int> &input, stackLL<int> &extra , int n) {
   for(int i =0 ;i<n ;i++){
    int temp = input.top();
    input.pop();

    transfer(input,extra,n-i-1);
    input.push(temp);
    transfer(extra,input,n-i-1);
   }

}

void reverseQueue(queue<int> &q){
    if(q.empty()){
        return;
    }
    int front = q.front();
    q.pop();
    reverseQueue(q);
    q.push(front);
}

bool checkredundant(char *str , int n){
    stackLL<int> st;
     for(int i= 0 ; i<n ;i++){
       if(str[i]==')'){
          char top = st.top();
        //   st.pop();
          if(top == '('){
            return false;
          }
          while(!st.isEmpty()){
            bool oprtrFnd=false;
            while(top!='('){
                if(top=='+'||top=='-'||top=='*'||top=='/'){
                    oprtrFnd=true;
                }
                st.pop();
                top=st.top();
            }
            if(oprtrFnd==false){
                return false;
            }
            else{
                oprtrFnd=false;
                st.pop();
            }
          }
       }

       else{
        st.push(str[i]);
       }
     }
     return false;
}

int main() {
    stackLL<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++) {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra , size);

    while (!input.isEmpty()) {
        cout << input.top() << " ";
        input.pop();
    }

    queue<int> q;
    int size;
    cin>>size;

    for(int i =0,val ;i<size ;i++){
        cin>>val;
        q.push(val);
    }

    reverseQueue(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    cout<<endl;

    // int n;
    // QueueArray<int> q,p;
    // q.enqueue(10);
    // q.enqueue(20);
    // q.enqueue(30);
    // q.enqueue(40);
    // q.enqueue(50);

    // cout<<"Enter size:";
    // cin>>n;

    // string str;
    // cin>>str;

    // int len = strlen(str);
    
    // cout<<checkBalanced(str);

    // stackLL<int> s,p;
    // s.push(10);
    // s.push(20);
    // s.push(30);
    // s.push(40);
    // s.push(50);

    // cout<<s.top()<<endl;
    // cout<<s.getSize()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.pop()<<endl;
    // cout<<s.getSize()<<endl;
    // cout<<s.isEmpty()<<endl;

}