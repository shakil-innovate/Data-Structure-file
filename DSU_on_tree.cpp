// https://codeforces.com/problemset/problem/600/E

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define nl '\n'
#define f first
#define se second
#define vl vector<ll>
#define all(v) v.begin(),v.end()
#define vi vector<int>
ll INF=1e17;
ll mod=676767677;

template<typename T>

using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

//order_of_key(x)  => how many element smaller than x
//*st.find_by_order(k)  k th element 0 based index
//if(st.find(5) != st.end())		=> check exist
//st.order_of_key(x + 1)   => number of element

vl color;
vector<vl> g;
vl sz;
vl heavy;
unordered_map<ll,ll>freq;
ll cur_sum,cur_mx;
vl ans;

void calc(ll node,ll p){
  sz[node]=1;
  heavy[node]=-1;

  int mx_sz=0;

  for(auto child:g[node]){
    if(child==p)continue;

    calc(child,node);

    sz[node]+=sz[child];
    if(sz[child]>mx_sz){
      mx_sz=sz[child];
      heavy[node]=child;
    }
  }
}

void add(ll node,ll p){
  freq[color[node]]++;

  if(freq[color[node]]>cur_mx){
    cur_mx=freq[color[node]];
    cur_sum=color[node];
  }
  else if(freq[color[node]]==cur_mx){
    cur_sum+=color[node];
  }
}

void add_subtree(ll node,ll p){
  add(node,p);

  for(auto child:g[node]){
    if(child==p)continue;
    add_subtree(child,node);
  }
}

void rem_subtree(ll node,ll p){
  freq[color[node]]--;

  for(auto child:g[node]){
    if(child==p)continue;
    rem_subtree(child,node);
  }
}

void dfs(ll node,ll p,bool keep){
    
  for(auto child:g[node]){
    if(p==child || heavy[node]==child)continue;
    dfs(child,node,0);
  }

  if(heavy[node]!=-1){
    dfs(heavy[node],node,1);
  }

  add(node,p);

  for(auto child:g[node]){
    if(child==p || heavy[node]==child)continue;
    add_subtree(child,node);
  }

  ans[node]=cur_sum;

  if(!keep){
    rem_subtree(node,p);
    cur_mx=0;
    cur_sum=0;
  }
}

void shakil(){
  ll n;   cin>>n;
  color.clear();
  color.resize(n+1);
  g.clear();
  g.resize(n+1);
  sz.clear();
  sz.resize(n+1);
  heavy.clear();
  heavy.resize(n+1);
  ans.clear();
  ans.resize(n+1);

  cur_mx=0;cur_sum=0;

  for(ll i=1;i<=n;i++)  cin>>color[i];

  for(ll i=0;i<n-1;i++){
    ll u,v;   cin>>u>>v;
    g[u].pb(v);
    g[v].pb(u);
  }

  calc(1,0);
  dfs(1,0,0);

  for(ll i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<nl;

}


int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif

  ll tt=1;
  // cin>>tt;

  for(ll i=1;i<=tt;i++){
    // cout<<"Case "<<i<<": ";
    shakil();
  }
}
