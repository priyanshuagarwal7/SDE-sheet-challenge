bool visited[1001];
vector<int> dfs(int index , vector<int> adj[] , vector<int> &v , int V){
    if(visited[index]==false){
        visited[index] = true;
        v.push_back(index);
        for(int i = 0 ; i< adj[index].size() ; i++){
            if(visited[adj[index][i]]==false){
                v = dfs(adj[index][i] , adj , v , V);
            }
        }
    }
    return v;
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    for(int i = 0 ; i<E ; i++){
        int x = edges[i][0] , y = edges[i][1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int count = 0;
    memset(visited , false , sizeof(visited));
    vector<vector<int>> ans;
    for(int i = 0 ; i<V ; i++){
        if(visited[i]==false){
            count++;
            vector<int> v;
            v = dfs(i , adj , v , V);
            sort(v.begin() , v.end());
            ans.push_back(v);
        }
    }
    memset(visited , false , sizeof(visited));
    return ans;
}
