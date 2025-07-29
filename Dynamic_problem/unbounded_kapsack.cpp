#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=100000007;

ll n;

void shakil()
{
    ll n,k; cin>>n>>k;
    vector<ll>v(n);

    for(auto &it:v) cin>>it;

    vector<vector<ll>>dp(n+1,vector<ll>(k+1,0));

    for(int i=0; i<n  ; i++)  dp[i][0]=1;

    sort(v.begin(),v.end());

    for(int i=0; i<n ; i++)
    {
      for(int j=1; j<=k ; j++)
      {

        if(i==0)
        {
          if((j-v[i])>=0)
        {
           dp[i][j]=dp[i][j-v[i]];
        }
          else dp[i][j]=0;
        }

      else
      {
        if((j-v[i])>=0)
        {
           dp[i][j]=(dp[i-1][j]+dp[i][j-v[i]])%mod;
        }
        else dp[i][j]=dp[i-1][j];
      }
    }
    }

    cout<<dp[n-1][k]<<endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int tt; cin>>tt;
 for(int i=1;i <=tt ; i++)
 {
  cout<<"Case "<<i<<": ";
  shakil();
 }
  
}
