#include<bits/stdc++.h>
using namespace std;


int solve(int W, vector<int> &val, vector<int> &wt, int n){

    if((n == 0) || (W == 0)){
      return 0;
    }
  
    if(wt[n-1] <= W){
      return max(solve(W - wt[n-1],val,wt,n) + val[n-1],solve(W,val,wt,n-1));
    }
  
    else{
      return solve(W, val, wt, n-1);
    }
  
  }

int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    // code here

    int n = val.size();

    return solve(capacity,val,wt,n);
}

int main() {

    // your code goes here
    vector<int> val = {6,1,7,7};
    vector<int> wt = {1,3,4,5};
    int capacity = 8;

    cout << "Max value : " << knapSack(val,wt,capacity) << endl;

    return 0;
}