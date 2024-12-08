#include<bits/stdc++.h>
using namespace std;

struct Node
{
 
   int val;
   Node* next;
   Node* pre;
};

int main()
{
   Node *head;
   Node* one;
   Node* two;
   Node* three;

   one=new Node();
   two=new Node();
   three=new Node();

  one->val=1;
  two->val=2;
  three->val=3;
  
  one->next=two;
  one->pre=NULL;

  two->next=three;
  two->pre=one;

  three->next=NULL;
  three->pre=two;

  head=one;

  while(head!=NULL)
  {
   cout<<head->val<<" ";
   head=head->next;
  }
  head=three;
  cout<<endl;

  while(head!=NULL)
  {
   cout<<head->val<<" ";
   head=head->pre;
  }
   return 0;   
}