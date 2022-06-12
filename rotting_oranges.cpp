#include<bits/stdc++.h>
int counter = 0;
void func(queue<pair<int,int>> &q , vector<vector<bool>> &visited , vector<vector<int>>& grid, int n , int m){
    counter++;
    int size = q.size();
    while(size-->0){
        pair<int,int> p = q.front();
        q.pop();
        int x = p.first , y = p.second;
        if((x+1)>=0 && (x+1)<n && y>=0 && y<m && grid[x+1][y]==1 && visited[x+1][y]==false){
            visited[x+1][y] = true;
            grid[x+1][y] = 2;
            q.push({x+1 , y});
         } 
         if((x-1)>=0 && (x-1)<n && y>=0 && y<m && grid[x-1][y]==1 && visited[x-1][y]==false){
            visited[x-1][y] = true;
            grid[x-1][y] = 2;
             q.push({x-1 , y});
         } 
         if((x)>=0 && (x)<n && y+1>=0 && y+1<m && grid[x][y+1]==1 && visited[x][y+1]==false){
            visited[x][y+1] = true;
            grid[x][y+1] = 2;
             q.push({x , y+1});
         } 
         if((x)>=0 && (x)<n && y-1>=0 && y-1<m && grid[x][y-1]==1 && visited[x][y-1]==false){
            visited[x][y-1] = true;
            grid[x][y-1] = 2;
             q.push({x , y-1});
         } 
    }
    if(q.size() > 0){
        func(q , visited , grid , n , m);
    }
}
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    vector<vector<bool>> visited;
    for(int i = 0 ; i<n ; i++){
        vector<bool> f;
        for(int j = 0 ; j<m ; j++){
            f.push_back(false);
        }
        visited.push_back(f);
    }
    queue<pair<int,int>> q;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(grid[i][j]==2){
                q.push({i , j});
                visited[i][j] = true;
            }
        }
    }
    func(q , visited , grid , n , m);
    for(int i = 0 ; i<n ; i++){
        for(int j= 0 ; j <m ; j++){
            if(visited[i][j]==false && grid[i][j]!=0){
                counter = 0;
                break;
            }
        }
    }
    int x = counter;
    counter = 0;
    return x-1;
}
