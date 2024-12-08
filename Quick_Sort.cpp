#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&v,int low,int high)
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
    quick_Sort(v,low,pi-1);
    quick_Sort(v,pi+1,high);
    
  }
}


int main()
{
    vector<int>arr={75,30,41,12,85,25,60,55,20,11,0};

    int siz=arr.size();

    quick_Sort(arr,0,siz-1);

    for(int i=0;i<siz;i++)
    {
        cout<<arr[i]<<" ";
    }
}