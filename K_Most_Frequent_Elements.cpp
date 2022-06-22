#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    unordered_map<int,int> mp;
    for(int i = 0 ; i<n ; i++){
        mp[arr[i]]++;
    }
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    
    for(auto it = mp.begin() ; it!=mp.end() ; it++){
        pair<int,int> p = {it->second , it->first};
        q.push(p);
        if(q.size() > k){
            q.pop();
        }
    }
    vector<int> v;
    while(q.size() > 0){
        pair<int,int> x = q.top();
        v.push_back(x.second);
        q.pop();
    }
    sort(v.begin() , v.end());
    return v;
}
