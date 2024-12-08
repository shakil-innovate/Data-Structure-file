#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&v,int n,int i)
{
   int largest=i;
   int r=2*i+1;
   int l=2*i+2;

   if(l<n && v[largest]<v[l])
   {
    largest=l;
   }

   if(r<n && v[largest]<v[r])
   {
    largest=r;
   }

   if(largest!=i)
   {
    swap(v[largest],v[i]);
    heapify(v,n,largest);
   }

}

void heapSort(vector<int>&v,int n)
{
    int parent=n/2-1;

    for(;parent>=0;parent--)
    {
        heapify(v,n,parent);
    }

    for(int i=n-1;i>=0;i--)
    {
        swap(v[0],v[i]);
        heapify(v,i,0);
    }
}



int main()
{
    int n;cin>>n;
   
    vector<int>v(n);

    for(int i=0;i<n;i++)  cin>>v[i];

    heapSort(v,n);

    //print

    for(int i=0;i<n;i++) cout<<v[i]<<" ";

    cout<<endl;
}