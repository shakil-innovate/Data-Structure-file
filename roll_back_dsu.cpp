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

class DisjointSet{
  public:

  vl sz,par;
  vector<tuple<ll,ll,ll>>history;

  DisjointSet(ll n){
    sz.resize(n+1,1);
    par.resize(n+1);

    for(ll i=1;i<=n;i++)par[i]=i;
  }

  ll findParent(ll u){
    while(par[u]!=u){
      u=par[u];
    }
    return u;
  }

  void unionSet(ll u,ll v){
    ll pu=findParent(u),pv=findParent(v);

    if(pu==pv){
      history.pb({-1,-1,-1});
      return;
    }

    if(sz[pu]<sz[pv]) swap(pu,pv);
    history.pb({pv,pu,sz[pu]});

    par[pv]=pu;
    sz[pu]+=sz[pv];
  }

  ll save(){
    return (ll)history.size();
  }

  void rollback(ll checkPoint){
    while(history.size()>checkPoint){
      auto [pv,pu,old_sz]=history.back();
      history.pop_back();

      if(pv==-1)continue;
      sz[pu]=old_sz;
      par[pv]=pv;
    }
  }

  bool connected(ll u,ll v){
    return findParent(u)==findParent(v);
  }
};

vector<vector<pair<ll,ll>>>seg(2000005);

void seg_add(ll node,ll l,ll r,ll ql,ll qr,pair<ll,ll>edge){
  if(qr<l || ql>r)return;
  if(l>=ql && r<=qr){
    seg[node].pb(edge);
    return;
  }

  else{
    ll mid=(l+r)/2;
    seg_add(2*node,l,mid,ql,qr,edge);
    seg_add(2*node+1,mid+1,r,ql,qr,edge);
  }
}

ll M_op;
vl op_type,op_x,op_y;
vector<char>answer;

void dc(ll node,ll l,ll r,DisjointSet &dj){
  ll checkPoint=dj.save();

  for(auto [u,v]:seg[node]){
    dj.unionSet(u,v);
  }

  if(l==r){
    if(op_type[l]==2){
      answer.pb((dj.connected(op_x[l],op_y[l])?'Y':'N'));
    }
  }
  else{
    ll mid=(l+r)/2;
    dc(2*node,l,mid,dj);
    dc(2*node+1,mid+1,r,dj);
  }
  dj.rollback(checkPoint);

}

void shakil(){
  ll n;   cin>>n>>M_op;
  op_type.resize(M_op);
  op_x.resize(M_op);
  op_y.resize(M_op);

  for(ll i=0;i<M_op;i++)cin>>op_type[i]>>op_x[i]>>op_y[i];

  map<pair<ll,ll>,ll>active;

  for(ll i=0;i<M_op;i++){
    ll u=op_x[i],v=op_y[i];
    if(u>v)swap(u,v);

    pair<ll,ll>e={u,v};

    if(op_type[i]==0){
      active[e]=i;
    }
    else if(op_type[i]==1){
      ll start=active[e];
      active.erase(e);
      if(start<=i-1){
        seg_add(1,0,M_op-1,start,i-1,e);
      }
    }
  }

  for(auto &[e,start]:active){
    seg_add(1,0,M_op-1,start,M_op-1,e);
  }

  DisjointSet dj(n);
  dc(1,0,M_op-1,dj);

  for(auto ch:answer)cout<<ch<<nl;
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
