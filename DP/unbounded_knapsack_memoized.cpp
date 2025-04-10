#include<bits/stdc++.h>
using namespace std;

int solve(int W, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp){

    if((n == 0) || (W == 0)){
      return 0;
    }
  
    if(dp[n][W] != -1){
      return dp[n][W];
    }
  
    if(wt[n-1] <= W){
      return dp[n][W] = max(solve(W - wt[n-1],val,wt,n,dp) + val[n-1],solve(W,val,wt,n-1,dp));
    }
  
    else{
      return dp[n][W] = solve(W, val, wt, n-1, dp);
    }
  
}

int knapSack(vector<int>& val, vector<int>& wt, int W) {
    // code here

    int n = wt.size();
    vector<vector<int>> dp(n+1,vector<int>(W+1,-1));

    for(int i = 0;i < n+1;i++){
        dp[i][0] = 0;
    }

    for(int j = 0;j < W+1;j++){
        dp[0][j] = 0;
    }

    return solve(W,val,wt,n,dp);
}

int main() {

    // your code goes here
    vector<int> val = {6,1,7,7};
    vector<int> wt = {1,3,4,5};
    int capacity = 8;

    cout << "Max value : " << knapSack(val,wt,capacity) << endl;

    return 0;
}