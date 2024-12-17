//complexity->   all case -> o(n);

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
      
    int maxDepth(Tree* root)
    {
       if(root==nullptr)  return 0;

       int l=maxDepth(root->left);
       int r=maxDepth(root->right);

       maxi=max(maxi,l+r);

       return 1+max(l,r);
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
  root->right->right->left->left=new Tree(10);

   Solution sol;

   int height=sol.maxDepth(root);

   cout<<maxi<<endl;
 
}