#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&v,int l,int mid,int h)
{
    int n1=mid-l+1;
    int n2=h-mid;

    vector<int>left(n1),right(n2);

    for(int i=0;i<n1;i++) left[i]=v[l+i];
    for(int i=0;i<n2;i++) right[i]=v[mid+1+i];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2)
    {
        if(left[i]<right[j])
         {
            v[k++]=left[i++];
         }
         else
          {
            v[k++]=right[j++];
          }
    }

    while(i<n1)
    {
        v[k++]=left[i++];
    }
    while(j<n2)
    {
        v[k++]=right[j++];
    }
}

void mergeSort(vector<int>&v,int l,int h)
{
    if(l<h)
    {
      int mid=(l+h)/2;

      mergeSort(v,l,mid);
      mergeSort(v,mid+1,h);

      merge(v,l,mid,h);
    }
}

void printmerge(vector<int>v)
{
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";

    cout<<endl;
}

int main()
{
    int n;cin>>n;

    vector<int>v(n);
    
    for(int i=0;i<n;i++)  cin>>v[i];

    mergeSort(v,0,n-1); 

    printmerge(v);
}