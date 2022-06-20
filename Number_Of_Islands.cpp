#include<bits/stdc++.h>
bool visited[1001][1001];
void dfs(int i , int j , int** arr , int n , int m){
    if((i>=0  && i<n) && (j>=0 && j < m)){
        if(visited[i][j]==false && arr[i][j]==1){
            visited[i][j] = true;
            dfs(i-1 , j-1 , arr , n , m);
            dfs(i-1 , j , arr , n , m);
            dfs(i-1 , j+1 , arr , n , m);
            dfs(i , j-1 , arr , n , m);
            dfs(i , j+1 , arr , n , m);
            dfs(i+1 , j-1 , arr , n , m);
            dfs(i+1 , j , arr , n , m);
            dfs(i+1 , j+1 , arr , n , m);
        }
        else{
            return ;
        }
    }
    return ;
}
int getTotalIslands(int** arr, int n, int m)
{
   memset(visited , false , sizeof(visited));
    int count = 0;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(arr[i][j]==1 && visited[i][j]==false){
                dfs(i , j , arr , n ,m);
                count++;
            }
        }
    }
    memset(visited , false , sizeof(visited));
    return count;
}
