#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Graph
{
    public:

    vector<ll>arr;
    vector<ll>seg_tree;
    vector<ll>lazy;

    Graph(ll n)
    {
        arr.resize(n);
        seg_tree.resize(4*n);
        lazy.resize(4*n,0);
    }


    void propagate(ll low,ll high,ll pos)
    {
        if(lazy[pos]!=0)
        {
            seg_tree[pos]+=(high-low+1)*lazy[pos];

            if(low!=high)
            {
                lazy[pos*2+1]+=lazy[pos];
                lazy[pos*2+2]+=lazy[pos];
            }
            lazy[pos]=0;
        }
    }

    void build(ll low,ll high,ll pos)
    {
        if(low==high)
        {
            seg_tree[pos]=arr[low];
        }
        else
        {
            ll mid=(low+high)>>1;
            
            build(low,mid,pos*2+1);
            build(mid+1,high,pos*2+2);

            seg_tree[pos]=(seg_tree[pos*2+1]+seg_tree[pos*2+2]);
        }
    }

    ll query(ll qlow,ll qhigh,ll low,ll high,ll pos)
    {
        propagate(low,high,pos);

        if(qlow<=low && qhigh>=high)    return seg_tree[pos];
        else if(qlow> high || qhigh < low) return 0;
        else{
            ll mid=(low+high)>>1;
            return ((query(qlow,qhigh,low,mid,pos*2+1) + query(qlow,qhigh,mid+1,high,pos*2+2)));
        }
    }

    void update(ll qlow,ll qhigh,ll low,ll high, ll val, ll pos)
    {
        propagate(low,high,pos);

        if(qlow>high || qhigh<low)  return;

        if(qlow<=low && qhigh>=high)
        {
            lazy[pos]+=val;
            propagate(low,high,pos);
            return;
        }

        else{
            ll mid=(low+high)>>1;
             update(qlow,qhigh,low,mid,val,pos*2+1);
              update(qlow,qhigh,mid+1,high,val,pos*2+2);

            seg_tree[pos]=(seg_tree[pos*2+1]+seg_tree[pos*2+2]);
        }
    }

};

int main()
{
    ll n;   cin>>n;

    Graph g(n);

    for(int i=0 ;i<n ; i++) cin>>g.arr[i];

    g.build(0,n-1,0);

    ll l,r; cin>>l>>r;
    cout<<g.query(l-1,r-1,0,n-1,0)<<endl;
    
    ll val;     cin>>l>>r>>val;
    g.update(l-1,r-1,0,n-1,val,0);

     cin>>l>>r;
     cout<<g.query(l-1,r-1,0,n-1,0)<<endl;
}
