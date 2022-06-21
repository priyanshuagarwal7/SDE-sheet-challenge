#include<bits/stdc++.h>
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int n = image.size() , m = image[0].size();
    bool visited[n][m];
    memset(visited , false , sizeof(visited));
    stack<pair<int,int>> st;
    st.push({x , y});
    int target = image[x][y];
    while(!st.empty()){
        pair<int,int> p = st.top();
        st.pop();
        if(p.first>=0 && p.first < n && p.second >= 0 && p.second < m){
            int i = p.first , j = p.second;
            if(visited[i][j]==false && image[i][j]==target){
                visited[i][j] = true;
                st.push({i+1 , j});
                st.push({i , j+1});
                st.push({i-1 , j});
                st.push({i , j-1});
                image[i][j] = newColor;
            }
        }
    }
    return image;
}
