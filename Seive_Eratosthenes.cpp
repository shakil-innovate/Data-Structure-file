#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=5;


void seive_Eratosthenes() {

    ll n;       cin>>n;

    vector<bool>prime(n+1,1);

    for(int i=2; i*i<=n ; i++)
    {
        if(prime[i])
        {
            for(int j=i*i; j<=n; j+=i)
            {
                prime[j]=0;
            }
        }
    }

    ll ans=0;
    for(int i=2; i<=n; i++)if(prime[i])ans++;

    cout<<ans<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // int tt;
    // cin >> tt;
    // while (tt--)
      seive_Eratosthenes();
    return 0;
}
