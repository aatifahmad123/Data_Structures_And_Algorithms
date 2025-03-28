#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &nums, int target, int n){
    if((target == 0) && (n == 0)) return 1;
    if(n == 0) return 0;

    return solve(nums,target + nums[n-1],n-1) + solve(nums,target - nums[n-1],n-1);
}

int findTargetSumWays(vector<int>& nums, int target) {

    int n = nums.size();
    target = abs(target);

    return solve(nums,target,n);

}

int main() {

    // your code goes here
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout << "Number of ways : " << findTargetSumWays(nums,target) << endl;

    return 0;
}