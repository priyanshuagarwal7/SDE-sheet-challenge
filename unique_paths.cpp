#include <bits/stdc++.h> 
int t[16][16];
int func(int m , int n , int i , int j){
    if(i==m-1 && j==n-1){
        return 1;
    }
    if(t[i][j]!=0){
        return t[i][j];
    }
    else{
        if((i>=0 && i<m )&&(j>=0 && j<n)){
            t[i][j] = func(m , n , i+1 , j) + func(m , n , i, j+1);
        }
        else{
            return 0;
        }
    }
    return t[i][j];
}
int uniquePaths(int m, int n) {
    memset(t , 0 , sizeof(t));
    return func(m , n , 0, 0);
}
