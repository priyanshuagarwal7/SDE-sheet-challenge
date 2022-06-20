#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    bool visited[vertex];
    memset(visited , false , sizeof(visited));
    vector<int> adj[vertex];
    for(int i = 0 ; i<edges.size() ; i++){
        int x = edges[i].first , y = edges[i].second;
        adj[x].push_back(y) , adj[y].push_back(x);
    }
    vector<int> ans;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int index = q.front();
        q.pop();
        ans.push_back(index);
        vector<int> v;
        for(int i = 0 ; i<adj[index].size() ; i++){
             if(visited[adj[index][i]]==false){
                    v.push_back(adj[index][i]);
                    visited[adj[index][i]] = true;
                }
            }
        sort(v.begin() , v.end());
            for(int i = 0 ; i<v.size() ; i++){
                q.push(v[i]);
            }
    }
    for(int i = 0 ; i<vertex ; i++){
        if(visited[i]==false){
            ans.push_back(i);
        }
    }
    return ans;
}
