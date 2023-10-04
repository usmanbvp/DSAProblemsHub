// coding ninjas question

vector<int> getSecondOrderElements(int n, vector<int> a) {
    sort(a.begin(),a.end());
    vector<int> v;
    
    v.push_back(a[n-2]);
    v.push_back(a[1]);
    return v;

    
}
