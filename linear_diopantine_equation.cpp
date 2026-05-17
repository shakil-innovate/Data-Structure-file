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
#define int128 __int128

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

ll g(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }

    ll x1,y1;
    ll d=g(b,a%b,x1,y1);

    x=y1;
    y=x1-y1*(a/b);

    return d;
}

void shakil(){

   ll a=15,b=10,c=25;
   ll x,y;

   ll d=g(a,b,x,y);

   ll x0=x*(c/d),y0=y*(c/d);

   cout<<"particular soltion: "<<x0<<" "<<y0<<nl;

   //other soltion:
   //(x0+(c/d)*m),  (y0 - (c/d)*m)
}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  ll tt=1;
//   cin>>tt;

  for(ll i=1;i<=tt;i++){
  // cout<<"Case "<<i<<": ";
  shakil();
  }
}
