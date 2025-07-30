problem link:https://vjudge.net/contest/732417#problem/L

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
   ll n;        cin>>n;
   vector<ll>v(n);
   for(auto &it:v)  cin>>it;

   vector<ll>ans;
   ans.push_back(v[0]);

   for(int i=1; i<n ; i++)
   {
       ll x=v[i];
        auto it=lower_bound(ans.begin(),ans.end(),x);
        if(it==ans.end())
        {
            ans.push_back(x);
        }
        else *it=x;
   }

   cout<<ans.size()<<endl;
}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

    solve();
}
