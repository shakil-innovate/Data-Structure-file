#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&v,int n,int i)
{
    int largest=i;
    int left=i*2+1;
    int right=i*2+2;

    if(left<n && v[left]>v[largest])
    {
      largest=left;
    }
    else if(right<n && v[right]>v[largest])
    {
      largest=right;
    }
    
    if(largest!=i)
    {
        swap(v[largest],v[i]);
        heapify(v,n,largest);
    }
}

void heapSort(vector<int>&v,int n)
{
    for(int parent=n/2-1;parent>=0;parent--)
    {
        heapify(v,n,parent);
    }

    for(int i=n-1;i>=0;i--)
    {
        swap(v[0],v[i]);
        heapify(v,i,0);
    }
}

void PrintHeap(vector<int>v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void insertion(vector<int>&v,int n,int data)
{
    v.push_back(data);
    n++;
    int i=n-1;

    while(i!=0 && v[(i-1)/2]<v[i])
    {
        swap(v[(i-1)/2],v[i]);
        i=(i-1)/2;
    }
}

void deleteRoot(vector<int>&v,int &n)
{
    if(n<=0){return;}

    if(n==1){n--;v.pop_back();return;}

   v[0]=v[n-1];
   v.pop_back();
   n--;
   heapify(v,n,0);
}

int main()
{
    vector<int>arr={40,30,50,22,60,55,77,55,95,15};

    int n=arr.size();

    heapSort(arr,n);
    PrintHeap(arr);
}