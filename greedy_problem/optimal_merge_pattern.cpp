#include<bits/stdc++.h>
using namespace std;

vector<int>combine (const vector<int>&v1,const vector<int>&v2)
{
    int siz1=v1.size();
    int siz2=v2.size();

     vector<int> result(siz1 + siz2);

    int i=0,j=0,k=i;

    while(i<siz1 && j<siz2)
    {
        if(v1[i]>v2[j])
        {
          result[k++]=v2[j++];
        }

        else 
        {
            result[k++]=v1[i++];
        }
    }

        while(i<siz1)
        {
            result[k++]=v1[i++];
        }
        while(j<siz2)
        {
            result[k++]=v2[j++];
        }

        return result;
}

void merge(vector<int>&v,int l,int mid,int r)
{
    int siz1=mid-l+1;
    int siz2=r-mid;

    vector<int>v1(siz1),v2(siz2);

    for(int i=0;i<siz1;i++)
    {
        v1[i]=v[l+i];
    }

    for(int i=0;i<siz2;i++)
    {
        v2[i]=v[mid+1+i];
    }

    int i=0,j=0,k=l;

    while(i<siz1 && j<siz2)
    {
        if(v1[i]>v2[j])
        {
          v[k++]=v2[j++];
        }

        else 
        {
            v[k++]=v1[i++];
        }
    }

        while(i<siz1)
        {
            v[k++]=v1[i++];
        }
        while(j<siz2)
        {
            v[k++]=v2[j++];
        }
}

void merge_sort(vector<int>&v,int l,int r)
{

  if(l>=r)return;
  int mid=(l+r)/2;

  merge_sort(v,l,mid);
  merge_sort(v,mid+1,r);
  merge(v,l,mid,r);

}

int main()
{

  vector<int>v={1,2,5,3,2},v1={6,2,6,2,1},v2={0,9,2,1,5};

  int n1=v.size()-1;
  int n2=v.size()-1;
  int n3=v.size()-1;


  merge_sort(v,0,n1);
  merge_sort(v1,0,n2);
  merge_sort(v2,0,n3);

  v=combine(v,v1);
  v=combine(v,v2);



  for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
}