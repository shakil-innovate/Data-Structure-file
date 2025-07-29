#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll minimum_coin(vector<ll>&coin,ll target)
{
    vector<ll>prev(target+1,0),cur(target+1,0);

    for(int t=0;t<=target; t++)
    {
        if(t%coin[0]==0)    prev[t]=t/ coin[0];
        else prev[t]=1e9;
    }

    for(int ind=1; ind<coin.size() ; ind++)
    {
         vector<ll> cur(target + 1, 0);
        for(int t=0 ; t<=target ; t++)
        {
         ll take=1e9;

        ll notTake=prev[t];

        if(coin[ind] <=t)
        take=1+cur[t-coin[ind]];

         cur[t]=min(notTake,take);
        }
        prev=cur;
    }

    ll ans = prev[target];
    if(ans>=1e9) return -1;
    else return ans;
}

int main()
{
    ll n,target;   cin>>n>>target;

    vector<ll>v(n);

    for(auto &it:v) cin>>it;

    cout<<minimum_coin(v,target)<<endl;
}
