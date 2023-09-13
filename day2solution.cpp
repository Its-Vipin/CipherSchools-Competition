#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int val){
            data=val;
            next=NULL;
        }
};

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* cur=head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=n;
}

node* reorderedList(node* head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }

    node* odd = head;
    node* even = head->next;
    node* x = even;
    while(even!=NULL && even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=x;
    return head;
}

void display(node* head){
    node* cur=head;
    while(cur!=NULL){
        cout << cur->data << " ";
        cur=cur->next;
    }
}

int main(){
    node* head=NULL;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int y;
        cin >> y;
        insertAtTail(head,y);
    }
    head = reorderedList(head);
    display(head);
    return 0;
}