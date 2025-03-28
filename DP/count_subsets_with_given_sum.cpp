#include<iostream>
#include<vector>
using namespace std;

int perfectSum(vector<int> &arr, int target){

    int n = arr.size();

    vector<vector<int>> dp(n+1,vector<int>(target+1,-1));

    for(int j = 0;j < target + 1;j++){
        dp[0][j] = 0;
    }

    for(int i = 0;i < n+1;i++){
        dp[i][0] = 1;
    }

    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < target+1;j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][target];
}

int main(){

    vector<int> arr = {5,2,3,10,6,8};
    int target = 10;

    cout << "Number of subsets : " << perfectSum(arr,target) << endl;

    return 0;
}
