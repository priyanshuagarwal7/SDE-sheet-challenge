#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    vector<int> greater;
    int n = prices.size()-1;
    stack<int> st;
    for(int i = n ; i>=0 ; i--){
        if(st.size()==0){
            st.push(prices[i]);
            greater.push_back(-1);
        }
        else{
            while(!st.empty()){
                if(st.top() < prices[i]){
                    st.pop();
                }
                else{
                    greater.push_back(st.top());
                    break;
                }
            }
            if(st.size()==0){
                st.push(prices[i]);
                greater.push_back(-1);
            }
        }
    }
    reverse(greater.begin() , greater.end());
    int max = 0;
    for(int i = 0 ; i<greater.size() ; i++){
        if(greater[i]!=-1){
            int k = greater[i] - prices[i];
            if(k > max){
                max = k;
            }
        }
    }
    return max;
}
