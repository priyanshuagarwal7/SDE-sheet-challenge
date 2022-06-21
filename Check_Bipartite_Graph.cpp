#include<bits/stdc++.h>
bool isGraphBirpatite(vector<vector<int>> &edges) {
    int n = edges.size();
    vector<int> adj[n];
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(edges[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    bool visited[n];
    bool ans = true;
    memset(visited , false , sizeof(visited));
    queue<int> q;
    vector<int> color(n , -1);
    for(int index = 0 ; index < n ; index++){
        if(visited[index]==false){
            q.push(index);
            if(color[index]==-1){
                color[index] = 0;
            }
            while(!q.empty()){
                int ele = q.front();
                q.pop();
                if(visited[ele]==false){
                    visited[ele] = true;
                    for(int i = 0 ; i<adj[ele].size() ; i++){
                        int x = adj[ele][i];
                        if(visited[x]==false){
                            if(color[ele]==1){
                                color[x] = 0;
                            }
                            else if(color[ele]==0){
                                color[x]= 1;
                            }
                            q.push(x);
                        }
                        else if(visited[x]==true){
                            if(color[x]==color[ele]){
                                ans = false;
                                break;
                            }
                        }
                    }
                    if(ans==false){
                        break;
                    }
                }
            }
            if(ans==false){
                break;
            }
        }
    }
    return ans;
}
