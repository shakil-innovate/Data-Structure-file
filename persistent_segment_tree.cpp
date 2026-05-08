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

#define MAXN 100

struct Node{
    ll val;
    Node* left,*right;

    Node(){};

    Node(Node* l,Node* r,int v){
        left=l;
        right=r;
        val=v;
    }

};

int arr[MAXN];
Node* version[MAXN];

void build(Node* cur,ll low,ll high){
    if(low==high){
        cur->val=arr[low];
        return;
    }
    else{
        ll mid=(low+high)/2;
        cur->left=new Node(nullptr,nullptr,0);
        cur->right=new Node(nullptr,nullptr,0);

        build(cur->left,low,mid);
        build(cur->right,mid+1,high);

        cur->val=cur->right->val + cur->left->val;
    }
}

void upgrade(Node* pre, Node* cur,ll low, ll high,ll ind,ll value){
    if(ind>high || ind<low or low>high)return;

    if(low==high){
        cur->val=value;
        return;
    }
    else{
        ll mid=(low+high)/2;

        if(ind<=mid){
            cur->right=pre->right;
            cur->left=new Node(nullptr,nullptr,0);

            upgrade(pre->left,cur->left,low,mid,ind,value);
        }
        else{
            cur->left=pre->left;
            cur->right=new Node(nullptr,nullptr,0);

            upgrade(pre->right,cur->right,mid+1,high,ind,value);
        }

        cur->val=cur->left->val + cur->right->val;
    }
}

int query(Node* cur,ll low,ll high,ll l,ll r){
    if(l>high || r<low ||low>high){
        return 0;
    }

    if(l <= low && high <= r){
        return cur->val;
    }

    ll mid=(low+high)/2;
    ll p1=query(cur->left,low,mid,l,r);
    ll p2=query(cur->right,mid+1,high,l,r);

    return p1+p2;
}

void shakil(){
    vl A={1,2,3,4,5};
    ll n=A.size();

    for(ll i=0;i<n;i++){
        arr[i]=A[i];
    }

    Node* root=new Node(nullptr,nullptr,0);
    build(root,0,n-1);
    version[0]=root;

    version[1]=new Node(nullptr,nullptr,0);
    upgrade(version[0],version[1],0,n-1,4,1);

    version[2]=new Node(nullptr,nullptr,0);
    upgrade(version[1],version[2],0,n-1,2,10);

    cout<<"query from version 1:"<<nl;
    cout<<query(version[1],0,n-1,0,4)<<nl;

    cout<<"query from version 2:"<<nl;
    cout<<query(version[2],0,n-1,3,4)<<nl;
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
    cout<<"Case "<<i<<":"<<nl;
    shakil();
  }
}
