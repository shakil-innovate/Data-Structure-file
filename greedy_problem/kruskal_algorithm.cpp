#include<bits/stdc++.h>
using namespace std;

#define edge pair<int,int>

class Graph
    {
    private:
        vector<pair<int,edge>>G;  //store edge
        int* parent;
        int v; //number of vertices/node in the graph
        vector<pair<int,edge>>T;  //minimum spanning tree


    public:
        Graph(int v);
        void addWeightedEdge(int u,int v,int w);
        void kruskal();
        int find_set(int i);
        void union_set(int u,int v);
        void print();

    };

 void Graph::addWeightedEdge(int u,int v,int w)
    {
        G.push_back(make_pair(w,edge(u,v)));
    }  

Graph::Graph(int v)
    {
        parent=new int[v];
        
        for(int i=0;i<v;i++)
        {
            parent[i]=i;
        }
    }


void Graph::kruskal()
{
  sort(G.begin(),G.end());

  int vRep,uRep;

  for(int i=0;i<G.size();i++)
  {
     uRep=G[i].second.first;
     vRep=G[i].second.second;

     if(find_set(uRep)!=find_set(vRep))
     {
      T.push_back(G[i]);
      union_set(uRep,vRep);
     }
  }
}

int Graph::find_set(int i)
    {
        if(i==parent[i])
        {
            return i;
        }
        else return find_set(parent[i]);
    }

void Graph::union_set(int u, int v) 
    {
        parent[v] = u;  // Make v the parent of u
    }


    void Graph::print()
    {

        cout<<"node-node : Weight"<<endl;
        for(int i=0;i<T.size();i++)
        {
        cout<<T[i].second.first<<"-"<<T[i].second.second<<" "<<T[i].first<<endl;
        }
    }


 int main()
    {
    Graph g(6);

    g.addWeightedEdge(0,1,4);
    g.addWeightedEdge(1,0,4);
    g.addWeightedEdge(1,2,2);
    g.addWeightedEdge(2,1,2);
    g.addWeightedEdge(2,0,4);
    g.addWeightedEdge(0,2,4);
    g.addWeightedEdge(2,3,3);
    g.addWeightedEdge(3,2,3);
    g.addWeightedEdge(2,5,2);
    g.addWeightedEdge(5,2,2);
    g.addWeightedEdge(2,4,4);
    g.addWeightedEdge(4,2,4);
    g.addWeightedEdge(3,4,3);
    g.addWeightedEdge(4,3,3);
    g.addWeightedEdge(0,1,4);
    g.addWeightedEdge(5,2,2);
    g.addWeightedEdge(2,5,2);
    g.addWeightedEdge(5,4,3);
    

    g.kruskal();
    g.print();

    }