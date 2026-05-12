//https://lightoj.com/problem/points-in-rectangle

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

const int N=1000+5;
int bit[N][N];

void update(ll x,ll y,ll val){
  for(ll i=x;i<=1001;i+=i&-i){
    for(ll j=y;j<=1001;j+=j&-j){
      bit[i][j]+=val;
    }
  }
}

ll query(ll x,ll y){
  ll ans=0;

  for(ll i=x;i>0;i-=i&-i){
    for(ll j=y;j>0;j-=j&-j){
      ans+=bit[i][j];
    }
  }

  return ans;
}

ll rslt(ll x1,ll y1,ll x2,ll y2){
    return query(x2,y2)-
          query(x2,y1-1)-
          query(x1-1,y2)+
          query(x1-1,y1-1);
}

void shakil(){
  ll n;   cin>>n;

  for(ll i=0;i<=1001;i++){
    for(ll j=0;j<=1001;j++){
      bit[i][j]=0;
    }
  }

  map<pair<ll,ll>,bool>vis;

  while(n--){
    ll op;    cin>>op;

    if(op==0){
      ll x,y;   cin>>x>>y;
      x++,y++;

      if(vis[{x,y}]==0){
        vis[{x,y}]=1;
      update(x,y,1);}
    }
    else if(op==1){
        ll x1,y1,x2,y2;   cin>>x1>>y1>>x2>>y2;
        x1++,y1++,x2++,y2++;
        ll ans=rslt(x1,y1,x2,y2);

        cout<<ans<<nl;
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
  cin>>tt;

  for(ll i=1;i<=tt;i++){
  cout<<"Case "<<i<<":"<<nl;
  shakil();
  }
}
