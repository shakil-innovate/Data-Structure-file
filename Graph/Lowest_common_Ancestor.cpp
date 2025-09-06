//--------------------------------------//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define nl '\n'
const ll mod=1e9+7;
const ll INF=1e9;
#define vi vector<ll>
#define vii vector<vi>
#define f first
#define s second

ll add(ll a,ll b){ return ((a%mod + b%mod)+ mod ) % mod;}
ll sub(ll a,ll b){ return ((a%mod - b%mod)+mod)% mod;}
ll mul(ll a,ll b){ return ((a%mod) * (b%mod))%mod ;}
ll power(ll a, ll b){ll res=1; a%=mod;while(b > 0){if(b & 1)res=(res*a) %mod; a=(a*a)%mod;b=b>>1;}return res;}
ll inv(ll a){return power(a,mod-2);}
//---------------------------------------//
const ll N=1e5;
const ll LOG=20;
vector<vector<ll>>g(N);
ll depth[N];
ll up[N][LOG];


void dfs(ll src)
{
  for(auto child:g[src])
  {
    depth[child]=depth[src]+1;
    up[child][0]=src;
    for(ll j=1;j<LOG;j++)
    {
      up[child][j]=up[up[child][j-1]][j-1];
    }
    dfs(child);
  }
}

ll lca(ll a,ll b)
{
  if(depth[a]<depth[b])
  {
    swap(a,b);
  }
 
   ll k=depth[a]-depth[b];
   
   for(int j=0;j<LOG;j++)
   {
    if(k & (1<<j))a=up[a][j];
   }

   if(a==b)return a;
   
  for(int j=LOG-1;j>=0;j--)
  {
    if(up[a][j]!=up[b][j])
    {
      a=up[a][j],b=up[b][j];
    }
  }

  return up[a][0];
}

void shakil()
{
  ll n; cin>>n;
  
  for(ll v=0;v<n;v++)
  {
      ll cnt; cin>>cnt;
      while(cnt--)
      {
        ll child; cin>>child;
        g[v].push_back(child);
      }
  }

  dfs(0);

  ll q; cin>>q;
  while(q--)
  {
      ll u,v; cin>>u>>v;
      cout<<lca(u,v)<<nl;
  }
}

int  main()
{
   ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tt=1;
    // cin>>tt;

    for(ll i=1;i<=tt;i++)
    {
      shakil();
    }
}
