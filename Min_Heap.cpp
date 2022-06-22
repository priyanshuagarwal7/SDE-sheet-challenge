vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> v;
    priority_queue<int , vector<int> , greater<int>> p;
    for(int i = 0 ; i<n ; i++){
        if(q[i].size() > 1){
            p.push(q[i][1]);
        }
        else{
            int x = p.top();
            p.pop();
            v.push_back(x);
        }
    }
    return v;
}
