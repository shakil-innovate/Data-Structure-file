//for trie insert,count word,count prefix,erase
//problem link:https://bit.ly/3qwT4OL
//at code360

#include<bits/stdc++.h>
using namespace std;

struct Node
{
  Node* links[26];
  int cntEndWith=0;
  int cntPrefix=0;

  bool isContainKeys(char ch)
  {
    return links[ch-'a']!=nullptr;
  }

  Node* get(char ch)
  {
    return links[ch-'a'];
  }

  void put(char ch,Node* node)
  {
    links[ch-'a']=node;
  }

  void increaseEnd()
  {
    cntEndWith++;
  }

  void incresePref()
  {
    cntPrefix++;
  }

  void deleteEnd()
  {
    cntEndWith--;
  }

  void resucePref()
  {
    cntPrefix--;
  }
  
  int getEnd()
  {
    return cntEndWith;
  }

  int getPref()
  {
    return cntPrefix;
  }

};

class Trie
{
  private:
        Node* root;

  public:
       Trie();
       void insert(string word);
       int countWordsEqualTo(string word);
       int countWordsStartingWith(string word);
       void erase(string word);
};

Trie::Trie()
{
    root=new Node();
}

void Trie::insert(string word)
 {
   Node* node=root;

   for(int i=0;i<word.length();i++)
   {
     if(!node->isContainKeys(word[i]))
     {
        node->put(word[i],new Node());
     }
     node=node->get(word[i]);
     node->incresePref();
   }
   node->increaseEnd();
 }

 int Trie::countWordsEqualTo(string word)
 {
    Node* node=root;

    for(int i=0;i<word.length();i++)
    {
        if(node->isContainKeys(word[i]))
        {
            node=node->get(word[i]);
        }
        else return 0;
    }
    return node->getEnd();
 }

 int Trie::countWordsStartingWith(string word)
 {
    Node* node=root;

    for(int i=0;i<word.length();i++)
    {
        if(node->isContainKeys(word[i]))
        {
            node=node->get(word[i]);
        }
        else return 0;
    }
    return node->getPref();
 }

 void Trie::erase(string word)
 {
    Node* node=root;

   for(int i=0;i<word.length();i++)
   {
      if(node->isContainKeys(word[i]))
      {
        node=node->get(word[i]);
        node->resucePref();
      }
      else return;
   }
   node->deleteEnd();
 }