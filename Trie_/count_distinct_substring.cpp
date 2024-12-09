//L4. Number of Distinct Substrings in a String | Trie
//problem link:https://bit.ly/3ocRQW0
#include<bits/stdc++.h>
using  namespace std;

struct Node
{
    Node* links[26];
    
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }

    bool isContainKeys(char ch)
    {
        return links[ch-'a']!=nullptr;
    }

    Node* getlinks(char ch)
    {
        return links[ch-'a'];
    }


};


int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int ans=0;
    Node* root=new Node();

    for(int i=0;i<s.length();i++)
    {
        Node* node=root;
        for(int j=i;j<s.length();j++)
        {
          if(!node->isContainKeys(s[j]))
          {
            ans++;
            node->put(s[j],new Node());
          }
          node=node->getlinks(s[j]);
        }
    }

    return ans+1;
}