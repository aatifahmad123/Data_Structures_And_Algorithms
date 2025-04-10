#include<bits/stdc++.h>
using namespace std;

int solve(int amount,vector<int> &coins, int n, vector<vector<int>> &dp){
    if(amount == 0) return 0;

    if(n == 0) return 1e9;

    if(dp[n][amount] != -1) return dp[n][amount];

    if(coins[n-1] <= amount){
        return dp[n][amount] = min(solve(amount - coins[n-1],coins,n,dp) + 1,solve(amount,coins,n-1,dp));
    }

    else{
        return dp[n][amount] = solve(amount,coins,n-1,dp);
    }

}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));

    for(int j = 0;j < amount+1;j++){
        dp[0][j] = 1e9;
    }

    for(int i = 0;i < n+1;i++){
        dp[i][0] = 0;
    }

    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < amount+1;j++){
            if(coins[i-1] <= j){
                dp[i][j] = min(dp[i][j - coins[i-1]] + 1, dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int ans = dp[n][amount];
    if(ans >= 1e9) return -1;
    return ans;
}

int main() {

    // your code goes here
    vector<int> coins = {2};
    int amount = 3;
    cout << coinChange(coins,amount) << endl;

    return 0;
}