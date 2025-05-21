#include<bits/stdc++.h>
using namespace std;

int BLOCK_SIZE;
struct Query
{
    int l,r,index;
    Query(int left,int right,int index_)
    {
        l=left;
        r=right;
        index=index_;
    }
};

bool compare(const Query &a ,const Query &b)
{
    int left_block_index=a.l/BLOCK_SIZE;
    int other_block_index=b.l/BLOCK_SIZE;

    if(left_block_index!=other_block_index)
    {
        return left_block_index < other_block_index;
    }
    return a.r> b.r ;
}

vector<int> solve(vector<int> &a,vector<Query>queries)
{
    sort(queries.begin(),queries.end(),compare);
     
    vector<int>freq(1000001,0);
    vector<int>ans(queries.size());

    int cnt=1;
    int start=queries[0].l,end=start;
    freq[a[start]]++;

    for(auto &query:queries)
    {
     //   cout<<start<<" "<<end<<endl;
        while(start < query.l)
        {
           // cout<<"1 "<<start<<" "<<query.l<<endl;
            freq[a[start]]--;

            if(freq[a[start]]==0)
              cnt--;
            start++;
        }
        while(start > query.l)
        {
           // cout<<"2 "<<start<<" "<<query.l<<endl;
              start--;
            freq[a[start]]++;

            if(freq[a[start]]==1)
              cnt++;

        }

        while(end<query.r)
        {
          //  cout<<"3 "<<start<<" "<<query.l<<endl;
            end++;
            freq[a[end]]++;

            if(freq[a[end]]==1)
              cnt++;
              
              
        }

         while(end > query.r)
        {
          //  cout<<"4 "<<start<<" "<<query.l<<endl;
         
            freq[a[end]]--;

            if(freq[a[end]]==0)
              cnt--;
                  end--;
              
             
        }

        ans[query.index]=cnt;
    }

    return ans;

}

int  main()
{
    int n;  cin>>n;
    vector<int>v(n);

    for(int i=0; i<n ;i++)  cin>>v[i];

    int q;      cin>>q;

    vector<Query>queries;

    for(int i=0; i<q ;i++)
    {
        int l;  cin>>l;
        int r;  cin>>r;

        queries.emplace_back(l-1,r-1,i);
    }

    BLOCK_SIZE=static_cast<int>(sqrt(v.size()));

    vector<int>ans=solve(v,queries);

    for(int  i=0 ; i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }



}
