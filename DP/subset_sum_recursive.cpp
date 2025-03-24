#include<iostream>
#include<vector>
using namespace std;

bool solve(vector<int> &arr, int sum, int n){
    
    if(sum == 0) return true;
    if(n == 0) return false;

    if(arr[n-1] <= sum){
        return solve(arr,sum - arr[n-1],n-1) || solve(arr,sum,n-1);
    }

    else{
        return solve(arr,sum,n-1);
    }
}

bool isSubsetSum(vector<int> &arr, int sum){

    int n = arr.size();

    return solve(arr,sum,n);
}

int main(){

    vector<int> arr = {3,34,4,12,5,2};
    int sum = 9;

    isSubsetSum(arr,sum) ? cout << "Subset exists" << endl : cout << "Subset does not exist" << endl; 

    return 0;
}
