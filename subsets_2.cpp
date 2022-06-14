#include<bits/stdc++.h>
vector<vector<int>> v;
map<vector<int> , int> mp;
void func(vector<int> &x , int start , int n , vector<int> &arr){
    vector<int> y = x;
    sort(y.begin() , y.end());
    if(mp[y]==0){
        mp[y]++;
        v.push_back(y);
    }
    for(int i = start ; i < n ; i++){
        x.push_back(arr[i]);
        func(x , i+1 , n , arr);
        x.pop_back();
    }
    return ;
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<int> x;
    v.push_back(x);
    for(int i = 0 ; i<n ; i++){
        x.push_back(arr[i]);
        func(x , i+1 , n , arr);
        x.pop_back();
    }
    sort(v.begin() , v.end());
    vector<vector<int>> ans = v;
    v.clear() , mp.clear();
    return ans;
}
