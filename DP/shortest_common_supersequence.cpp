#include<bits/stdc++.h>
using namespace std;

string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    vector<vector<int>> dir(n+1,vector<int>(m+1,0));

    // 1 : upward arrow, 2 : leftward arrow, 3 : up-left-diagonal arrow

    for(int i = 1;i < n+1;i++){
        for(int j = 1;j < m+1;j++){
            if(str1[i-1] == str2[j-1]){
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
    set<int> first_set;
    set<int> second_set;

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
                first_set.insert(currpos.first - 1);
                second_set.insert(currpos.second - 1);
                currpos.first--;
                currpos.second--;
                break;
        }
    }

    int i = 0, j = 0;
    string ans = "";

    while((i < n) && (j < m)){
        if((first_set.find(i) != first_set.end()) && (second_set.find(j) != second_set.end())){
            // elements from both strings are present
            ans += str1[i++];
            j++;
        }
        else if((first_set.find(i) != first_set.end()) && (second_set.find(j) == second_set.end())){
            // only element from first string is present
            ans += str2[j++];
        }
        else if((first_set.find(i) == first_set.end()) && (second_set.find(j) != second_set.end())){
            // only element from second string is present
            ans += str1[i++];
        }
        else{
            // elements from both strings are absent
            ans += str1[i++];
            ans += str2[j++];
        }
    }

    while(i < n){
        ans += str1[i++];
    }

    while(j < m){
        ans += str2[j++];
    }

    return ans;
}

int main() {

    // your code goes here
    string str1 = "abcxdy", str2 = "bczdyr";
    cout << shortestCommonSupersequence(str1,str2) << endl;

    return 0;
}