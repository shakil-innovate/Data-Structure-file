#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll recur(vector<int>&coin,int n,int sum,vector<vector<int>>&dp)
{
    if(sum==0)return 1;
    else if(sum<0 || n<0)return 0;
    else
    {
            if(dp[n][sum]!=-1)  return dp[n][sum];
            else return recur(coin,n,sum-coin[n],dp) +
                        recur(coin,n-1,sum,dp);
    }
}

int cnt(vector<int>&coin,int sum)
{
    vector<vector<int>>dp(coin.size(),vector<int>(sum+1,-1));
    return recur(coin,coin.size()-1,sum,dp);
}

int main() {
    vector<int>coin={1,2,3};
    int sum=5;
     cout<<cnt(coin,sum)<<endl;
}
