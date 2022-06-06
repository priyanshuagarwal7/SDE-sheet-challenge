#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    pair<int,int> p = {0 , 0};
    unordered_map<int,int> mp;
    int sum = 0;
    for(int i = 0 ; i<n ; i++){
        mp[arr[i]]++;
        sum+=arr[i];
    }
    for(int i = 1; i<=n ; i++){
        if(mp[i]==0){
            p.first = i;
        }
        else if(mp[i]==2){
            p.second = i;
        }
    }
    return p;
}
