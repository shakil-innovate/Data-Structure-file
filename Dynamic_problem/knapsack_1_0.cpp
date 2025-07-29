problem link:https://atcoder.jp/contests/math-and-algorithm/tasks/dp_d?lang=en

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void shakil()
{
    ll n,weight;  cin>>n>>weight;
    vector<ll>w(n+1),p(n+1);

    for(int i=1;i<=n; i++) cin>>w[i]>>p[i];

    vector<vector<ll>>dp(n+1,vector<ll>(weight+1,0));

    for(int i=0 ; i<=n ;i++)
    {
        for(int j=0; j<=weight ; j++)
        {
          if(i==0 || j==0)  dp[i][j]=0;
          else if(w[i]<=j)
          {
            dp[i][j]=max(dp[i-1][j],p[i]+dp[i-1][j-w[i]]);
          }
          else
          {
            dp[i][j]=dp[i-1][j];
          }
        }
    }

    cout<<dp[n][weight]<<endl;

}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

 shakil();
}
