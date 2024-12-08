#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int check[N]={0};

int gain_profit(vector<pair<int,int>>&jobs);
bool compare(pair<int,int>a,pair<int,int>b);

int main()
{
    int no_of_job;
    cin>>no_of_job;

    vector<pair<int,int>>jobs(no_of_job);     // first-> profit   second->deadline

    for(int i=0;i<no_of_job;i++)
    {
        cin>>jobs[i].first>>jobs[i].second;
    }

   int ans=gain_profit(jobs);

   cout<<ans<<endl;
}

bool compare(pair<int,int>a,pair<int,int>b)
{
    return a.first>b.first;
}

int gain_profit(vector<pair<int,int>>&jobs)
{
    sort(jobs.begin(),jobs.end(),compare);

   int profit=0;

   for(auto& job:jobs)
   {
      for(int i=job.second;i>0;i--)
      {
        if(check[i]!=1){check[i]=1;profit+=job.first;break;}
      }
   }

   return profit;
}