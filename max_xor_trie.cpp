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

struct node{
    node* child[2];

};

const ll mxNodes=500002*33;
node pool[mxNodes];

ll ind;
void reset(){
  ind=0;
}

node* newNode(){
  pool[ind].child[0]=nullptr;
  pool[ind].child[1]=nullptr;
  
  return &pool[ind++];
}

void insert(node* root,ll num){
    node* cur=root;

    for(ll i=31;i>=0;i--){
        ll bit=((num>>i)&1);

        if(!cur->child[bit]){
            cur->child[bit]=newNode();
        }
        cur=cur->child[bit];
    }
}

ll find_mxxor(node* root,ll num){
    node* cur=root;

    ll ans=0;
    for(ll i=31;i>=0;i--){
        ll bit=(num>>i)&1;
        ll want=1-bit;

        if(cur->child[want]!=nullptr){
            ans|=(1LL<<i);
            cur=cur->child[want];
        }
        else cur=cur->child[bit];
    }

    return ans;
}

ll min_xor(node* root,ll num){
    node* cur=root;

    ll ans=0;

    for(ll i=31;i>=0;i--){
        ll bit=(num>>i)&1;
        ll want=1-bit;

        if(cur->child[bit]!=nullptr){
            cur=cur->child[bit];
        }
        else{
            ans|=(1LL<<i);
            cur=cur->child[want];
        }
    }
    return ans;
}

void shakil(){
    ll n;   cin>>n;

    reset();

    vl v(n);

    for(auto &it:v) cin>>it;

    node* root=newNode();

    insert(root,0);

    ll mn=INF,mx=-5;

    ll nw=0;

    for(ll i=0;i<n;i++){
        nw=nw^v[i];

        mx=max(mx,find_mxxor(root,nw));
        mn=min(mn,min_xor(root,nw));

        insert(root,nw);
    }

    cout<<mx<<" "<<mn<<nl;
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
