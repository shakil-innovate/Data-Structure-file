#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>>preprocess(vector<ll>&input,ll n)
{
    vector<vector<ll>>sparse(n,vector<ll>(log2(n)+1));

    for(int i=0 ; i<n ; i++)    sparse[i][0]=input[i];


    for(int j=1; (1<<(j))<=n ; j++)
    {
        for(int i=0; (i+(1<<(j))-1)< n ; i++)
        {
            sparse[i][j]=__gcd(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
        }
    }

    return sparse;

}

ll query(ll low,ll high,vector<vector<ll>>&sparse,vector<ll>&input)
{
    ll l=high-low+1;
    ll k=log2(l);

    return __gcd(sparse[low][k],sparse[high-(1<<k)][k]);
}

void shakil()
{
    int n,q;  cin>>n>>q;
    vector<ll>v(n);
    for(int i=0 ; i<n ; i++)    cin>>v[i];
    vector<vector<ll>>sparse=preprocess(v,n);


    while(q--)
    {
        ll l,r;     cin>>l>>r;
        cout<<query(l-1,r-1,sparse,v)<<endl;
    }
}
int  main()
{
    // int tt;     cin>>tt;
    // while(tt--)
        shakil();
}
