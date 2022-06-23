double median(vector<int> a, vector<int> b)
{
    vector<int> v;
    int n = a.size() , m = b.size();
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
    }
    if(j < m){
        for(int index = j ; index < m ; index++){
            v.push_back(b[index]);
        }
    }
    else if(i < n){
        for(int index = i ; index < n ; index++){
            v.push_back(a[index]);
        }
    }
    double x;
    if(v.size()%2==0){
        double x1 = (double)v[v.size()/2-1] ;
        double x2 = (double)v[v.size()/2];
        x = x1 + x2;
        x = x/2;
    }
    else{
        double x1 = (double)v[v.size()/2];
        x = x1;
    }
    return x;
}
