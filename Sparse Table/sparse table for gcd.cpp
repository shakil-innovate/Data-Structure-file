#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>

vector<vl>preprocess(vector<ll>&input,int n){
 vector<vl>sparse(n,vector<ll>(log2(n)+1));
 
 for(int i=0 ; i< n ; i++)   sparse[i][0]=input[i];

 for(int j=1 ; (1<<j)<= n ; j++){
  for(int i=0 ; (i+(1<<j)-1) < n ; i++) {
   sparse[i][j]=__gcd(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
  }
 }
return sparse;
}

ll query(int low,int high,vector<vector<ll>>&sparse){
 ll l=high-low+1;
 ll k=log2(l);
 return __gcd(sparse[low][k],sparse[high-(1<<k)+1][k]);
}

void shakil(){
 ll n,q;  cin>>n>>q;
 vector<ll>v(n);
 for(int i=0 ;i<n ; i++) cin>>v[i];
  
 vector<vector<ll>>sparse=preprocess(v,n);
 while(q--){
 ll low,high;    cin>>low>>high;
 cout<<query(low-1,high-1,sparse)<<endl;
 }
}

int main(){
    int tt; cin>>tt;
    while(tt--)
      shakil();
}
