#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>>adj;

int edge,verteces;

void print(vector<vector<int>>&path,int u,int v)
{
    if(path[u][v]==-1)
    {
        cout<<"-1"<<endl;
        return;
    }
    
    vector<int>fullPath;

    while(v!=-1)
    {
        fullPath.push_back(v);
        v=path[u][v];
    }

    reverse(fullPath.begin(),fullPath.end());

    for(int node:fullPath)
    {
        cout<<node<<" ";
    }
    cout<<endl;
}

void floyd_warshall()
{
    vector<vector<int>>dist(verteces+1,vector<int>(verteces+1,1e5));
    vector<vector<int>>path(verteces+1,vector<int>(verteces+1,-1));

    for(int i=1;i<=verteces;i++)
    {
        dist[i][i]=0;
    }

    for(int i=1;i<=verteces;i++)
    {
        for(auto it:adj[i])
        {
            dist[i][it.first]=it.second;
            path[i][it.first]=i;
        }
    }

    for(int k=1;k<=verteces;k++)
    {
        for(int i=1;i<=verteces;i++)
        {
            for(int j=1;j<=verteces;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                    path[i][j]=path[k][j];
                }
            }
        }
    }

    for(int i=1;i<=verteces;i++)
    {
         for(int j=0;j<=verteces;j++)
         {
           cout<<dist[i][j]<<" ";
         }
         cout<<endl;
    }

    cout<<"path :"<<endl;

    for(int i=1;i<=verteces;i++)
      { 
        for(int j=1;j<=verteces;j++)
           {
            cout<<"path from "<<i <<" to "<<j<<endl;
            if(dist[i][j]==1e5)cout<<"NO path"<<endl;
            else
            {
                print(path,i,j);

            } 
           }
      }
}

int main()
{
    
    cin>>edge>>verteces;
   
    adj.resize(verteces+1);

    for(int i=0;i<edge;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    floyd_warshall();

    

}