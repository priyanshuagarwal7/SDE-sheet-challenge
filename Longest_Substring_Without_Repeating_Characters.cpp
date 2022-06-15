#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    unordered_map<char , int> mp;
    int i = 0 , j = 0 , n = input.length();
    int max = 1;
    while(j  < n){
        if(mp[input[j]]==0){
            mp[input[j]]++;
            j++;
        }
        else{
            int len = j-i;
            if(len > max){
                max = len;
            }
            while(input[i]!=input[j]){
                mp[input[i]]--;
                i++;
            }
            mp[input[i]]--;
            i++;
            mp[input[j]]++;
            j++;
        }
    }
    int l = j-i;
    if(l > max){
        max = l;
    }
    return max;
}
