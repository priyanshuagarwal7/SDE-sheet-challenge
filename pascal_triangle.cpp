#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>> v;
    for(int i = 0 ; i<n ; i++){
        vector<long long int> x(i+1);
        x[0] = 1 , x[i] = 1;
        if(v.size() >= 1){
            vector<long long int> y = v[v.size()-1];
            for(int index = 0 ; index < y.size()-1 ; index++){
                x[index+1] = y[index] + y[index+1];
            }
        }
        v.push_back(x);
    }
    return v;
}
