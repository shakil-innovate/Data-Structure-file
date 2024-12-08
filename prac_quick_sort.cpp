#include<bits/stdc++.h>
using namespace std;

int parti(vector<int>&v,int l,int h)
{
   int i=l,j=l-1;

   for(;i<h;i++)
   {
    if(v[i]<=v[h])
      {
        j++;
        swap(v[i],v[j]);
      }
   }
   swap(v[++j],v[h]);

   return j;
}

void quickSort(vector<int>&v,int l,int h)
{
    int pi;

   if(l<h)
    {
        pi=parti(v,l,h);
        quickSort(v,l,pi-1);
        quickSort(v,pi+1,h);
    }
}

int main()
{
    int n;
    cin>>n;

    vector<int>v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }

    quickSort(v,0,n-1);

    for(int i=0;i<n;i++) cout<<v[i]<<" ";
    cout<<endl;
}