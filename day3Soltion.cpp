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

void rotateByK(node* &head, int k){
    if(head==NULL || k==0){
        return;
    }

    int l=1;
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        l++;
    }

    k=k%l;
    if(k==0){return;}
    node* cur=head;
    for(int i=1;i<l-k;i++){
        cur=cur->next;
    }
    node* head2=cur->next;

    cur->next=NULL;
    temp->next=head;
    head=head2;
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
    rotateByK(head,k);
    display(head);
    return 0;
}