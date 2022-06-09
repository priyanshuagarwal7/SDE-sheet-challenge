#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    stack<pair<int,int>> st;
    vector<int> v(n , -1);
    for(int i = 0 ; i<n ; i++){
        if(st.size()==0){
            st.push({arr[i] , i});
        }
        else{
            while(st.size() > 0){
                if(st.top().first < arr[i]){
                    v[st.top().second] = arr[i];
                    st.pop();
                }
                else{
                    break;
                }
            }
            st.push({arr[i] , i});
        }
    }
    return v;
}
