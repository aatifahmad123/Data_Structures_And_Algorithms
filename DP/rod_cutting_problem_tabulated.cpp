#include<bits/stdc++.h>
using namespace std;

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

    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < N+1;j++){
            if(lengths[i-1] <= j){
                dp[i][j] = max(dp[i][j - lengths[i-1]] + price[i-1],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][N];

}

int main() {

    // your code goes here
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << "Maximum Value : " << cutRod(price) << endl;

    return 0;
}