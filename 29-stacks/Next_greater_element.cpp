#include<bits/stdc++.h>
using namespace std;
    //Function to find the next greater element for each element of the array.
vector<long long> nextLargerElement(vector<long long> arr, int n){
    stack<long long int>st; //this stores the indexes of arr rather than the element arr[i]
    vector<long long int>vec(arr.size()); //final vector to be returned
    
    for(int i=0;i<n;i++){
        //if stack is not empty and the arr[i]>the element in arr at the index present at the top of st  
        //then at the index in vec store the arr[i] element as next_greater_element;
        while(!st.empty()&&arr[i]>arr[st.top()]){
        vec[st.top()]=arr[i];
        st.pop();
        }
        st.push(i);
    }

    // stack not empty, means no next_greater_element, hence store -1 for that index
    while(!st.empty()){
        vec[st.top()]=-1;
        st.pop();
    }
    return vec;
}
int main()
{
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    vector <long long> res = nextLargerElement(arr, n);
    for (long long i : res) cout << i << " ";
    cout<<endl;
    return 0;
}