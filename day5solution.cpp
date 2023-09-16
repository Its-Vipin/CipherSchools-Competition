
// LeetCode Solution 

class Solution {
public:
void insertAtTail(ListNode* &head, int x){
    ListNode* n = new ListNode(x);
    if(head==NULL){
        head=n;
        return;
    }
    ListNode* cur=head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=n;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> l;
        for(ListNode* head : lists){
            ListNode* cur=head;
            while(cur!=NULL){
                l.push_back(cur->val);
                cur=cur->next;
            }
        }
        sort(l.begin(),l.end());
        ListNode* mainHead=NULL;
        for(int i:l){
            insertAtTail(mainHead,i);
        }
        return mainHead;
    }
};