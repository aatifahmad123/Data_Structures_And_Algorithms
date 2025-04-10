#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &prices, vector<int> &lengths, int N, int n){
    if(N == 0 || n == 0){
        return 0;
    }

    if(lengths[n-1] <= N){
        return max(solve(prices,lengths,N-lengths[n-1],n) + prices[n-1],solve(prices,lengths,N,n-1));
    }

    else{
        return solve(prices,lengths,N,n-1);
    }
}

int cutRod(vector<int> &price) {
    
    int n = price.size();
    int N = n;
    vector<int> lengths(n,0);
    for(int i = 0;i < n;i++){
        lengths[i] = i + 1;
    }

    return solve(price,lengths,N,n);

}

int main() {

    // your code goes here
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << "Maximum Value : " << cutRod(price) << endl;

    return 0;
}