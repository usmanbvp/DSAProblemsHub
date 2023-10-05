// coding ninjas question named merge 2 sorted array


https://www.codingninjas.com/studio/problems/sorted-array_6613259?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf
vector<int> removeDuplicates(vector<int> &arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            arr.erase(arr.begin() + i);
            i--;
            n--;
        }
    }
    return arr;
}


vector<int> sortedArray(vector<int> a, vector<int> b) {
    vector<int> finall;
    for (int i = 0; i < a.size(); i++) {
        finall.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        finall.push_back(b[i]);
    }
    sort(finall.begin(), finall.end());
    int fsize = finall.size();
    vector<int> ans;
     ans = removeDuplicates(finall, fsize);
    return ans;
}


