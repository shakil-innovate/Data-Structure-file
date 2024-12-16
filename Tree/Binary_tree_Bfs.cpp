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
    
    vector<vector<int>>levelOrder(Tree* root)
    {
        vector<vector<int>>ans;

        if(root==nullptr)   return ans;

        queue<Tree*>q;
        q.push(root);

        while(!q.empty())
        {
            vector<int>level;
            int size=q.size();

            for(int i=0;i<size;i++)
            {
                Tree* node=q.front();
                q.pop();

                if(node->left!=nullptr)   q.push(node->left);
                if(node->right!=nullptr)   q.push(node->right);

                level.push_back(node->data);
            }
            ans.push_back(level);
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

  vector<vector<int>>result=sol.levelOrder(root);

  int i=1;
  for(auto level:result)
  { 
    cout<<"level : "<<i++<<endl;

      for(auto it:level)
      {
        cout<<it<<" ";
      }
      cout<<endl;
  }
}