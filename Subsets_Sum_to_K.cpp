#include<bits/stdc++.h>
vector<vector<int>> v;
map<vector<int> , int> mp;
void func(vector<int> arr, int n, int k , int sum , vector<int> &x , int start){
    if(sum==k){
        v.push_back(x);
    }
    for(int i = start ; i<n ; i++){
            x.push_back(arr[i]);
            func(arr , n , k , sum+arr[i] , x , i+1);
            x.pop_back();
        }
    return ;
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<int> x;
    for(int i = 0 ; i<n ; i++){
            x.push_back(arr[i]);
            func(arr , n , k , arr[i] , x , i+1);
            x.pop_back();
        }
    sort(v.begin() , v.end());
    vector<vector<int>> ans = v;
    v.clear() , mp.clear();
    return ans;
}
