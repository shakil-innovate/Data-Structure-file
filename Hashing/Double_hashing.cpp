//problem_link:https://cses.fi/problemset/task/1753/

//--------------------------------------//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
const ll mod1=1e9+7;
const ll mod2=998244353;
//---------------------------------------//

void shakil()
{
   string s,t;    cin>>s>>t;

   ll n=s.size(),m=t.size();
   ll base=26,power1=1,power2=1,pattern1=0,pattern2=0,hash1=0,hash2=0;

   for(ll i=0;i<m;i++)
   {
     pattern1=(pattern1*base+t[i]-'a')%mod1;
     pattern2=(pattern2*base+t[i]-'a')%mod2;
     hash1=(hash1*base+s[i]-'a')%mod1;
     hash2=(hash2*base+s[i]-'a')%mod2;

     if(i<m-1)
     {
       power1=(power1*base)%mod1;
       power2=(power2*base)%mod2;
     }
   }

   ll cnt=0;

   for(ll i=0;i+m-1<n;i++)
   {
    if(hash1==pattern1 && hash2==pattern2)cnt++;

    if(i+m-1<n-1)
    {
      hash1=((hash1-(s[i]-'a')*power1)*base+s[i+m]-'a')%mod1;
      hash2=((hash2-(s[i]-'a')*power2)*base+s[i+m]-'a')%mod2;
    }
    if(hash1<0)hash1+=mod1;
    if(hash2<0)hash2+=mod2;
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
