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

int sizeOfLinkedList(node* head){
    if(head==NULL){
        return 0;
    }
    int s=1;
    while(head->next!=NULL){
        s++;
        head=head->next;
    }
    return s;
}

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

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* cur=head;
    n->next=cur;
    head=n;
}

node* reverseKGroup(node* head,int k){
    list<int> l;
    node* cur=head;
    int sz=sizeOfLinkedList(head)/k;
    while(sz--){
        vector<int> gD;
        for(int i=0;i<k;i++){

            gD.push_back(cur->data);
            cur=cur->next;
        }
        for(int i=k-1;i>=0;i--){
            l.push_back(gD[i]);
        }
    }
    while(cur!=NULL){
        l.push_back(cur->data);
        cur=cur->next;
    }
    node* temp=head;
    for(int i : l){
        temp->data=i;
        temp=temp->next;
    }
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
    int k;cin >> k;
    head = reverseKGroup(head,k);
    display(head);
    return 0;
}