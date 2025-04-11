#include<bits/stdc++.h>
using namespace std;

string findLCS(int n, int m,string &s1, string &s2){

    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    vector<vector<int>> dir(n+1,vector<int>(m+1,0));

    // 1 : upward arrow, 2 : leftward arrow, 3 : up-left-diagonal arrow

    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < m+1;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                dir[i][j] = 3;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(dp[i][j-1] >= dp[i-1][j]){
                    dir[i][j] = 2;
                }
                else{
                    dir[i][j] = 1;
                }
            }
        }
    }

    // dp and dir vectos are ready

    pair<int,int> currpos = {n,m}; // current indices

    string ans = "";

    while((currpos.second != 0) && (currpos.first != 0)){
        int direction = dir[currpos.first][currpos.second];
        switch(direction){
            case 1:
                currpos.first--;
                break;
            case 2:
                currpos.second--;
                break;
            case 3:
                ans = s1[currpos.first - 1] + ans;
                currpos.first--;
                currpos.second--;
                break;
        }
    }

    return ans;

}

int main() {

    string s1 = "abcdxy";
    string s2 = "bcdxz";
    int n = s1.size();
    int m = s2.size();
    cout << findLCS(n,m,s1,s2) << endl;

    return 0;
}