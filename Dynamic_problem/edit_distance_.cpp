//--------------------------------------//
#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef long long ll;

typedef double db;
#define pb push_back 
#define nl '\n'
const ll mod=998244353;
const ll INF=1e9;
#define vi vector<ll>
#define vii vector<vi>
#define pb push_back
#define f first
#define s second

ll add(ll a,ll b){ return ((a%mod + b%mod)+ mod ) % mod;}
ll sub(ll a,ll b){ return ((a%mod - b%mod)+mod)% mod;}
ll mul(ll a,ll b){ return ((a%mod) * (b%mod))%mod ;}
ll power(ll a, ll b){ll res=1; a%=mod;while(b > 0){if(b & 1)res=(res*a) %mod; a=(a*a)%mod;b=b>>1;}return res;}
ll inv(ll a){return power(a,mod-2);}
//---------------------------------------//

void shakil()
{
    string s,t;   cin>>s>>t;
    vector<vi>dp(t.size()+1,vi(s.size()+1,-1));

    for(ll i=0;i<=t.size();i++)
    {
      for(ll j=0;j<=s.size();j++)
      {

          
          if(i==0)dp[i][j]=j;
          else if(j==0)dp[i][j]=i;
          else if(t[i-1]==s[j-1])dp[i][j]=dp[i-1][j-1];

          else dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
      }
    }

    cout<<dp[t.size()][s.size()]<<nl;

    vector<string>operation;
    ll i=t.size(),j=s.size();

    while(i>0 || j>0)
    {
      if(i>0 && j>0 && t[i-1]==s[j-1])
      {
        char ch=t[i-1];
        operation.pb("take same ");
        i--,j--;
      }
      else if(i>0 && j>0 && dp[i][j]==1+dp[i-1][j-1])
      {
        operation.pb("replace");
        i--,j--;
      }
      else if(i>0 && dp[i][j]==1+dp[i-1][j])
      {
        operation.pb("insert");
        i--;
      }
      else operation.pb("delete"),j--;
    }

    reverse(operation.begin(),operation.end());

    for(ll i=0;i<operation.size();i++)
    {
      cout<<i<<" ";
      cout<<operation[i]<<nl;
    }
    cout<<nl;
}

int  main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    ll tt=1;
    // cin>>tt;

    for(ll i=1;i<=tt;i++)
    {
      shakil();
    }
}
