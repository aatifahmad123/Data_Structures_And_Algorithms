#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string &text1, string &text2) {
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i = 1;i < m+1;i++){
        for(int j = 1;j < n+1;j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main() {

    const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

    // your code goes here
    string text1 = "abcde", text2 = "ace";
    cout << longestCommonSubsequence(text1,text2) << endl;


    return 0;
}