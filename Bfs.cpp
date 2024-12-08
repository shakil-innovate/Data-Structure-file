#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e7+10;

vector<vector<ll>>v(N);
ll vis[N];

void bfs(ll source)
{
   queue<ll>q;

   q.push(source);
   vis[source]=1;

   while(!q.empty())
   {
    ll node=q.front();
    q.pop();
    cout<<node<<" ";
  
    for(ll child:v[node])
    {
        if(!vis[child])
        {
            q.push(child);
            vis[child]=1;
        }
    }
   }

}

int main()
{
    ll node;cin>>node;

    for(ll i=0;i<node;i++)
    {
        ll x,y;cin>>x>>y;

        v[x].push_back(y);
        v[y].push_back(x);
    }
    ll source;cin>>source;
   bfs(source);
}