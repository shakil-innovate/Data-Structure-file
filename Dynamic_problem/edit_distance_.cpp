problem link:https://vjudge.net/contest/732417#problem/O

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void shakil()
{
  string s,t; cin>>s>>t;
  vector<vector<ll>>dp(s.size()+1,vector<ll>(t.size()+1,INT_MAX));
  
  for(int i=0 ; i<=s.size(); i++)
  {
    for(int j=0; j<=t.size();j++)
    {
      if(i==0)dp[i][j]=j;
      else if(j==0) dp[i][j]=i;

      else
      {
        if(s[i-1]==t[j-1])
        {
          dp[i][j]=dp[i-1][j-1];
        }
        else
        {
            dp[i][j]=min(dp[i][j-1],{min(dp[i-1][j],dp[i-1][j-1])})+1;
        }
      }


    }
  }

  cout<<dp[s.size()][t.size()]<<endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // int tt; cin>>tt;
  // while(tt--)
  shakil();
}
