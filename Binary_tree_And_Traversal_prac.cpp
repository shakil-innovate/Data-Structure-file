#include<bits/stdc++.h>
using namespace std;

struct tree
{
   int data;
   tree* left;
   tree* right;
};

struct tree *newTree(int data)
{
   struct tree *tree=(struct tree *)malloc(sizeof(struct tree));

   tree->data=data;
   tree->left=NULL;
   tree->right=nullptr;

   return (tree);
}

void TraversePreorder(tree* temp)
{
  if(temp!=nullptr)
  {
    cout<<temp->data<<" ";
    TraversePreorder(temp->left);
    
    TraversePreorder(temp->right);
  }
  
}

void TraverseInorder(tree* temp)
{
  if(temp!=nullptr)
  {
    TraverseInorder(temp->left);
    cout<<temp->data<<" ";
    TraverseInorder(temp->right);
  }
 
}

void TraversePostorder(tree* temp)
{
  if(temp!=nullptr)
  {
    TraversePostorder(temp->left);
    
    TraversePostorder(temp->right);
    cout<<temp->data<<" ";
  }
  
}

int main()
{
  tree* root=newTree(1);
  root->left=newTree(2);
  root->right=newTree(3);
  root->left->left=newTree(4);

  cout<<"pre_order:"<<endl;
  TraversePreorder(root);cout<<endl;
  cout<<"Post_order:"<<endl;
  TraversePostorder(root);cout<<endl;
  cout<<"In_order:"<<endl;
  TraverseInorder(root);cout<<endl;
  

}