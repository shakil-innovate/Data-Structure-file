#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;

    vector<int>v(n);
    for(int i=0;i<n;i++)  cin>>v[i];

    int cnt=0;

   for(int i=0;i<n-1;i++)
   {
    int mini=i;
    for(int j=i+1;j<n;j++)
    {
        if(v[mini]>v[j])  {mini=j;}
    }
    if(mini!=i){cnt++;swap(v[mini],v[i]);}
   }

   for(int i=0;i<n;i++) cout<<v[i]<<" ";

   cout<<endl;

   cout<<cnt<<endl;
}