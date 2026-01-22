#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define nl '\n'

void linearSieve(ll n,vector<ll>&spf,vector<ll>&primes){
  spf.resize(n+1,0);
  primes.clear();

  for(int i=2;i<=n;i++){
   if(spf[i]==0){
    primes.push_back(i);
    spf[i]=i;
    }
  
   for(auto &p:primes){
    if(p*i*1LL>n || p>spf[i] )break;
    spf[i*p]=p;
    }
  }
}

vector<ll> factorize(ll x,vector<ll>&spf)
{
 vector<ll>factors;
 while(x>1){
  factors.push_back(spf[x]);
  x/=spf[x];
 }
return factors;
}

void shakil(){
 ll n; cin>>n;

 vector<ll>primes,spf;
 linearSieve(n,spf,primes);

 ll phi=n;
 vector<ll>factor=factorize(n,spf);

 set<ll>distinct;
 for(auto it:factor){
  distinct.insert(it);
 }

 for(auto p:distinct){
   phi-=phi/p;
 }
cout<<phi<<nl;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll tt=1;
  cin>>tt;

  for(int i=1;i<=tt;i++)
  {
    shakil();
  }
}
