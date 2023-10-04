// coding ninjas question

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
