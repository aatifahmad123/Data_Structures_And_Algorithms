#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

int knapsack(int W,vector<int> &val,vector<int> &wt){

  int n = wt.size();
  vector<vector<int>> dp(n+1,vector<int>(W+1,-1));

  for(int i = 0;i < n+1;i++){
      dp[i][0] = 0;
  }

  for(int j = 0;j < W+1;j++){
      dp[0][j] = 0;
  }

  for(int i = 1;i < n+1;i++){
      for(int j = 1;j < W+1;j++){
          if(wt[i-1] <= j){
            dp[i][j] = max(dp[i-1][j-wt[i-1]] + val[i-1] , dp[i-1][j]);
          }
          else{
            dp[i][j] = dp[i-1][j];
          }
      }
  }

  return dp[n][W];
 
}

int main(){

  int W = 4;
  vector<int> val = {1,2,3};
  vector<int> wt = {4,5,1};

  int ans = knapsack(W, val, wt);

  cout << "Ans : " << ans << endl; 
  return 0;
}
