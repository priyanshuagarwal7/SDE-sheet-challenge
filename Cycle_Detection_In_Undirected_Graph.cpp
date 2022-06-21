#include<bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    for(int i = 0 ; i<m ; i++){
        int x = edges[i][0] , y = edges[i][1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool visited[n+1];
    memset(visited , false , sizeof(visited));
    vector<int> parent(n+1 , -1);
    string ans = "No";
    queue<int> q;
    for(int index = 1 ; index<=n ; index++){
        if(visited[index]==false){
            q.push(index);
            while(!q.empty()){
                int ele = q.front();
                q.pop();
                if(visited[ele]==false){
                    visited[ele] = true;
                    for(int i = 0 ; i<adj[ele].size() ; i++){
                        int x = adj[ele][i];
                        if(visited[x]==false){
                            q.push(x);
                            parent[x] = ele;
                        }
                        else if(visited[x]==true && parent[ele]!=x){
                            ans = "Yes";
                            break;
                        }
                    }
                }
                if(ans=="Yes"){
                    break;
                }
            }
            if(ans=="Yes"){
                break;
            }
        }
    }
    return ans;
}
