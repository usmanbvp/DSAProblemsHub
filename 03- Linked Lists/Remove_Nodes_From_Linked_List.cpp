// LeetCode Problem List :- https://leetcode.com/problems/remove-nodes-from-linked-list/
// Author :- Jayant Patidar

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        vector<int> arr;
        ListNode *p=head,*q=nullptr;
        while(p){
            arr.push_back(p->val); // store linklist in array
            p=p->next;
        }
        stack<pair<int,int>> st; 
        for(int i=arr.size()-1;i>=0;i--){
            if(st.empty()){
                st.push({arr[i],1}); // for last element there is no greater element to right of it
            }else{
                if(st.top().first>arr[i]){ // if there is greater element to right then in pair put -1 with max till element
                    st.push({st.top().first,-1});
                }else{
                    st.push({arr[i],1}); // if current is max till now then put it with 1
                }
            }
        }
        p=head;
        // which ever has 1 means it has no greater element to right
        while(st.size()){
            if(st.top().second==1){
                p->val = st.top().first;
                q=p; // q stores previous pointer
                p=p->next;
            }
            st.pop();
        }
        q->next = nullptr;
        return head;
    }
};
