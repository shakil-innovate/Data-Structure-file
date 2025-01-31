/** ----بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ----
* Author: SHAKIL AHMED
* Problem Name: 2D_segment_tree
* Created: 31, Friday
* Time: 09:58:31 (Bangladesh)
**/

#include<bits/stdc++.h>
using namespace std;
const int MAXN=1025;

int tree[4*MAXN][4*MAXN];
int n;

void updateY(int nodeX, int nodeY, int ly, int ry, int x, int y, int val);
int queryY(int nodeX, int nodeY, int ly, int ry, int y1, int y2);

void updateX(int nodeX,int lx,int rx,int x,int y,int val)
{
    if(rx==lx)
    {
        updateY(nodeX,1,0,n-1,lx,y,val);
    }
    else{
        int mid=(lx+rx)>>1;
        if(x<=mid)
             updateX(nodeX*2,lx,mid,x,y,val);
        else
            updateX(nodeX*2+1,mid+1,rx,x,y,val);

        for(int i=0;i<4*n;i++)
        {
            tree[nodeX][i]=tree[nodeX*2][i]+tree[nodeX*2+1][i];
        }
    }
}

void updateY(int nodeX,int nodeY,int ly,int ry,int x,int y,int val)
{
   if(ly==ry)
   {
    tree[nodeX][nodeY]=val;
   }
   else{
    int mid=(ly+ry)>>1;
      
      if(y<=mid)
         updateY(nodeX,2*nodeY,ly,mid,x,y,val);
      else
         updateY(nodeX,nodeY*2+1,mid+1,ry,x,y,val);

        tree[nodeX][nodeY]=tree[nodeX][nodeY*2]+tree[nodeX][nodeY*2+1];

   }
}

int queryX(int nodeX,int lx,int rx,int x1,int y1,int x2,int y2)
{
    if(lx>x2 || rx<x1)
    {
        return 0;
    }
    if(lx>=x1 && rx<=x2)
    {
      return queryY(nodeX,1,0,n-1,y1,y2);
    }

    int mid=(lx+rx)>>1;

    return queryX(2*nodeX,lx,mid,x1,y1,x2,y2)+queryX(2*nodeX+1,mid+1,rx,x1,y1,x2,y2);
}

int queryY(int nodeX,int nodeY,int ly,int ry,int y1,int y2)
{
    if(ly>y2 || ry<y1)
    return 0;

    if(ly>=y1 && ry<=y2)
    {
        return tree[nodeX][nodeY];
    }

    int mid=(ry+ly)>>1;
    return queryY(nodeX,nodeY*2,ly,mid,y1,y2)+queryY(nodeX,nodeY*2+1,mid+1,ry,y1,y2);
}

void update(int x,int y,int val)
{
   updateX(1,0,n-1,x,y,val);
}

int query(int x1,int y1,int x2,int y2)
{
    return queryX(1,0,n-1,x1,y1,x2,y2);
}

int main()
{
    int tt;
    cin>>tt;

    while(tt--)
    {
        cin>>n;
        fill(&tree[0][0],&tree[0][0]+sizeof(tree)/sizeof(int),0);

        string command;

        while(cin>>command)
        {
            if(command=="END")break;
            else if(command=="SET")
            {
                int x,y,num;    cin>>x>>y>>num;
                update(x,y,num);
            }

            if(command=="SUM")
            {
                int x1,y1, x2, y2;
                cin>>x1>>y1>>x2>>y2;
                cout<<query(x1,y1,x2,y2)<<endl;

            }

        }
    }

}