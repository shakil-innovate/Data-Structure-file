//tutorial:https://www.youtube.com/watch?v=xFv_Hl4B83A&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=64

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

bool isSafe(vector<string>&board,ll row,ll col)
{
    // check colmn
    for(int i=0;i<row ; i++)
    {
        if(board[i][col]=='Q')
           return false;
    }

    //check top-lef diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--,j--)
    {
        if(board[i][j]=='Q')
          return false;
    }

    //check top-right diagonal
    for(int i=row-1,j=col+1;i>=0 && j<n ; i--,j++)
    {
        if(board[i][j]=='Q')
           return false;
    }

   return true;
}

void solve(ll row,vector<string>&board,vector<vector<string>>&solution)
{
    if(row==n)
    {
        solution.push_back(board);
        return;
    }

    for(int col=0;col<n ; col++)
    {
        if(isSafe(board,row,col))
        {
            board[row][col]='Q';
            solve(row+1,board,solution);
            board[row][col]='.';            //backtracking
        }
    }
}

int main()
{
   cout<<"Enter the value of N:"<<endl;
   cin>>n;

   vector<string>board(n,string(4,'.'));
   vector<vector<string>>solution;
   
   solve(0,board,solution);

   cout<<"Total Solution : "<<solution.size()<<endl;

   for(auto &sol:solution)
   {
      for(auto &row:sol)
        cout<<row<<endl;
        cout<<endl;
   }


}
