//problem:https://cses.fi/problemset/task/3191/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define longd long double
#define vl vector<ll>
ll INF=1e10;

void shakil(){	
	ll n;	cin>>n;
	vl v(n);

	for(auto &i:v)	cin>>i;
	vl basis(63,0);

	for(auto x:v){
	 for(ll i=62;i>=0;i--){
		if(((x>>i) & 1)==0) continue;

		if(basis[i]==0){
		 basis[i]=x;
		 break;
		}

		x^=basis[i];
	}
 }

 ll ans=0;

 for(ll i=62;i>=0;i--){
 ans=max(ans,ans^basis[i]);
 }
   
  cout<<ans<<nl;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);

	ll tt=1;
	// cin>>tt;

	while(tt--){
		shakil();
	}
}
