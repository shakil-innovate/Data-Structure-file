//tutorial:https://www.youtube.com/watch?v=wUc4sLRnm1M&t=27s
//--------------------------------------//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define nl '\n'
const ll mod=1e9+7;
const ll INF=1e9;
#define vi vector<ll>
#define vii vector<vi>
#define f first
#define s second

ll add(ll a,ll b){ return ((a%mod + b%mod)+ mod ) % mod;}
ll sub(ll a,ll b){ return ((a%mod - b%mod)+mod)% mod;}
ll mul(ll a,ll b){ return ((a%mod) * (b%mod))%mod ;}
ll power(ll a, ll b){ll res=1; a%=mod;while(b > 0){if(b & 1)res=(res*a) %mod; a=(a*a)%mod;b=b>>1;}return res;}
ll inv(ll a){return power(a,mod-2);}
//---------------------------------------//

struct Point
{
  ll x,y;
};
Point p0;

ll orientation(Point p,Point q,Point r)     
{
   Point pq={(q.x-p.x),(q.y-p.y)};     //create two vector
   Point qr={(r.x-q.x),(r.y-q.y)};

   ll val=(pq.x*qr.y)-(pq.y*qr.x);     //cross vector

   if(val==0)return 0;
   return (val>0)?1:2;
}

ll dist(Point p1,Point p2)
{
  return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

bool compare(Point p1,Point p2)
{
    ll o=orientation(p0,p1,p2);

    if(o==0)
    {
      return dist(p0,p1) < dist(p0,p2);
    }

    return (o==2);
}

vector<Point>convexHull(vector<Point>&points)
{
  ll n=points.size();

  if(n<3)return {};

  ll yMin=points[0].y , minInd=0;

  for(int i=1;i<n;i++)
  {
    if(points[i].y < yMin || (points[i].y==yMin && points[i].x < points[minInd].x ))
    {
      yMin=points[i].y,minInd=i;
    }
  }

  swap(points[0],points[minInd]);
  p0=points[0];

  sort(points.begin()+1,points.end(),compare);

  vector<Point>hull;
  hull.push_back(points[0]);
  hull.push_back(points[1]);
  hull.push_back(points[2]);

  for(ll i=3;i<n;i++)
  {
    while(hull.size()>1 && orientation(hull[hull.size()-2],hull.back(),points[i])!=2)  //untill left polar angle
    {
      hull.pop_back();
    }
    hull.push_back(points[i]);
  }

  return hull;
}

void shakil()
{
  cout<<"Enter num of point:"<<nl;

  ll N; cin>>N;


  vector<Point>points;

  cout<<"Enter point:"<<nl;
  for(int i=0;i<N;i++)
  {
    ll x,y;   cin>>x>>y;
    points.push_back({x,y});
  }
    vector<Point>hull=convexHull(points);

    cout<<"countable point: "<<hull.size()<<nl;
    cout<<"Convex Hull:"<<nl;

    for(auto it:hull)
    {
      cout<<it.x<<" "<<it.y<<nl;
    }
}

int  main()
{
   ios_base::sync_with_stdio(0);cin.tie(0); 
    ll tt=1;
    // cin>>tt;

    for(ll i=1;i<=tt;i++)
    {
      shakil();
    }
}
