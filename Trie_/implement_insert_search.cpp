//L1. Implement TRIE | INSERT | SEARCH | STARTSWITH
// problem link:https://bit.ly/3n4m3Hu
#include<bits/stdc++.h>
using namespace std;
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
struct Node
{
   Node* links[26];

   bool flag=false;

   bool isContainKeys(char ch)
   {
     return links[ch-'a']!=nullptr;
   }

   void put(char ch,Node* node)
   {
     links[ch-'a']=node;
   }

   Node* get(char ch)
   {
     return links[ch-'a'];
   }

   void setEnd()
   {
     flag=true;
   }

   bool End()
   {
     return flag;
   }
};

class Trie {
  private:
     Node* root;

public:

    /** Initialize your data structure here. */
    Trie() {
      root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
      Node* node=root;

      for(int i=0;i<word.size();i++)
      {
        if(!node->isContainKeys(word[i]))
        {
          node->put(word[i],new Node);
        }
        node=node->get(word[i]);
      }
      node->setEnd();

    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
      Node* node=root;

      for(int i=0;i<word.length();i++)
      {
        if(node->isContainKeys(word[i])){
          node=node->get(word[i]);
        }
        else return false;
      }
      return node->End();

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
      Node* node=root;

      for(int i=0;i<word.length();i++)
      {
        if(node->isContainKeys(word[i]))
        {
          node=node->get(word[i]);
        }
        else return false;
      }

      return true;

    }
};