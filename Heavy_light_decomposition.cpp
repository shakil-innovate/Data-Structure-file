//problem:https://cses.fi/problemset/task/1138/

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

vector<vl>g;
vl arr;

void shakil(){
  ll n,q;   cin>>n>>q;

  g.resize(n+1);
  arr.resize(4*n+5,0);
  vl heavy(n+1,-1);
  vl depth(n+1,0);
  vl sz(n+1,0),index,parent(n+1);

  vl value(n+1);

  for(ll i=1;i<=n;i++)  cin>>value[i];
  for(ll i=0;i<n-1;i++){
    ll u,v;   cin>>u>>v;
    g[u].pb(v);
    g[v].pb(u);
  }

  function<void(ll,ll,ll)>build=[&](ll l,ll h,ll pos)->void{
      if(l==h){
        arr[pos]=value[index[l]];
      }
      else{
        ll mid=(l+h)/2;
        build(l,mid,pos*2);
        build(mid+1,h,pos*2+1);
        arr[pos]=arr[pos*2]+arr[pos*2+1];
      }
  };

  function<void(ll,ll,ll,ll,ll)>update=[&](ll l,ll h,ll ind,ll val,ll pos)->void{
    if(l==h){
      arr[pos]=val;
    }
    else{
      ll mid=(l+h)/2;

      if(ind<=mid)update(l,mid,ind,val,pos*2);
      else update(mid+1,h,ind,val,pos*2+1);

      arr[pos]=arr[pos*2]+arr[pos*2+1];
    }
  };

  function<void(ll,ll,ll)>dfs=[&](ll node,ll p,ll d)->void{
    sz[node]=1;
    ll mx=0;
    depth[node]=d;
    parent[node]=p;

    for(auto child:g[node]){
      if(p==child)continue;

      dfs(child,node,d+1);
      sz[node]+=sz[child];
      if(sz[child]>mx){
        mx=sz[child];
        heavy[node]=child;
      }
    }
  };

  dfs(1,0,1);
  vl point(n+1);

  index.pb(0);
  function<void(ll,ll,ll)>go2=[&](ll node,ll p,ll po)->void{
    index.pb(node);
    point[node]=po;

      for(auto child:g[node]){
        if(heavy[node]==child){
          go2(child,node,po);
        }
      }

      for(auto child:g[node]){
        if(heavy[node]==child || p==child)continue;
        go2(child,node,child);
      }
  };

  go2(1,0,1);

  vl position(n+1,0);

  for(ll i=1;i<=n;i++){
    position[index[i]]=i;
  }

  // for(ll i=1;i<=n;i++){
  //   cout<<position[i]<<nl;
  // }

  function<ll(ll,ll,ll,ll,ll)>query=[&](ll l,ll h,ll lq,ll hq,ll pos)->ll{
    if(lq>h || hq<l)return 0;
    if(lq<=l && hq>=h)return arr[pos];
    else{
      ll mid=(l+h)/2;
      return query(l,mid,lq,hq,pos*2) +
                query(mid+1,h,lq,hq,pos*2+1);
    }
  };

  build(1,n,1);

  while(q--){
    ll op;  cin>>op;

    if(op==1){
      ll ind,val; cin>>ind>>val;
      ll asol=position[ind];

      update(1,n,asol,val,1);
    }
    else{
      ll v;   cin>>v;
      ll u=1;

      ll res=0;

      while(1){
        ll x=point[u];
        ll y=point[v];

        ll l1=position[u],l2=position[v];

        if(x==y){
          if(l1>l2)swap(l1,l2);

          res+=query(1,n,l1,l2,1);
          break;
        }

        ll dpt1=depth[u],dpt2=depth[v];

        if(dpt1>dpt2){
          ll to=point[u];
          ll r1=position[to];

          res+=query(1,n,r1,l1,1);
          u=parent[to];
        }
        else{
          ll to=point[v];
          ll r2=position[to];

          res+=query(1,n,r2,l2,1);
          v=parent[to];
        }
      }

      cout<<res<<nl;

    }
  }


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
