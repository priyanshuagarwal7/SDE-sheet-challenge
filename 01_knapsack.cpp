#include<bits/stdc++.h>
int dp[1001][1001];
int func(vector<int> &values, vector<int> &weights, int n, int w){
    if(n<=0 || w<0){
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    if(w >= weights[n-1]){
        dp[n][w] = max(values[n-1] + func(values , weights , n-1 , w - weights[n-1]) , func(values , weights , n-1 , w));
    }
    else if(w < weights[n-1]){
        dp[n][w] = func(values , weights , n-1 , w);
    }
    return dp[n][w];
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    memset(dp , -1 , sizeof(dp));
    for(int i = 0 ; i<=n ; i++){
        dp[i][0] = 0;
    }
    for(int j = 0 ; j<=w ; j++){
        dp[0][j] = 0;
    }
    int k = func(values , weights , n , w);
    int y = dp[n][w];
    memset(dp ,-1 , sizeof(dp));
    return y;
}
