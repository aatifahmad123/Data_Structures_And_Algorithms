#include <algorithm>
#include<iostream>
#include<vector>
using namespace std;

int solve(int W, vector<int> &val, vector<int> &wt, int n){

  if((n == 0) || (W == 0)){
    return 0;
  }

  if(wt[n-1] <= W){
    return max(solve(W - wt[n-1],val,wt,n-1) + val[n-1],solve(W,val,wt,n-1));
  }

  else{
    return solve(W, val, wt, n-1);
  }

}

int knapsack(int W,vector<int> &val,vector<int> &wt){

  int n = wt.size();

  return solve(W,val,wt,n);
 
}

int main(){

  int W = 4;
  vector<int> val = {1,2,3};
  vector<int> wt = {4,5,1};

  int ans = knapsack(W, val, wt);

  cout << "Ans : " << ans << endl; 
  return 0;
}
