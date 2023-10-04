// coding ninjas question

int linearSearch(int n, int num, vector<int> &arr)
{   
    int idx;
    for(int i=0;i<n;i++){
        if(arr[i]==num){
            idx=i;
            break;
        }
    }
    if(idx<=n){
        return idx;
    }
    else{
        return -1;
    }
}
