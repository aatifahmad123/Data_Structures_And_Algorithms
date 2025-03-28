#include<bits/stdc++.h>
using namespace std;

int minDifference(vector<int>& arr) {

    int sum = accumulate(arr.begin(),arr.end(),0);
    int n = arr.size();

    vector<vector<int>> dp(n + 1, vector<int> (sum + 1,-1));

    for(int j = 0;j < sum + 1;j++){
        dp[0][j] = 0;
    }

    for(int i = 0;i < n + 1;i++){
        dp[i][0] = 1;
    }

    for(int i = 1;i < n + 1;i++){
        for(int j = 1;j < sum + 1;j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int minDifference = INT_MAX;

    for(int j = 0;j < sum + 1;j++){
        if(dp[n][j] != 0){
            // a subset with that sum exists
            int complementary_sum = sum - j;
            minDifference = min(minDifference,abs(j - complementary_sum));
        }
    }

    return minDifference;
}

int main() {

    // your code goes here
    vector<int> arr = {1, 6, 11, 5};
    cout << "Minimum subset sum difference : " << minDifference(arr) << endl;

    return 0;
}