    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;

    ll lis(vector<ll>&v)
    {
        vector<ll>sub;

        for(auto num:v)
        {
            auto pos=upper_bound(v.begin(),v.end(),num);
            if(pos==v.end())sub.push_back(num);
            else *pos=num;
        }
        return sub.size();
    }
    void solve()
    {
        vector<ll>v={10,20,1,30,2,3,4};
        cout<<lis(v)<<endl;
    }

    int main()
    {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    // int tt;  cin>>tt;
    // while(tt--)
        solve();
    }
