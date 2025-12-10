#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define nl '\n'

const ll N=1e5+1;
ll n;

vector<ll>bit(N,0);

void update(ll ind,ll val){
    while(ind<=n) {
        bit[ind]+=val;
        ind=ind+(ind & (-ind));
    }
}

ll sum(ll ind){
    ll res=0;
    while(ind>0){
        res+=bit[ind];
        ind=ind-(ind&(-ind));
    }
    return res;
}

ll range_sum(ll low,ll high){
    return sum(high)-sum(low-1);
}

void shakil(){
    cin>>n;

    vector<ll>v(n+1);

    for(int i=1;i<=n;i++) cin>>v[i];

    for(int i=1; i<=n; i++){
        update(i,v[i]);
    }

    ll first_el_sum;    cin>>first_el_sum;
    cout<<"sum of first nth el item :"<<sum(first_el_sum)<<nl;

    ll up_in,up_val;    cin>>up_in>>up_val;
    update(up_in,up_val);

    ll sum_from,sum_to; cin>>sum_from>>sum_to;
    cout<<"range_sum of from to to :"<<range_sum(sum_from,sum_to)<<nl;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll tt;  cin>>tt;
    while(tt--)
       shakil();
}
