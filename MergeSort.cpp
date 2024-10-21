#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&v,int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;

    vector<int>left(n1),right(n2);

    for(int i=0;i<n1;i++)left[i]=v[l+i];
    for(int i=0;i<n2;i++)right[i]=v[mid+1+i];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            v[k]=left[i];
            i++;
        }
        else{
            v[k]=right[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        v[k]=left[i];
        k++;i++;
    }
    while(j<n2)
    {
        v[k]=right[j];
        j++;k++;
    }

}

void mergeSort(vector<int>&v,int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
         mergeSort(v,l,mid);
         mergeSort(v,mid+1,r);
         
         merge(v,l,mid,r);
    }
}

void Printmerge(vector<int>v)
{
    for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
    cout<<endl;
}

int main()
{
  vector<int>v= {38, 27, 43, 3, 9, 82, 10};

  mergeSort(v,0,v.size()-1);

  Printmerge(v);
  
}