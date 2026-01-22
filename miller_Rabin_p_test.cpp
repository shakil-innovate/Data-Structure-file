//--------------------------------------//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;         typedef unsigned long long ull;    
typedef long double ld;       typedef double db;
#define nl endl
typedef priority_queue<ll, vector<ll>, greater<ll>> min_pq;   


#define i128  __int128
ll mod=1e15+7;      const ll INF=1e15;
ll power(ll a, ll b){ll res=1; a%=mod;while(b > 0){if(b & 1)res=((i128)res*a) %mod; a=((i128)a*a)%mod;b=b>>1;}return res;}
//---------------------------------------//

bool isPrime(ll n){
 if(n<2 || n%2==0)return false;
 if(n==2 || n==3) return 1;
 mod=n;

 ll d=n-1;
 ll m=0;
 while(d%2==0){
  m++;
  d/=2;
 }

vector<ll>base={2,3,5,7,11,13,17,19,23};

for(auto a:base){
 if(a>n) break;
 ll x=power(a,d);

 if(x==1 || x==n-1)continue;
 bool composite=1;
 
 for(ll r=1;r<m;r++){
  x=(i128)x*x%n;
  if(x==n-1 ){
  composite=false;
   break;
 }
}

 if(composite==1)return 0;
}
return 1;
}

void shakil(){
  cout<<"Enter a number: "<<nl;
  ll num;   cin>>num;
  cout<<num<<" is "<<(isPrime(num)==true?"Prime ":" not prime")<<nl;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll tt=1; 
    cin >> tt;
    for(ll i = 1; i <= tt; i++){
      // cout<<"Case "<<i<<": ";
        shakil();
    }
    return 0;
}
