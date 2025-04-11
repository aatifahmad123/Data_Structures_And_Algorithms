#include<bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string& s1, string& s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));

    for(int i = 1;i < m+1;i++){
        for(int j = 1;j < n+1;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    int ans = INT_MIN;

    for(int i = 0;i < m+1;i++){
        for(int j = 0;j < n+1;j++){
            ans = max(ans,dp[i][j]);
        }
    }

    return ans;
}

int main() {

    string s1 = "ABCDGH", s2 = "ACDGHR";
    cout << longestCommonSubstr(s1,s2) << endl;

    return 0;
}