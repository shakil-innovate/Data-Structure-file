#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll recur(vector<int>&weight,vector<int>&profit,int w,int n,vector<vector<int>>&dp)
{
    if(n<0) return 0;
    else if(dp[n][w]!=-1)return dp[n][w];
    else if(weight[n] > w) dp[n][w]=recur(weight,profit,w,n-1,dp);
    else{
        dp[n][w]=max(profit[n]+recur(weight,profit,w-weight[n],n-1,dp),recur(weight,profit,w,n-1,dp));
    }

    return dp[n][w];
}


int main() {
    vector<int>profit={60,100,120};
    vector<int>weight{10,20,30};
    int w=50;

    vector<vector<int>>dp(weight.size(),vector<int>(w+1,-1));
    cout<<recur(weight,profit,w,weight.size()-1,dp)<<endl;
}
