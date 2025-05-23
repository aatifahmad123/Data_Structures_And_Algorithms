#include<bits/stdc++.h>
using namespace std;

int longestRepeatingSubsequence(string st, int n){
    string text1 = st;
    string text2 = st;
    int m = n;
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i = 1;i < m+1;i++){
        for(int j = 1;j < n+1;j++){
            if((text1[i-1] == text2[j-1]) && (i != j)){
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

    string st = "aabcbdc";
    int n = st.size();
    cout << longestRepeatingSubsequence(st,n) << endl;

    return 0;
}