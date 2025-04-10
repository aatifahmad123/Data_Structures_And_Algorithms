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
    int ans = solve(amount,coins,n,dp);
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