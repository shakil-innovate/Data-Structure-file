#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=5;

ll gcd(ll a,ll b)
{
    if(b>a)swap(a,b);

    if(a%b==0)return b;
    else return gcd(b,a%b);
}

ll lcd(ll a,ll b)
{
    return a*b/gcd(a,b);
}

void solve() {
    cout<<lcd(8,12);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // int tt;
    // cin >> tt;
    // while (tt--)
      solve();
    return 0;
}
