//problem link:https://cses.fi/problemset/task/1111/

//--------------------------------------//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define pb push_back 
#define nl '\n'
#define vi vector<ll>
#define vii vector<vi>
#define f first
#define s second
const ll mod=1e9+7;
const ll mod1=1e9+7;
const ll mod2=1e9+9;
const ll INF=1e9;
//---------------------------------------//
 
struct  DoubleHash{
  vi h1,h2,p1,p2;
  ll base1=131,base2=133;
 
  DoubleHash(string &s){
    ll n=s.size();
    h1.resize(n+1,0);h2.resize(n+1,0);
    p1.resize(n+1,1),p2.resize(n+1,1);
 
    for(ll i=0;i<n;i++){
      h1[i+1]=(h1[i]*base1 + s[i])%mod1;
      h2[i+1]=(h2[i]*base2 + s[i])%mod2;
      p1[i+1]=(p1[i]*base1)%mod1;
      p2[i+1]=(p2[i]*base2)%mod2;
    }
  }
 
  pair<ll,ll> getHash(ll l,ll r){
    ll x1=(h1[r+1]-h1[l]*p1[r-l+1] )%mod1;
    ll x2=(h2[r+1]- h2[l]*p2[r-l+1])%mod2;
 
    if(x1<=0) x1+=mod1;
    if(x2<=0) x2+=mod2;
 
    return {x1,x2};
  }
 
};
 
void shakil(){
  string s;   cin>>s;
 
  DoubleHash Hf(s);
  string rs=s;
  reverse(rs.begin(),rs.end()); 
  DoubleHash Hr(rs);
 
  ll n=s.size();
 
  auto Palindrome=[&](ll l,ll r)-> bool{
    auto hf=Hf.getHash(l,r);
    ll rl=n-1-r;
    ll rr=n-1-l;
 
    auto hr=Hr.getHash(rl,rr);
 
    return hr==hf;
  };
 
  ll best_len=1,best_pos=0;
 
  auto check=[&](ll len)->ll{
    for(ll i=0;i+len-1<n;i++){
      ll j=i+len-1;
      if(Palindrome(i,j))  return i;
   }
 
   return -1;
  };
 
  ll low=1,high=n;
 
  while(low<=high){
    ll mid=(low+high)>>1;
    if(mid%2==0)mid--;
    if(mid<=0) {low=mid+1;continue;}
 
    ll pos=check(mid);
 
    if(pos!=-1){
      if(mid>best_len)
      {
        best_len=mid;
        best_pos=pos;
      }
      low=mid+2;
    }
    else high=mid-2;
  }
 
  low=2,high=n;
  while(low<=high){
     ll mid=(low+high)>>1;
     if(mid%2!=0){mid--;}
     if(mid<=0) {low=mid+2;continue;}
 
     ll pos=check(mid);
 
     if(pos!=-1){
      if(mid>best_len)
      {
        best_len=mid;
        best_pos=pos;
      }
      low=mid+2;
     }
     else high=mid-2;
  }
 
  cout<<s.substr(best_pos,best_len)<<nl;

}
int  main(){
   ios_base::sync_with_stdio(0);cin.tie(0);
    ll tt=1;
    // cin>>tt;
 
    for(ll i=1;i<=tt;i++)
    {
      shakil();
    }
}
