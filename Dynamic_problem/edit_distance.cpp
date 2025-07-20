#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll edit_distance(string &give,string &convert)
{
     vector<vector<ll>>dp(give.size()+1,vector<ll>(convert.size()+1,INT_MAX));

   for(int i=0; i<=give.size();i++)
      for(int j=0 ;j<=convert.size() ; j++)
      {
         if(i==0)dp[i][j]=j;
         else if(j==0)dp[i][j]=i;

         else if(give[i-1]==convert[j-1])
         {
            dp[i][j]=dp[i-1][j-1];            //if same char
         }
         else
         {
            dp[i][j]=min(dp[i][j-1]+1,        //insert
                          min(dp[i-1][j]+1,   //delete    
                          dp[i-1][j-1]+1));    //replace
         }
      }

   return dp[give.size()][convert.size()];
} 

void solve()
{
   string give,convert; cin>>give>>convert;
   cout<<edit_distance(give,convert)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

   //  int tt; cin>>tt;
   //  while(tt--)
       solve();
}
