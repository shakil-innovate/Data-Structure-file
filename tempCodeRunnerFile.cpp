#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>v,int low,int high)
{
   int pi=v[high];
   int i=low-1;

   for(int j=low;j<high;j++)
   {
    if(v[j]<pi)
    {
        i++;
        if(i!=j)swap(v[i],v[j]);
    }
   }

   swap(v[++i],v[high]);
   return i;
}

void quick_Sort(vector<int>&v,int low,int high)
{
  int pi;

  if(low<high)
  {
    pi=partition(v,low,high);
  }
}

