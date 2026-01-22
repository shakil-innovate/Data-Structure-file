//problem_link:https://atcoder.jp/contests/abc284/tasks/abc284_c

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'

class DisjoinSet{
  public:
  vector<ll>sz,parent;

  DisjoinSet(ll n){
   sz.resize(n+1,1);
  parent.resize(n+1);

  for(ll i=1;i<=n;i++)    
    parent[i]=i;
  }

  ll findParent(ll node){
   if(node==parent[node])return node;
   return parent[node]=findParent(parent[node]);
  }

  void unionSet(ll u,ll v){
   ll pu=findParent(u),pv=findParent(v);

   if(pu==pv)  return;
   if(sz[pu] > sz[pv]){
    parent[pv]=pu;
    sz[pu]+=sz[pv];
   }
  else{
    parent[pu]=pv;
    sz[pv]+=sz[pu];
  } 
 }
};

void shakil(){
    ll n,m;     cin>>n>>m;

    DisjoinSet dj(n);

    for(ll i=1;i<=m;i++){
        ll u,v; cin>>u>>v;
        dj.unionSet(u,v);
    }
    set<ll>st;

    for(ll i=1;i<=n;i++){
        st.insert(dj.findParent(i));
    }
    cout<<st.size()<<nl;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);

    ll tt=1;
    // cin>>tt;

    while(tt--){
        shakil();
    }
}
