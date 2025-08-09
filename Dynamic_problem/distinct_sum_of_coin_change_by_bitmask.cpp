//problem link:https://www.spoj.com/problems/ADACOINS/

#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;

void shakil()
{
    ll n,q; cin>>n>>q;

    vector<ll>v(n);

    for(auto &it:v) cin>>it;

    const ll max_sum=1e5+5;
    bitset<max_sum>dp;
    dp[0]=1;

    for(int i=0; i<n ;i++)
    {
        dp|=(dp<<v[i]);
    }

    vector<ll>pre(max_sum,0);

    for(int i=1; i<max_sum;i++)
    {
        pre[i]=pre[i-1]+dp[i];
    }

    while(q--)
    {
        ll st,en;   cin>>st>>en;
        cout<<pre[en]-pre[st-1]<<'\n';
    }
    // cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // ll tt;  cin>>tt;

    // while(tt--)

        shakil();
}
