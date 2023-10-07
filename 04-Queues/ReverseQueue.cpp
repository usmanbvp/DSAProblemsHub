#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int> &q){
   // queue<int>q;
    stack<int>s;
    // push elemnt into stack from queue
    while(!q.empty()){
        int elemnt = q.front();
        q.pop();
        s.push(elemnt);                                                                 //T.c -o(n)

    }                                                                                   //S.c -o(n)
    //step 2; push elemnt sinto queue from stack
    while(!s.empty()){
        int elemnt = s.top();
        s.pop();
        q.push(elemnt);
    }
}
void reverseusingrecursion(queue<int> &q){
    if(q.empty()){
        return;
    }
    //step 1:
    int temp = q.front();
    q.pop();
    reverseusingrecursion(q);
    //push all ements;
    q.push(temp);
}
void reversekelemnts(queue<int> &q, int k){
    
    stack<int>s;
    int count =0;
    int n = q.size();

    if( k<= 0 || k>n){
        return;
    }
    //step 1;
    while(!q.empty()){
        int element = q.front();
        q.pop();
        s.push(element);
        count++;

        if(count == k){
            break;
        }
    }
    //STEP 2:
    
    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);
    }
    //step 3:
    count =0;
    while(!q.empty() && n-k!= 0){
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if(count == n-k){
            break;
        }
    }
    }
void interleave(queue<int> &q){
    int n= q.size();
    if(q.empty()){
        return;
    }
    int k = n/2;
    int count =0;
    queue<int>q2;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        q2.push(temp);
        count++;

        if(count == k){
            break;
        }
    }

    while(!q.empty() && !q2.empty()){
        int first = q2.front();
        q2.pop();
        q.push(first);

        int second = q.front();
        q.pop();
        q.push(second);
    }
    //odd wala case
    if(n&1){
        int element = q.front();
        q.pop();
        q.push(element);
    }

}
int main(){
    queue<int>q;
    q.push(3);
    q.push(4);
    q.push(8);
    q.push(9);
    q.push(13);
    // cout<<"the main queue are";
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    //     cout<<endl;
    // }
    // cout<<"the reversed queues are";
    // reverseusingrecursion(q);
    interleave(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();                        
        cout<<endl;
    }
    return 0;
    
}