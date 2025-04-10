#include<bits/stdc++.h>
using namespace std;

int solve(int amount,vector<int> &coins,int n){
    
    if(amount == 0){
        return 1;
    }
    
    if(n == 0){
        return 0;
    }

    if(coins[n-1] <= amount){
        return solve(amount - coins[n-1],coins,n) + solve(amount,coins,n-1);
    }

    else{
        return solve(amount,coins,n-1);
    }
}

int change(int amount, vector<int>& coins) {
    
    int n = coins.size();

    return solve(amount,coins,n);
}

int main() {

    // your code goes here
    int amount = 5;
    vector<int> coins = {1,2,5};
    cout << change(amount,coins) << endl;


    return 0;
}