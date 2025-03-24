#include<iostream>
#include<vector>
using namespace std;

bool solve(vector<int> &arr, int sum, int n, vector<vector<int>> &dp){
    
    if(sum == 0) return true;
    if(n == 0) return false;

    if(dp[n][sum] != -1) return dp[n][sum];

    if(arr[n-1] <= sum){
        return dp[n][sum] = solve(arr,sum - arr[n-1],n-1, dp) || solve(arr,sum,n-1,dp);
    }

    else{
        return dp[n][sum] = solve(arr,sum,n-1, dp);
    }
}

bool isSubsetSum(vector<int> &arr, int sum){

    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int> (sum + 1,-1));

    return solve(arr,sum,n, dp);
}

int main(){

    vector<int> arr = {3,34,4,12,5,2};
    int sum = 9;

    isSubsetSum(arr,sum) ? cout << "Subset exists" << endl : cout << "Subset does not exist" << endl; 

    return 0;
}
