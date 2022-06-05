#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
    vector<pair<int,int>> index;
    int n = matrix.size() , m = matrix[0].size();
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(matrix[i][j]==0){
                index.push_back({i , j});
            }
        }
    }
    for(int i = 0 ; i<index.size() ; i++){
        pair<int,int> p = index[i];
        int x = p.first , y = p.second;
        for(int j = 0 ;  j <m ; j++){
            matrix[x][j] = 0;
        }
        for(int j = 0 ; j<n ; j++){
            matrix[j][y] = 0;
        }
    }
}
