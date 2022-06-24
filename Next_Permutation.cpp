#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int index = -1;

   for(int i = n - 2; i >= 0; --i){

       if(permutation[i] < permutation[i + 1]){
           index = i;
            break;
       }
   }

   if(index == -1){
       sort(permutation.begin(), permutation.end());
   }
    
    else{
        int num = -1;

       for(int i = n - 1; i > index; --i){
           if(permutation[i] > permutation[index]){
               num = i;
               break;
           }
       }
        int t = permutation[index];
        permutation[index] = permutation[num];
        permutation[num] = t;
       reverse(permutation.begin() + index + 1, permutation.end());
    }

   return permutation;
}
