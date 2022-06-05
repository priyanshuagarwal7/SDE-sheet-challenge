#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int start_idx = 0 , start_jdx = 0 , end_idx = n-1 , end_jdx = m-1;
    while(end_jdx > start_jdx && end_idx > start_idx){
        int temp = mat[start_idx][start_jdx];
        for(int i = start_jdx+1 ; i <= end_jdx ; i++){
            int k = mat[start_idx][i];
            mat[start_idx][i] = temp;
            temp = k;
        }
        for(int i = start_idx+1  ; i<=end_idx ; i++){
            int k = mat[i][end_jdx];
            mat[i][end_jdx] = temp;
            temp = k;
        }
        for(int i = end_jdx-1 ; i>=start_jdx ; i--){
            int k = mat[end_idx][i];
            mat[end_idx][i] = temp;
            temp = k;
        }
        for(int i = end_idx-1 ; i>=start_idx ; i--){
            int k = mat[i][start_jdx];
            mat[i][start_jdx] = temp;
            temp = k;
        }
        start_idx++ , start_jdx++ , end_idx-- , end_jdx--;
    }

}
