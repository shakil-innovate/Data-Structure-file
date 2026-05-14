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

const int N=1e6;
vector<ll>mob;

void init(){
  vl primes;
  vl spf(N+1,0);
  mob.resize(N+1,0);
  mob[1]=1;

  for(ll i=2;i<=N;i++){
    if(spf[i]==0){
      spf[i]=i;
      primes.pb(i);
      mob[i]=-1;
    }
    for(auto p:primes){
      if(p*i>N || p>spf[i])break;
      spf[i*p]=p;

      if(i%p==0)mob[i*p]=0;
      else mob[i*p]=-mob[i];
    }
  }
}


void shakil(){
  ll n;   cin>>n;

  //find pair of coprime

  ll ans=0;

  for(ll i=1;i<=n;i++){
    ll d=n/i;
    ans+=mob[i]*d*d;
  }

  cout<<ans<<nl;
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  init();

  ll tt=1;
  cin>>tt;

  for(ll i=1;i<=tt;i++){
  // cout<<"Case "<<i<<": ";
  shakil();
  }
}
