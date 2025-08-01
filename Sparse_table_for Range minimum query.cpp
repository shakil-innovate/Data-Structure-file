#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>>preprocess(vector<ll>&input,ll n)
{
    vector<vector<ll>>sparse(n,vector<ll>(log2(n)+1));
    for(int i=0 ; i<n ; i++)    sparse[i][0]=i;


    for(int j=1; (1<<(j))<=n ; j++)
    {
        for(int i=0; (i+(1<<(j))-1)< n ; i++)
        {
            if(input[sparse[i][j-1]] < input[sparse[i+(1<<(j-1))][j-1]])
            {
                sparse[i][j]=sparse[i][j-1];
            }
            else sparse[i][j]=sparse[i+(1<<(j-1))][j-1];
        }
    }

    return sparse;

}

ll query(ll low,ll high,vector<vector<ll>>&sparse,vector<ll>&input)
{
    ll l=high-low+1;
    ll k=log2(l);

    return min(input[sparse[low][k]],input[sparse[low+l-(1<<(k))][k]]);
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
