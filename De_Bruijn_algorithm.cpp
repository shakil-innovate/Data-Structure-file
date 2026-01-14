//problem_link:https://cses.fi/problemset/task/1692/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define pb push_back

unordered_map<string,ll>used;
ll n,k=2;
string ans;

void dfs(string &u){
    for(ll c=0;c<k;c++){
        char ch='0'+c;
        
        string edge=u+ch;

        if(!used[edge]){
            used[edge]=1;

            string v=edge.substr(1);
            dfs(v);

            ans.pb(ch);
        }
    }
}

void shakil(){
       cin>>n;
        string start(n-1,'0');
       dfs(start);

    //    cout<<start<<nl;
       ans+=start;
       reverse(ans.begin(),ans.end());

       cout<<ans<<nl;
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif

    ll tt=1;
    // cin>>tt;

    while(tt--){
        shakil();
    }

}
