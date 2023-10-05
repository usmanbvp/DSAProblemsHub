// coding ninjas question


https://www.codingninjas.com/studio/problems/ninja-and-the-sorted-check_6581957?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
int isSorted(int n, vector<int> a) {
    vector<int> before;
    for(int i=0;i<n;i++){
        before.push_back(a[i]);
    }
    int count=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        if(before[i]==a[i]){
            count++;
        }
    }
    if(count==n){
        return 1;
    }
    else{
        return 0;
    }

}
