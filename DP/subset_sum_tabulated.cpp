#include<iostream>
#include<vector>
using namespace std;

bool isSubsetSum(vector<int> &arr, int sum){

    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int> (sum + 1,-1));

    for(int j = 0;j < sum + 1;j++){
        dp[0][j] = 0;
    }

    for(int i = 0;i < n + 1;i++){
        dp[i][0] = 1;
    }

    for(int i = 1;i < n + 1;i++){
        for(int j = 1;j < sum + 1;j++){
            if(arr[i-1] <= j){
                dp[i][j] = dp[i-1][j - arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][sum];
}

int main(){

    vector<int> arr = {3,34,4,12,5,2};
    int sum = 9;

    isSubsetSum(arr,sum) ? cout << "Subset exists" << endl : cout << "Subset does not exist" << endl; 

    return 0;
}
