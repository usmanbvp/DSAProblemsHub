// coding ninjas question


https://www.codingninjas.com/studio/problems/linear-search_6922070?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
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
