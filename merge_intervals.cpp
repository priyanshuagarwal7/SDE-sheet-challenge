vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin() , intervals.end());
    vector<vector<int>> v;
    vector<int> x = intervals[0];
    int i = 1 , n = intervals.size();
    while(i < n){
        vector<int> y = intervals[i];
        if(x[0]==y[0]){
            x[1] = max(x[1] , y[1]);
        }
        else if(y[0] > x[0]){
            if(y[0] > x[1]){
                v.push_back(x);
                x = y;
            }
            else if(x[1] >= y[0]){
                x[1] = max(x[1] , y[1]);
            }
        }
        i++;
    }
    v.push_back(x);
    return v;
}
