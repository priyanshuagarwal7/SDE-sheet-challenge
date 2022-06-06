#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
    sort(arr.begin() , arr.end());
    int i = 0 , j = 1 , num;
    while(j < n){
        if(arr[i]==arr[j]){
            num = arr[i];
            break;
        }
        else{
            i++;
            j++;
        }
    }
    return num;
}
