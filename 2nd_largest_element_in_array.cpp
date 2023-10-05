// coding ninjas question



https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
vector<int> getSecondOrderElements(int n, vector<int> a) {
    sort(a.begin(),a.end());
    vector<int> v;
    
    v.push_back(a[n-2]);
    v.push_back(a[1]);
    return v;

    
}
