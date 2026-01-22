//https://codeforces.com/gym/102644/problem/C

#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
typedef long long ll;
ll mod=1e9+7;

struct Matrix{
    ll a[2][2];
};

Matrix multiply(Matrix x,Matrix y){
 Matrix r;
 r.a[0][0]=(x.a[0][0] * y.a[0][0] + x.a[0][1]*y.a[1][0])%mod;
 r.a[0][1]=(x.a[0][0] * y.a[0][1] + x.a[0][1]*y.a[1][1])%mod;
 r.a[1][0]=(x.a[1][0] * y.a[0][0] + x.a[1][1]*y.a[1][0])%mod;
 r.a[1][1]=(x.a[1][0] * y.a[0][1] + x.a[1][1]*y.a[1][1])%mod;
    
 return r;
}

Matrix power(Matrix base,ll exp){
  Matrix rs={{{1,0},{0,1}}};
  while(exp){
   if(exp & 1) rs=multiply(rs,base);
    base=multiply(base,base);
    exp=exp>>1;
   }
  return rs;
}

ll fib(ll n){
 if(n==0)return 0;
 else if(n==1)   return 1;

 Matrix M=  {{{0,1},{1,1}}};
 Matrix Mn=power(M,n-1);

 return Mn.a[1][1];
}

void shakil(){
 ll n;       cin>>n;
 cout<<fib(n)<<nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt=1;
    // cin>>tt;

    while(tt--){
        shakil();
    }

}
