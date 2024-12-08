#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=1e7+10;

vector<vector<ll>>g(N);
ll vis[N];

void dfs(ll source)
{
    stack<ll>st;

    st.push(source);

    vis[source]=1;

    while(!st.empty())
    {
      ll node=st.top();
      
      st.pop();
      cout<<node<<" ";

      for(ll child:g[node])
      {
        if(!vis[child])
        {
           st.push(child);
           vis[child]=1;
           
        }
      }
    }

}

int main()
{
    ll edge;
    cin>>edge;

    for(ll i=0;i<edge;i++)
    {
        ll x,y;
        cin>>x>>y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    ll source;cin>>source;

    dfs(source);

}