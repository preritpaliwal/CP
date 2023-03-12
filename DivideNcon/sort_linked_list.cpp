// link to ques : https://leetcode.com/problems/sort-list/

#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};

void insert(node *head){
    node *cur = (node *)malloc(sizeof(node));
    cin>>cur->data;
    cur->next = NULL;
    if(head == NULL){
        head = cur;
    }
    else{
        node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = cur;
    }
}

void print_list(node *head){
    node *cur = head;
    while(cur!=NULL){
        cout<<cur->data<<"\t";
        cur = cur->next;
    }
}

void swap_adj(node *a){
    int k = a->data;
    a->data = a->next->data;
    a->next->data = k;
}

void sort(node *head){
    if(head->next==NULL){
        return;
    }
    node *cur = head;
    while(cur->next != NULL){
        if(cur->data>cur->next->data){
            swap_adj(cur);
        }
    }
}

int main()
{
    node *head = NULL;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        insert(head);
    }
    print_list(head);
    sort(head);
    print_list(head);
    return 0;
}