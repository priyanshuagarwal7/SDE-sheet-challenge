#include<bits/stdc++.h>
int distinctSubstring(string &word) {
    //  Write your code here.
    map<string , int> mp;
    int n = word.length();
    for(int i = 0 ; i<n ; i++){
        string s = "";
        s.push_back(word[i]);
        if(mp[s]==0){
            mp[s]++;
        }
        for(int j = i+1 ; j<n ; j++){
            s.push_back(word[j]);
            if(mp[s]==0){
                mp[s]++;
            }
        }
    }
    return mp.size();
}
