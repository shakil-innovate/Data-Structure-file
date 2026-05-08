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

#define MAXN 100000+5

struct Node{
    ll val;
    Node* left,*right;

    Node(Node* l,Node* r,ll v){
        left=l,right=r,val=v;
    }
};

Node* version[MAXN];

void build(Node *cur,ll low,ll high){
    cur->val=0;

    if(low==high){
        return;
    }

    ll mid=(low+high)/2;

    cur->left=new Node(nullptr,nullptr,0);
    cur->right=new Node(nullptr,nullptr,0);

    build(cur->left,low,mid);
    build(cur->right,mid+1,high);
}

void upgrade(Node* pre,Node* cur,ll low,ll high,ll ind){
    if(low==high){
        cur->val=pre->val +1;
        return;
    }
    ll mid=(low+high)/2;

    if(ind<=mid){
        cur->right=pre->right;
        cur->left=new Node(nullptr,nullptr,0);

        upgrade(pre->left,cur->left,low,mid,ind);
    }
    else{
        cur->right=new Node(nullptr,nullptr,0);
        cur->left=pre->left;

        upgrade(pre->right,cur->right,mid+1,high,ind);
    }
    cur->val=cur->left->val + cur->right->val ;
}

ll query(Node* pre,Node *cur,ll low,ll high,ll k){
    if(low==high)return low;
    ll mid=(low+high)/2;

    ll leftCnt=cur->left->val -pre->left->val;
    
    if(k<=leftCnt){
        return query(pre->left,cur->left,low,mid,k);
    }
    else{
        return query(pre->right,cur->right,mid+1,high,k-leftCnt);
    }
}



void shakil(){
    ll n,q;	 cin>>n>>q;

    vl a(n+1);
    for(ll i=1;i<=n;i++)	cin>>a[i];

    vl sorted_a(a.begin()+1,a.end());
    sort(all(sorted_a));

    unordered_map<ll,ll>rank;
    for(ll i=0;i<n;i++)rank[sorted_a[i]]=i+1;

    version[0]=new Node(nullptr,nullptr,0);
    build(version[0],1,n);

    for(ll i=1;i<=n;i++){
        version[i]=new Node(nullptr,nullptr,0);
        upgrade(version[i-1],version[i],1,n,rank[a[i]]);
    }

    while(q--){
        ll l,r,k;	   cin>>l>>r>>k;
        ll ans=query(version[l-1],version[r],1,n,k);
        cout<<sorted_a[ans-1]<<nl;
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
    // cout<<"Case "<<i<<":"<<nl;
    shakil();
  }
}
