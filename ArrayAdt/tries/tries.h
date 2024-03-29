#include<iostream>
using namespace std;
#include"trieNode.h"

class Tries{
 public:   
 TrieNode *root;

 Tries(){
    root = new TrieNode('\0');
 }

 void insert(TrieNode *root, string Word){
    //base case
    if(Word.size()==0){
        root->isTerminal = true;
        return;
    }

    int index = Word[0]-'a';
    TrieNode *child;
    if(root->children[index]!=NULL){
      child = root->children[index];
    }else{
       child = new TrieNode(Word[0]);
       root->children[index]=child;
    }
    //recursive call
      insert(child,Word.substr(1));
 }

 bool Search(TrieNode *root , string Word){
    if(Word.size()==0){
        if(root->isTerminal == true){
            return true;
        }else{
            return false;
        }
    }
    int index = Word[0] - 'a';
    TrieNode *child;
    if(root->children[index]!=NULL){
        child = root->children[index];
        return Search(child,Word.substr(1));
    }else{
        return false;
    }
 }

 void removeWord(TrieNode *root , string Word){
    if(Word.size()==0){
        root->isTerminal = false;
        return;
    }
    int index = Word[0]-'a';
    TrieNode *child;
    if(root->children[index]!=NULL){
       child = root->children[index];
    }else{
       return;
    }
     removeWord(child , Word.substr(1));

     if(child->isTerminal == false){
        for(int i=0 ;i<26 ;i++){
            if(child->isTerminal!=NULL){
                return;
            }
        }
        delete child;
        root->children = NULL;
     }
 }

     //for user
     void insert(string Word){
       insert(root , Word);
     }

     bool Search(string Word){
        Search(root , Word);
     }
};