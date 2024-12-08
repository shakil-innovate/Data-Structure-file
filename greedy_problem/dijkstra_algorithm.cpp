#include<bits/stdc++.h>
using namespace std;

const int N=1000;


class Graph
{
   private:
      int vertices;
      vector<vector<pair<int,int>>>adj;

  public:
    Graph(int v);
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
    }
    vector<int> shortest_path(int src);
};

Graph::Graph(int v)
{
  vertices=v;
  adj.resize(v+1);
}

vector<int> Graph::shortest_path(int src)
{
 vector<int>dist(vertices+1,INT_MAX);

 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

 dist[src]=0;
 pq.push({0,src});

 while(!pq.empty())
 {
  int node=pq.top().second;

  pq.pop();

   for (auto it : adj[node])
  {
    int weight=it.second;
    int nxtNode=it.first  ;

    if(dist[node]+weight<dist[nxtNode])
    {
      dist[nxtNode]=dist[node]+weight;
     pq.push({dist[nxtNode],nxtNode});
    }
  }
 }
 return dist;
}



int main()
{
  int edge,vertex;
  cin>>edge>>vertex;

  Graph g(vertex);

  for(int i=0;i<edge;i++)
  {
    int x,y,w;
    cin>>x>>y>>w;
     g.addEdge(x,y,w);
  }

  vector<int>dis=g.shortest_path(1);

  for(int i=1;i<=vertex;i++)
  {
    cout<<i<<" :"<<dis[i]<<endl;
  }


}