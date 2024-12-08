#include<bits/stdc++.h>
using namespace std;

void print(vector<int>v)
{
    int n=v.size();
    for(int i=0;i<n;i++)
    {
    cout<<v[i];
    if(i<n-1)cout<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;cin>>n;

    vector<int>v(n);

    for(int i=0;i<n;i++)  cin>>v[i];

    for(int i=0;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(v[j]<v[j-1])  {swap(v[j],v[j-1]);}
        }
        print(v);
    }
}