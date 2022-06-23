int ninjaAndLadoos(vector<int> &a, vector<int> &b, int m, int n, int k) {
    vector<int> v;
    n = a.size() , m = b.size();
    int i = 0 , j = 0;
    while(i < n && j < m){
        if(a[i] > b[j]){
            v.push_back(b[j]);
            j++;
        }
        else if(a[i] < b[j]){
            v.push_back(a[i]);
            i++;
        }
        else if(a[i]==b[j]){
            v.push_back(a[i]);
            v.push_back(b[j]);
            i++ , j++;
        }
        if(v.size()==k){
            break;
        }
    }
    if(v.size() < k){
        if(j < m){
            for(int index = j ; index < m ; index++){
                v.push_back(b[index]);
                if(v.size()==k){
                    break;
                }
            }
        }
        else if(i < n){
            for(int index = i ; index < n ; index++){
                v.push_back(a[index]);
                if(v.size()==k){
                    break;
                }
            }
        }
    }
    return v[k-1];
}
