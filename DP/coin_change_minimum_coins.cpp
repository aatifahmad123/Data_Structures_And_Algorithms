#include<bits/stdc++.h>
using namespace std;

int solve(int amount,vector<int> &coins, int n){
    if(amount == 0) return 0;

    if(n == 0) return 1e9;

    if(coins[n-1] <= amount){
        return min(solve(amount - coins[n-1],coins,n) + 1,solve(amount,coins,n-1));
    }

    else{
        return solve(amount,coins,n-1);
    }

}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int ans = solve(amount,coins,n);
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