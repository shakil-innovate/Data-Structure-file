#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ll long long
#define ull unsigned long long
#define pb push_back
#define nl '\n'
#define f first
#define se second
#define vl vector<ll>
#define all(v) v.begin(),v.end()
#define vi vector<int>
ll INF=1e17;
ll mod=676767677;

vector<vector<pair<ll,ll>>>g;
vl resticted;
vl goal_node;

void ucs(ll source){
    string path;
    char ch_source='A'+ source;
    path.pb(ch_source);

    priority_queue<pair<ll,pair<ll,string>>,vector<pair<ll,pair<ll,string>>>,greater<pair<ll,pair<ll,string>>>>pq;

    pq.push({0,{source,path}});

    string ans="";
    ll selected=0;
    ll cost=0;
    bool ok=0;

    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();

        ll w=it.f;

        string ppath=it.se.se;
        ll nxt=it.se.f;

        // cout<<"nxt:"<<nxt<<nl;

        for(auto itt:goal_node){
            if(itt==nxt){
                cost=w;
                ans=ppath;
                selected=nxt;
                ok=1;
                break;
            }
        }
        if(ok)break;

        for(auto itt:g[nxt]){
            string temp=ppath;
            temp.push_back('A'+itt.first);

            ll newCost = w + itt.second;

            pq.push({newCost,{itt.first,temp}});
        }
    }

    cout<<"cost is:"<<cost<<nl;
    char ans_ch=selected+'A';
    cout<<"selected node is:"<<ans_ch<<nl;
    cout<<"path is:";
    for(auto it:ans)cout<<it<<"->";cout<<nl;
}


void shakil(){
    ll nodes;       cin>>nodes;
    ll mx=0;

    for(ll i=0;i<nodes;i++){
        char ch;        cin>>ch;
        ll temp=ch-'A';
        mx=max(mx,temp);
    }

    g.resize(mx+1);

    ll edges;       cin>>edges;

    for(ll i=0;i<edges;i++){
        char uu,vv;     cin>>uu>>vv;
        ll u=uu-'A',v=vv-'A';
        ll w;       cin>>w;

        g[u].pb({v,w});
    }

    ll res_node;        cin>>res_node;
    for(ll i=0;i<res_node;i++){
        char ch;        cin>>ch;
        resticted.pb(ch-'A');
    }

    ll start;
    char start_ch;      cin>>start_ch;
    start=start_ch-'A';
    
    // cout<<"source:"<<start_ch<<nl;

    ll goal_n;      cin>>goal_n;

    for(ll i=0;i<goal_n;i++){
        char ch;        cin>>ch;
        goal_node.pb(ch-'A');
    }

    ucs(start);

}

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);

  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif

  ll tt=1;
  // cin>>tt;

  for(ll i=1;i<=tt;i++){
  // cout<<"Case "<<i<<": ";
  shakil();
  }
}
