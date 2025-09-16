//--------------------------------------//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define nl '\n'
const ll mod=1e9+7;
const ll INF=1e9;
#define vi vector<ll>
#define vii vector<vi>
//---------------------------------------//

struct State
{
    ll no,profit,deadline;
};

struct cmp
{
    bool operator()(State const &a,State const &b)
    {
    return a.profit < b.profit;
    }
};

void shakil()
{
    cout<<"Number of job:"<<nl;
    ll n;   cin>>n;
    vector<State>job;
    for(int i=0;i<n;i++)
    {
        ll profit,deadline; cin>>profit>>deadline;
        job.push_back({i+1,profit,deadline});
    }

    priority_queue<State,vector<State>,cmp>pq;

    sort(job.begin(),job.end(),[](State const &a,State const &b){return a.deadline<b.deadline;});
    for(auto it:job)
    {
        cout<<it.no<<" "<<it.profit<<" "<<it.deadline<<nl;
    }

    ll total_profit=0;
    vector<ll>sq;

    for(int i=n-1;i>=0;i--)
    {
        pq.push(job[i]);
        ll deadline=job[i].deadline;
        if(i!=0)
        {
            deadline-=job[i-1].deadline;
        }

        while(deadline!=0 && !pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            deadline--;
            total_profit+=it.profit;
            sq.push_back(it.no);
        }
    }

    cout<<"Maximum Profit is: "<<total_profit<<nl;
    reverse(sq.begin(),sq.end());
    cout<<"Squence is :";
    for(auto it:sq)
    {
        cout<<it<<" ";
    }
    cout<<nl;


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
