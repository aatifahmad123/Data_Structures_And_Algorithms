#include<bits/stdc++.h>
using namespace std;

int solve(string text1,string text2,int m,int n){
    if((m == 0) || (n == 0)) return 0;

    if(text1[m-1] == text2[n-1]){
        return solve(text1,text2,m-1,n-1) + 1;
    }
    else{
        return max(solve(text1,text2,m,n-1),solve(text1,text2,m-1,n));
    }
}

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size();
    int n = text2.size();
    return solve(text1,text2,m,n);
}

int main() {

    // your code goes here
    string text1 = "abcde", text2 = "ace";
    cout << longestCommonSubsequence(text1,text2) << endl;


    return 0;
}