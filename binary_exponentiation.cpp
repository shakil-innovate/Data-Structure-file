
const ll mod=1e9+7;

ll power(ll a,ll b)
{
    ll res=1;

    while(b)
    {
        if(b%2==1)
        {
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b/=2;
    }
    return res;
}
