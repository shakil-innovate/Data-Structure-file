//tutorial:https://www.youtube.com/watch?v=052VkKhIaQ4&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=66

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll V,M,E;
vector<vector<ll>>solution;

bool isSafe(ll node,vector<vector<ll>>&graph,vector<ll>&color,ll c)
{
    for(int adj=0; adj<V; adj++)
    {
            if(graph[adj][node] && color[adj]==c)
              return false;
    }

    return true;
}

void solve(ll node,vector<vector<ll>>&graph,vector<ll>&color)
{
    if(node==V)
    {
        solution.push_back(color);
        return;
    }

    for(int c=1;c<=M; c++)
    {
        if(isSafe(node,graph,color,c))
        {
            color[node]=c;
            solve(node+1,graph,color);
            color[node]=0;   // backtracking
        }
    }
}

void graph_coloring(vector<vector<ll>>&graph)
{
    vector<ll>color(V,0);

    solve(0,graph,color);

    cout<<solution.size()<<endl;

    for(int i=0; i<solution.size();i++)
    {
        for(auto it:solution[i])cout<<it<<" ";
        cout<<endl;
    }
}

int main(){
 
    cin>>V>>E;
    vector<vector<ll>>graph(V,vector<ll>(V,0));

    for(int i=0; i<E ; i++)
    {
        ll u,v; cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }

    cin>>M;
    graph_coloring(graph);

}
