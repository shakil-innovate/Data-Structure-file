//tutorial:https://www.youtube.com/watch?v=052VkKhIaQ4&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=66

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<ll>>solution;

bool isSafe(ll node,vector<ll>&color,vector<vector<ll>>&graph,ll c,ll V)
{
    for(ll adj=0;adj<V; adj++)
    {
        if(graph[node][adj] && color[adj]==c)
        {
            return false;
        }
    }

    return true;
}

void solve(ll node,vector<ll>&color,ll M,vector<vector<ll>>&graph,ll V)
{
    if(node==V)
    {
        solution.push_back(color);
        return;
    }

    for(ll c=1 ;c<=M; c++)
    {
        if(isSafe(node,color,graph,c,V))
        {
            color[node]=c;
            solve(node+1,color,M,graph,V);
            color[node]=0;  //backtracking
        }
    }

}

void graph_coloring(vector<vector<ll>>&graph,ll M,ll V)
{
    vector<ll>color(V,0);
    solve(0,color,M,graph,V);

    cout<<solution.size()<<endl;

    for(auto &sol:solution)
    {
        for(auto &it:sol)   cout<<it<<" ";
        cout<<endl;
    }
}

int main(){
    ll V,E,M;   cin>>V>>E;

    vector<vector<ll>>graph(V,vector<ll>(V,0));

    for(int i=0; i<E ; i++)
    {
        ll u,v; cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }

    //Enter number of color
    cin>>M;

    graph_coloring(graph,M,V);


}
