#include<bits/stdc++.h>
using namespace std;

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
    
   vector<int> iterative_preorder_traversal(Tree* root)
   {
    vector<int>ans;
    stack<Tree*>st;
    st.push(root);

    while(!st.empty())
    {
       Tree* node=st.top();
       st.pop();
       ans.push_back(node->data);

       if(node->right!=nullptr)   st.push(node->right);
       if(node->left!=nullptr)    st.push(node->left);

    }

    return ans;
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

  Solution sol;

  vector<int>ans=sol.iterative_preorder_traversal(root);

  for(auto it:ans)
  {
    cout<<it<<" ";
  }

 
}