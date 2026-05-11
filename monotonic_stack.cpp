//problem_link:https://lightoj.com/problem/histogram

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
//if(st.find(5) != st.end())        => check exist
//st.order_of_key(x + 1)   => number of element

void shakil(){
    ll n;       cin>>n;
    vl v(n);

    for(auto &it:v)     cin>>it;

    vl nxsmLR(n,n);
    vl nxsmRL(n,-1);

    stack<ll>st;

    for(ll i=0;i<n;i++){
        
        while(st.size()!=0 && v[i]<v[st.top()]){
            ll ind=st.top();

            nxsmLR[ind]=i;
            st.pop();
        }
        st.push(i);
    }

    set<ll>st2;

    for(ll i=n-1;i>=0;i--){
        while(!st.empty() &&    v[i]<v[st.top()]){
            ll ind=st.top();

            nxsmRL[ind]=i;
            st.pop();
        }
        st.push(i);
    }

    ll mx=0;

    for(ll i=0;i<n;i++){    
        ll l=nxsmLR[i]-i;
        ll r=i-nxsmRL[i];

        ll tlt=l+r-1;
        mx=max(mx,tlt*v[i]);
    }

    cout<<mx<<nl;
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
