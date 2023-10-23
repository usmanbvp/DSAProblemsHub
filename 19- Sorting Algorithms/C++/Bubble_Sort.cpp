//enter 5 numbers separated by space

#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for(int x=0; x<5; x++) {
        cin>>arr[x];
    }
    cout<<"Original list: ";
    for(int x=0; x<5; x++) {
       cout<<arr[x]<<" ";}
     
    for(int i=1; i<5; i++){
    for(int j=0; j<(5-i); j++){
    if(arr[j] > arr[j+1]){
        int a = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = a;       
    }}}
    
    cout<<"\n"<<"Sorted list: "; 
    for(int x=0; x<5; x++) {
       cout<<arr[x]<<" ";}
    
    return 0;
}
