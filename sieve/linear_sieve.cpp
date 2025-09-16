#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'

void linear(ll n,vector<ll>&primes,vector<ll>&spf)
{
    spf.resize(n+1,0);
    primes.clear();

    for(int i=2;i<=n;i++)
    {
        if(spf[i]==0)
        {
            spf[i]=i;
            primes.push_back(i);
        }

        for(auto &p:primes)
        {
            if(p>spf[i] || i*p>n)break;   //smaller num. is a divisor of i
            spf[i*p]=p;
        }
    }
}

vector<ll>factorize(ll x,vector<ll>&spf)
{
    vector<ll>factors;
    while(x>1)
    {
        factors.push_back(spf[x]);
        x/=spf[x];
    }
    return factors;
}

void shakil()
{
    ll n;   cin>>n;
    vector<ll>primes,spf;
    linear(n,primes,spf);

    cout<<"primes :"<<primes.size()<<nl;
    for(auto it:primes) cout<<it<<" ";
    cout<<nl;

    ll x=36;
    vector<ll>factor=factorize(x,spf);
     
    cout<<factor.size()<<nl;
    for(auto it:factor)cout<<it<<" ";
    cout<<nl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();

    // ll tt;  cin>>tt;
    // while(tt--)
       shakil();
}
