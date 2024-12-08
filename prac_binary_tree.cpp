#include<bits/stdc++.h>
using namespace std;
struct tree
{
    int val;
    tree *left;
    tree *right;
};

tree *NewTree(int data)
{
    tree *node=new tree();
    node->val=data;
    node->left=NULL;
    node->right=NULL;
}

void postorder(tree *temp)
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);

        cout<<temp->val<<" ";
    }
}

int main()
{
  tree *root=NewTree(1);
  root->left=NewTree(2);
  root->right=NewTree(3);
  root->left->left=NewTree(4);
  root->left->right=NewTree(5);

  postorder(root);
  cout<<endl;
}