#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

vector<ll>limit(ll R)
{
    vector<bool>prime(R+1,1);
    prime[0]=0;
    prime[1]=0;

    for(ll i=2;i*i<=R;i++)
    {
        if(prime[i]==1)
        {
            for(ll j=i*i;j<=R;j+=i)
               prime[j]=0;
        }
    }

    vector<ll>only_Prime;
    for(int i=2;i<=R;i++)
    {
        if(prime[i])  only_Prime.push_back(i);
    }
    return only_Prime;
}

ll segmentedSieve(ll L,ll R)
{
    vector<ll>primes=limit(sqrt(R));

    vector<bool>actual_prime(R-L+1,1);

    for(auto &p:primes)
    {
        ll start=max(p*p,1LL*((L+p-1)/p)*p);
        for(;start<=R;start+=p)
        {
            actual_prime[start-L]=0;
        }
    }

    ll cnt=0;
    for(ll i=L;i<=R;i++)
    {
        if(i==1 || i==0)continue;
        if(actual_prime[i-L]==1){cout<<i<<" ";cnt++;}
    }
    cout<<nl;
    return cnt;
    
}

void shakil()
{
    ll L,R; cin>>L>>R;
    cout<<segmentedSieve(L,R)<<nl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();

    // ll tt;  cin>>tt;
    // while(tt--)
       shakil();
}
