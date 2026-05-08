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

ll block;
vector<vl>arr;
vl v;
ll n;

ll query(ll l,ll r,ll m){
    ll ans=0;

    while(l<=r){
        ll b=l/block;

        if(l%block==0 && l+block-1<=r){
            ans+=upper_bound(all(arr[b]),m-1)-arr[b].begin();
            l+=block;
        }
        else{
            if(v[l]<m)ans++;
            l++;
        }
    }
    return ans;
}

void rebuild(ll l){
    ll b=l/block;

    arr[b].clear();
    ll R=min(n-1,b*block+block-1);

    for(ll i=b*block;i<=R;i++)arr[b].pb(v[i]);

    sort(all(arr[b]));
}

void shakil(){
    ll q;       cin>>n>>q;

    v.resize(n);

    for(auto &it:v)     cin>>it;

    ll sz=sqrt(n);

    while(sz*sz<n)sz++;
    while(sz*sz>n)sz--;

    sz++;

    block=sz;
    ll tlt=(n+sz-1)/sz;

    arr.resize(tlt+1);

    for(ll i=0;i<n;i++){
        arr[i/block].pb(v[i]);
    }

    for(ll i=0;i<=tlt;i++)sort(all(arr[i]));

    while(q--){
        ll op;      cin>>op;

        if(op==1){
            ll l,r,m;       cin>>l>>r>>m;
            l--,r--;

            cout<<query(l,r,m)<<nl;
        }
        else {
            ll l,r;     cin>>l>>r;
            l--,r--;

            swap(v[l],v[r]);

            rebuild(l);
            rebuild(r);
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
