#include<bits/stdc++.h>
using namespace std;

int maxi=0;

struct Tree
{
   int data;
   Tree* left;
   Tree* right;

   Tree(int x)
   {
    data=x;
    left=right=nullptr;
   }
};

class Solution
{
   public:
     int findHight(Tree* root)
     {
       if(root==nullptr)  return 0;

       int l=findHight(root->left);
       int r=findHight(root->right);

       return max(l,r)  +1 ;
     }

     void find_Diameter(Tree* root)
     {

        if(root==nullptr)  return;
       int l=findHight(root->left);
       int r=findHight(root->right);

       maxi=max(maxi,l+r);

       find_Diameter(root->left);
       find_Diameter(root->right);

     }
};

int main()
{
  Tree* root=new Tree(1);
  root->left=new Tree(2);
  root->right=new Tree(3);
  root->left->left=new Tree(4);
  root->left->right=new Tree(5);
  root->right->left=new Tree(6);
  root->right->right=new Tree(7);
  root->right->right->left=new Tree(8);
  root->right->right->right=new Tree(9);

  Solution sol;

  sol.find_Diameter(root);

  cout<<maxi<<endl;
}