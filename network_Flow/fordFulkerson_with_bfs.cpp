//--------------------------------------//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define nl '\n'
const ll mod=998244353;
const ll INF=1e9;
ll n;
//---------------------------------------//

bool bfs(vector<vector<ll>>&graph,ll s,ll t,vector<ll>& parent)
{
  ll v=n;
  vector<bool>vis(v+1,false);
  queue<ll>q;
  q.push(s);
  vis[s]=1;
  parent[s]=-1;

  while(!q.empty())
  {
    ll node=q.front();q.pop();
    for (ll child = 1; child <= n; child++)
    {
      if(!vis[child] && graph[node][child]>0)
      {
        parent[child]=node;
        vis[child]=1;
        if(child==t)return true;
        q.push(child);
      }
    }
  }
  return false;
}

ll fordFulkerson(vector<vector<ll>>&graph,ll s,ll t)
{
  ll v=n;
  vector<ll>parent(v+1);

  ll mx_flow=0;

  while(bfs(graph,s,t,parent))
  {
    ll path_flow=INF;
    for(ll v=t;v!=s;v=parent[v])
    {
      ll u=parent[v];
      path_flow=min(path_flow,graph[u][v]);
    }

    for(v=t;v!=s;v=parent[v])
    {
      ll u=parent[v];
      graph[u][v] -= path_flow;
      graph[v][u] += path_flow;
    }
    mx_flow+=path_flow;
  }
  return mx_flow;
}

void shakil()
{
      ll m; cin>>n>>m;      //vertics,edge
  vector<vector<ll>>graph(n+1,vector<ll>(n+1,0));

  for(ll i=0;i<m;i++)
  {
    ll u,v,cap; cin>>u>>v>>cap;
    graph[u][v]=cap;
  }

  ll s,t; cin>>s>>t;  //source ,destination
   ll maxFlow = fordFulkerson(graph, s, t);
   cout << "The maximum possible flow is " << maxFlow << endl;
}

int  main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll tt=1;
  // cin>>tt;
 
  for(int i=1;i<=tt;i++)
  {
    shakil();
  }
}

