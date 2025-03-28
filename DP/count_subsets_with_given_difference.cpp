#include<bits/stdc++.h>
using namespace std;

int countPartitions(vector<int>& arr, int d) {

    vector<int> arrNew;
    int count_zeros = 0;
    for(int &i : arr){
        if(i != 0){
            arrNew.push_back(i);
        }
        else{
            count_zeros++;
        }
    }

    int target = accumulate(arrNew.begin(),arrNew.end(),0);
    int n = arrNew.size();

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
                dp[i][j] = dp[i-1][j-arrNew[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int zero_subsets = pow(2,count_zeros);

    int num_subsets = 0;
    int l = 0, r = target;

    while(l <= r){
        if((r - l) == d ){
            num_subsets = dp[n][l];
        }
        l++;
        r--;
    }

    return num_subsets * zero_subsets;
}

int main() {

    // your code goes here
    vector<int> arr = {1, 3, 3, 2, 1};
    int d = 5;
    cout << "numPartitions : " << endl << countPartitions(arr,d) << endl;

    return 0;
}