#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;

ll ph(ll n)
{
    ll result=n;

    ll p;
    for(p=2; p*p<=n ; p++)
    {
        if(n%p==0)
        {
            while(n%p==0)
            {
                n/=p;
                result-=result/p;
            }
        }
    }

    // cout<<result<<" "<<n<<" "<<p<<endl;

    if(n>1)
    {
        result-=result/n;
    }

    return result;
}

void solve()
{
    ll n;   cin>>n;

    cout<<ph(n)<<endl;
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);

//    ll tt;   cin>>tt;
   
//    while(tt--)
     solve();
}
