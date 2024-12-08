#include<bits/stdc++.h>
using namespace std;

#define ipair pair<int,int>

class Graph
{
  private:
    int v;
    list<pair<int,int>>*adj;
  public:
    Graph(int v);
    void addEdge(int u,int v,int w);
    void shortestPath(int s);
};

Graph::Graph(int v)
{
    this->v=v;
    adj=new list<ipair>[v];
}

void Graph::addEdge(int u,int v,int w)
{
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

void Graph::shortestPath(int s)
{
  priority_queue<ipair,vector<ipair>,greater<ipair>>pq;
  vector<int>dist(v,INT_MAX);

  pq.push(make_pair(0,s));
  dist[s]=0;

  while(!pq.empty())
  {
    int u=pq.top().second;
    pq.pop();
    
    list<pair<int,int>>::iterator i;
    for(i=adj[u].begin();i!=adj[u.end();i++])
    {
       
    }
  }
}

int main()
{
    int v=7;
    Graph g(7);

    g.addEdge(0,1,2);
    g.addEdge(0,2,6);
    g.addEdge(1,3,5);
    g.addEdge(2,3,8);
    g.addEdge(3,4,10);
    g.addEdge(3,5,15);
    g.addEdge(4,6,2);
    g.addEdge(5,6,6);
  
   g.shortestPath(0);

}