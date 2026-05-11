//problem:https://lightoj.com/problem/how-many-zeroes

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

// order_of_key(x)  => how many element smaller than x
// *st.find_by_order(k)  k th element 0 based index
// if(st.find(5) != st.end())		=> check exist  
// st.order_of_ke

ll cal(ll num){
  if(num<0)return -1;
    ll cnt=0;
    ll len=0;
    ll pw=1;
    ll pass=0;

    while(num>0){

      ll x=num%10;
      num/=10;
      ll numm=num/10;

      if(x==0){
          cnt+=(num-1)*pw+1+pass;
      }
      else{
        cnt+=num*pw;
      }
      pass+=x*pw;
      pw*=10;
    }

    return cnt; 
}

void shakil(){
  ll m,n;   cin>>m>>n;

  cout<<cal(n)-cal(m-1)<<nl;
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
  cout<<"Case "<<i<<": ";
  shakil();
  }
}
