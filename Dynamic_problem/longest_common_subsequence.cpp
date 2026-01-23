//problem link:https://atcoder.jp/contests/dp/tasks/dp_f

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vl vector<ll>

void solve(){
  string s,t;     cin>>s>>t;
  vector<vl>dp(s.size()+1,vl(t.size()+1,0));

  for(int i=1 ; i<=s.size() ; i++){
    for(int j=1; j<=t.size() ; j++){
      if(s[i-1]==t[j-1])dp[i][j]=1+dp[i-1][j-1];
      else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }

  string lcm="";
  int i=s.size(),j=t.size();

   while(i>0 && j>0){
    if(s[i-1]==t[j-1]){lcm+=s[i-1];i--,j--;}
    else if(dp[i-1][j] > dp[i][j-1])i--;
    else j--;
   }

  reverse(lcm.begin(),lcm.end());
  cout<<lcm<<endl;
}

int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);

    solve();
}
