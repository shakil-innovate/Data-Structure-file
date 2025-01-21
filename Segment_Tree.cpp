#include<bits/stdc++.h>
using namespace std;



vector<int>tree(1000),segTree(1000<<2);

void buildSeg(int low,int high,int index)
{
    if(low==high)
       segTree[index]=tree[low];

       else{
        int mid=(low+high)>>1;
         buildSeg(low,mid,index*2+1);
         buildSeg(mid+1,high,index*2+2);

         segTree[index]=min(segTree[index*2+1],segTree[index*2+2]);
       }
}

int rangeQuery(int qlow,int qhigh,int low,int high,int pos)
{
    if(qlow<=low && qhigh>=high)
    return segTree[pos];

    if(qlow>high || qhigh<low)
         return INT_MAX;

   int mid=(low+high)>>1;

     return (min(rangeQuery(qlow,qhigh,low,mid,pos*2+1),rangeQuery(qlow,qhigh,mid+1,high,pos*2+2)));
}

void updateQuery(int low,int high,int index,int pos,int value)
{

    if(pos<low || pos>high)
       return;

    if(low==high)
       segTree[index]=value;

    

    else{
        int mid=(low+high)>>1;
        updateQuery(low,mid,index*2+1,pos,value);
        updateQuery(mid+1,high,index*2+2,pos,value);

        segTree[index]=min(segTree[index*2+1],segTree[index*2+2]);


    }
}

int main()
{
    int n;      cin>>n;

    for(int i=0;i<n;i++)    cin>>tree[i];

    buildSeg(0,n-1,0);

    for(int i=0;i<4*n;i++)
    {
        cout<<segTree[i]<<" ";
    }
    cout<<endl;

    cout<<rangeQuery(1,3,0,5,0)<<endl;

    updateQuery(0,5,0,4,-2);

     for(int i=0;i<4*n;i++)
    {
        cout<<segTree[i]<<" ";
    }


    
}