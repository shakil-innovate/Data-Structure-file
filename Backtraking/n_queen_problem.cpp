//tutorial:https://www.youtube.com/watch?v=xFv_Hl4B83A&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=64

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll offset;
vector<bool>colmn,leftDiagonal,rightDiagonal;

void solve(ll row,vector<string>&board,vector<vector<string>>&solution)
{
    if(row==n)
    {
        solution.push_back(board);
        return;
    }

    for(int col=0;col<n ; col++)
    {
        if(!colmn[col] && !leftDiagonal[col-row+offset] && !rightDiagonal[row+col])
        {
            colmn[col]=leftDiagonal[col-row+offset]=rightDiagonal[row+col]=true;
            board[row][col]='Q';
            solve(row+1,board,solution);
            
            colmn[col]=leftDiagonal[col-row+offset]=rightDiagonal[row+col]=false;
            board[row][col]='.';            //backtracking
        }
    }
}

int main()
{
   cout<<"Enter the value of N:"<<endl;
   cin>>n;

   colmn.resize(n,false);
   leftDiagonal.resize(2*n,false);
   rightDiagonal.resize(2*n,false);
   offset=n-1;
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
