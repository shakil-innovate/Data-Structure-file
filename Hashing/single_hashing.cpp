//problem link:https://cses.fi/problemset/task/1753

//--------------------------------------//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
const ll mod=998244353;
//---------------------------------------//

void shakil()
{
   string s,t;    cin>>s>>t;

   ll n=s.size(),m=t.size();
   ll base=26,power=1,pattern=0,hash=0;

   for(ll i=0;i<m;i++)
   {
     pattern=(pattern*base+t[i]-'a')%mod;
     hash=(hash*base+s[i]-'a')%mod;
     if(i<m-1)power=(power*base)%mod;
   }

   ll cnt=0;

   for(ll i=0;i+m-1<n;i++)
   {
    if(hash==pattern)cnt++;
    if(i+m-1<n-1)
    {
      hash=((hash-(s[i]-'a')*power)*base+s[i+m]-'a')%mod;
    }
    if(hash<0)hash+=mod;
   }

   cout<<cnt<<nl;
}
int  main()
{
   ios_base::sync_with_stdio(0);cin.tie(0);
    ll tt=1;
    // cin>>tt;

    for(ll i=1;i<=tt;i++)
    {
      shakil();
    }
}
