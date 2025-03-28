#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int target){

    int n = arr.size();

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
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][target];
}

int perfectSum(vector<int> &arr, int target){

    int n = arr.size();

    // target = 0
    if(target == 0){
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(arr[i] == 0){
                cnt++;
            }
        }
        int num_subsets = pow(2,cnt);
        return num_subsets;
    }

    // when target is non zero

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

    int num = solve(arrNew,target);
    return pow(2,count_zeros) * num;
    
}

int main(){

    vector<int> arr = {0, 30 ,18, 33, 29, 27, 39, 0};
    int target = 30;

    cout << "Number of subsets : " << perfectSum(arr,target) << endl;

    return 0;
}
