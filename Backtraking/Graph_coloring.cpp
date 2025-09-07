//tutorial:https://www.youtube.com/watch?v=052VkKhIaQ4&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=66
//--------------------------------------//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define nl '\n'

//---------------------------------------//
ll V,E,cl;
vector<vector<ll>>g,solution;
vector<ll>color;

bool isSafe(ll n,ll c)
{
    for(int adj=0;adj<V;adj++)
    {
        if(g[n][adj]==1 && color[adj]==c)
        {
            return false;
        }
    }
    return true;
}

void solve(ll n,ll k)
{
    // if(n >= V) return;
    if(n==V)
    {
        solution.push_back(color);
        return;
    }

    for(int c=0;c<k;c++)
    {
        if(isSafe(n,c))
        {
            color[n]=c;
            solve(n+1,k);
            color[n]=-1;
        }
    }
}

void shakil()
{
    cin>>V>>E;
    g.resize(V,vector<ll>(V,0));
    color.resize(V,-1);

    for(int i=0;i<E;i++)
    {
        ll u,v; cin>>u>>v;
        g[u][v]=g[v][u]=1;
    }

    ll min_color=1;
    solution.clear();

    while(1)
    {
        solution.clear();
        solve(0,min_color);
        if(solution.size()==0)
          min_color++;
        else break;
    }
    cout<<"cramatic number: "<<min_color<<nl;
    cout<<"total solution is "<<solution.size()<<nl;

    for(int i=0;i<solution.size();i++)
    {
        for(int j=0;j<V;j++)cout<<solution[i][j]<<" ";
        cout<<nl;
    }
    
}

int  main()
{
   ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tt=1;
    // cin>>tt;

    for(ll i=1;i<=tt;i++)
    {
      shakil();
    }
}
