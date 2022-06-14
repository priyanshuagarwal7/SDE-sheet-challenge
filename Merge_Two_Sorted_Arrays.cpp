#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int i = m-1 , j = n-1 , index = 0;
    while(i>=0 && j>=0){
        if(arr1[i] > arr2[j]){
            arr1[m+n-1-index] = arr1[i];
            arr1[i] = 0 , i--;
            index++;
        }
        else if(arr2[j] > arr1[i]){
            arr1[m+n-1-index] = arr2[j];
            arr2[j] = 0 , j--;
            index++;
        }
        else{
            arr1[m+n-1-index] = arr1[i];
            arr1[i] = 0 , i--;
            index++;
            arr1[m+n-1-index] = arr2[j];
            arr2[j] = 0 , j--;
            index++;
        }
    }
    if(j >= 0){
        int k = j;
        for(int idx = k ; idx >=0 ; idx--){
            arr1[idx] = arr2[j];
            j--;
        }
    }
    return arr1;
}
