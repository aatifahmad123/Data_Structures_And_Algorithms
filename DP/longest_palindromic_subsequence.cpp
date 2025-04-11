#include<bits/stdc++.h>
using namespace std;

int longestPalinSubseq(string &s) {
    string s1 = s;
    reverse(s.begin(),s.end());
    string s2 = s;
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i = 1;i < m+1;i++){
        for(int j = 1;j < n+1;j++){
            if(s1[i-1] == s2[j-1]){
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

    // your code goes here
    string s = "bbabcbcab";
    cout << longestPalinSubseq(s) << endl;

    return 0;
}