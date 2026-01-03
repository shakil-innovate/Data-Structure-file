#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define longd long double
#define vl vector<ll>
ll INF=1e10;

struct node{
	node* child[2];

	node(){
		child[0]=child[1]=NULL;
	}
};

void insert(node* root,ll num){

	  node* cur=root;
		for(ll i=31;i>=0;i--){
			ll bit=((num>>i) & 1);

			if(!cur->child[bit]){
				cur->child[bit]=new node();
			}
			cur=cur->child[bit];
		}
}

//find mx_xor
ll max_xor(node* root,ll num){
	node* cur=root;

	ll ans=0;
	for(ll i=31;i>=0;i--){
		ll bit=((num>>i) & 1);
		ll want=1-bit;

		if(cur->child[want]){
			ans|=(1LL<<i);

			cur=cur->child[want];
		}
		else cur=cur->child[bit];
	}
	return ans;
}


void shakil(){	
	ll n;	cin>>n;
	vl v(n);

	node* root=new node();

	for(auto &i:v)	{cin>>i;insert(root,i);}

	ll mx=0;
	
	for(auto x:v){
		mx=max(mx,max_xor(root,x));
	}

	cout<<"max_xor:"<<mx<<nl;
	
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);

	ll tt=1;
	cin>>tt;

	while(tt--){
		shakil();
	}
}
