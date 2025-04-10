#include<bits/stdc++.h>
using namespace std;

long long int minm(long long int a, long long int b){
    if(a <= b) return a;
    return b;
}

int change(int amount, vector<int>& coins) {
    
    int n = coins.size();
    vector<vector<long long int>> dp(n+1,vector<long long int>(amount+1,0));

    for(int j = 0;j < amount+1;j++){
        dp[0][j] = 0;
    }

    for(int i = 0;i < n+1;i++){
        dp[i][0] = 1;
    }

    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < amount+1;j++){
            if(coins[i-1] <= j){
                long long int upper_cap = 2e9;
                dp[i][j] = minm(dp[i][j - coins[i-1]] + dp[i-1][j],upper_cap);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][amount];
}

int main() {

    // your code goes here
    int amount = 5;
    vector<int> coins = {1,2,5};
    cout << change(amount,coins) << endl;


    return 0;
}