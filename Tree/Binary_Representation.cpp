#include<bits/stdc++.h>
using namespace std;

struct Node
{
   int data;
   Node* left;
   Node* right;

   Node(int value)
   {
    data=value;
    left=right=nullptr;
   }
};

int main()
{
   Node* root=new Node(1);
   root->left=new Node(2);
   root->right=new Node(3);
   root->right->right=new Node(5);

   cout<<root->data<<" "<<root->right->right->data;
}