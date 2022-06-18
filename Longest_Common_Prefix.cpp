#include<bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    int min = 1001;
    for(int i = 0 ; i<n ; i++){
        int l = arr[i].length();
        if(l < min){
            min = l;
        }
    }
    string ans = "";
    for(int i = 0 ; i<min ; i++){
        bool var = true;
        for(int j = 0 ; j<n-1 ; j++){
            if(arr[j][i]!=arr[j+1][i]){
                var = false;
                break;
            }
        }
        if(var==true){
            ans.push_back(arr[0][i]);
        }
        else{
            break;
        }
    }
    return ans;
}


