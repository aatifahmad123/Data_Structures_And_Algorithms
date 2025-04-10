#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices, vector<int> &lengths, int N, int n, vector<vector<int>> &dp){
    if(N == 0 || n == 0){
        return 0;
    }

    if(dp[n][N] != -1){
        return dp[n][N];
    }

    if(lengths[n-1] <= N){
        return dp[n][N] = max(solve(prices,lengths,N-lengths[n-1],n, dp) + prices[n-1],solve(prices,lengths,N,n-1, dp));
    }

    else{
        return dp[n][N] = solve(prices,lengths,N,n-1, dp);
    }
}

int cutRod(vector<int> &price) {
    
    int n = price.size();
    int N = n;
    vector<int> lengths(n,0);
    for(int i = 0;i < n;i++){
        lengths[i] = i + 1;
    }

    vector<vector<int>> dp(n+1,vector<int>(N+1,-1));

    for(int i = 0;i < n+1;i++){
        dp[i][0] = 0;
    }

    for(int j = 0;j < N+1;j++){
        dp[0][j] = 0;
    }

    return solve(price,lengths,N,n,dp);

}

int main() {

    // your code goes here
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << "Maximum Value : " << cutRod(price) << endl;

    return 0;
}