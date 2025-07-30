problem link:https://vjudge.net/contest/732417#problem/G

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
   ll n,m; cin>>n>>m;
   vector<ll>A(n),C(n);

   for(auto &it:A)cin>>it;
   for(auto &it:C)cin>>it;

   vector<bool>dp(m+1,0);
   dp[0]=1;

   for(int i=0;i<n ; i++)
   {   
   vector<ll>used(m+1,0);
     for(int j=A[i];j<=m ; j++)
     {
        if(!dp[j] && dp[j-A[i]] && used[j-A[i]]<C[i])
        {
            dp[j]=1;
            used[j]=used[j-A[i]]+1;
        }
     }
   }

   ll ans=0;
   for(int i=1; i<=m ;i++)
   {
    if(dp[i]==1)ans++;
   }

   cout<<ans<<endl;

}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   ll tt;   cin>>tt;

   for(int i=1; i<=tt;i++)
   {
    cout<<"Case "<<i<<": ";
    solve();
   }
    
}
