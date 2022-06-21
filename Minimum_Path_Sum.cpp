#include<bits/stdc++.h>
int dp[101][101];
int func(int i , int j , int n , int m , vector<vector<int>> &matrix){
    if(i==n-1 && j==m-1){
        dp[i][j] = matrix[i][j];
    }
    else if(dp[i][j]!=INT_MAX){
        return dp[i][j];
    }
    else if(i>=0 && i < n && j>=0 && j<m){
        dp[i][j] = matrix[i][j] + min(func(i+1 , j , n , m , matrix) , func(i , j+1 , n , m , matrix));
    }
    else{
        return INT_MAX;
    }
    return dp[i][j];
}
int minSumPath(vector<vector<int>> &grid) {
    for(int i = 0 ; i<101 ; i++){
        for(int j = 0 ; j<101 ; j++){
            dp[i][j] = INT_MAX;
        }
    }
    int n = grid.size() , m = grid[0].size();
    int k = func(0 , 0 , n , m , grid);
    k = dp[0][0];
    for(int i = 0 ; i<101 ; i++){
        for(int j = 0 ; j<101 ; j++){
            dp[i][j] = INT_MAX;
        }
    }
    return k;
}
