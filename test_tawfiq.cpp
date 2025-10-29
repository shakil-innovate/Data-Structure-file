#include<bits/stdc++.h>
#include<cmath>
#include<cstring>
#include<numeric>
#include <algorithm>
using namespace std;
#define orderedset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define tawfiq123() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define endl '\n'
#define F first
#define S second
#define pb push_back
#define ll long long
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

#define mod 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
#define sqr(a) ((a)*(a))
typedef vector<int>vi;
typedef vector<ll>vll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<pair<int,int>>vpii;
typedef vector<pair<ll,ll>>vpll;

const ll p=1e5+123;
const int mx=2e5+120;
const ll inf=9000000000000000000;

ll mul(ll a,ll b)
{
    return ((((a%mod)+mod)%mod)*(((b%mod)+mod)%mod))%mod;
}

ll add(ll a,ll b)
{
    return ((((a%mod)+mod)%mod)+(((b%mod)+mod)%mod))%mod;
}


ll binexpo(ll a,ll b)
{
    ll res=1ll;
    if(b==0)return 1ll;
    res=binexpo(a,b/2);
    if(b%2)
    {
        res=mul(res,res);
        res=mul(res,a);
    }
    else {
            res=mul(res,res);
    }
    return res;
}


vll primes;
bool vis[mx];
void sieve(ll n)
{
    for(int i=3;i<=n;i+=2)vis[i]=1;
    ll sq=sqrt(n);
    vis[2]=1;
    primes.pb(2);
    for(int i=3;i<=sq;i+=2)
    {

            for(int j=i+i;j<=n;j+=i)
            {
                vis[j]=0;
            }

    }
    for(int i=3;i<=n;i+=2)
    {
        if(vis[i])primes.pb(i);
    }

}


void solve(int t)
{
int n;
cin>>n;
vll v(n);
ll k=0;
ll ans=0,f=0;

for(int i=0;i<n;i++){cin>>v[i];
k=gcd(k,v[i]);

}

if(vis[k])
{
    cout<<n<<endl;
}
else
{
    ll c=0,x,h;
    ans=0,f=0;
    for(int i=0;i<n;i++)
    {c=0;
 h=v[i];
x=v[i];
if(vis[v[i]])f=1;
       ll l=i-1,r=i+1;

        while(l>=0 )
        {
             x=gcd(v[l],x);

            if(vis[x]){
                    c++;
            h=x;
            }
            else{

                break;
            }
            l--;
        }
        //cout<<h<<endl;
        while(r<n)
        {
             h=gcd(v[r],h);

            if(vis[h])c++;
            else break;
            r++;
        }
        ans=max(ans,c);
//cout<<ans<<endl;
    }
 // cout<<ans<<" "<<f<<endl;
 if(ans==0 &&f==0)cout<<-1<<endl;
 else if(ans==0 &&f==1)cout<<1<<endl;
else cout<<ans+1<<endl;
}
}




 int main()
 {
     tawfiq123();
    int t=1;
cin>>t;

sieve(mx);
for(int i=1;i<=t;i++)
     {
       solve(i);
     }
  }
