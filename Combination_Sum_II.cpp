#include<bits/stdc++.h>
vector<vector<int>> v;
map<vector<int> , int> mp;
void func(vector<int> &arr , int n , int target , int sum , vector<int> &x , int start){
    if(sum==target){
        sort(x.begin() , x.end());
        if(mp[x]==0){
            mp[x]++;
            v.push_back(x);
        }
        return ;
    }
    if(sum > target){
        return ;
    }
    for(int i = start ; i<n ; i++){
            x.push_back(arr[i]);
            func(arr , n , target , sum+arr[i] , x , i+1);
            x.pop_back();
        }
    return ;
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    vector<int> x;
    sort(arr.begin() , arr.end());
    for(int i = 0 ; i<n ; i++){
        x.push_back(arr[i]);
        func(arr , n , target , arr[i] , x , i+1);
        x.pop_back();
    }
    sort(v.begin() , v.end());
    vector<vector<int>> ans = v;
    v.clear() , mp.clear();
    return ans;
}
