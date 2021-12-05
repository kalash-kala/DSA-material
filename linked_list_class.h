//
//  linked_list_class.h
//  linked_list
//
//  Created by kalash kala on 24/04/21.
//
#include <iostream>
using namespace std;

#ifndef linked_list_class_h
#define linked_list_class_h

class double_Node{
public:
    double_Node * prev;
    int data;
    double_Node * next;
};

class node{
public:
    int data;
    node * next;
};

class linkedList{

private:
    int data;
    linkedList *next;
    linkedList * first;

public:
    void createList(int A[], int n, linkedList * s);
    void print(linkedList *head);
    void print_recursive(linkedList *head);
    int length(linkedList *head);
    int maximum(linkedList * head);
    int minimum(linkedList * head);
    void mergeList(linkedList * first, linkedList * second, linkedList * &source);
};

void linkedList::createList(int *A, int n, linkedList *s){
    linkedList *t, *last;
    
    s = new linkedList;
    s->data=A[0];
    s->next=NULL;
    last = s;
    
    for(int i=1; i<n; i++){
        t=new linkedList;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void linkedList::print(linkedList *head){ // traversing linked list
    linkedList *cur = head;
    
    for(;cur!=NULL;cur=cur->next){
        cout<<cur->data<<"\n";
    }
}

void linkedList::print_recursive(linkedList *head){
    
    if(head!=NULL){
        cout<<head->data<<" ";      //reverse the line 45 and 46 to print
        print_recursive(head->next);//the numbers in reverse order
    }else{
        cout<<"\n";
    }
}

int linkedList::length(linkedList *head){ // counting number of elements in the list
    
    linkedList *cur = head;
    int count =0;
    for(;cur!=NULL; cur = cur->next){
        count++;
    }
    return count;
}

int linkedList::maximum(linkedList * head){
    
    int max=INT_MIN;
    linkedList * cur = head;
    while(cur!=NULL){
        if(max<cur->data){
            max=cur->data;
        }
        cur=cur->next;
    }
    return max;
}

int linkedList::minimum(linkedList * head){
    
    int min=INT_MAX;
    linkedList * cur = head;
    while(cur!=NULL){
        if(min>cur->data){
            min=cur->data;
        }
        cur=cur->next;
    }
    return min;
}

void linkedList::mergeList(linkedList *first, linkedList *second, linkedList * &finale){
    
    linkedList * last=NULL;
    
    if(first->data<second->data){
        finale=first;
        last=first;
        first=first->next;
        last->next=NULL;
        
    }else if(second->data<first->data){
        finale=second;
        last=second;
        second=second->next;
        last->next=NULL;
        
    }else{
        finale=first;
        last=first;
        first=first->next;
        second=second->next;
        last->next=NULL;
    }
    
    while(first!=NULL && second!=NULL){
        if(first->data<second->data){
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
            
        }else if(first->data>second->data){
            last->next=second;
            last=second;
            second=second->next;
            last->next=NULL;
        }else{
            last->next=first;
            last=first;
            first=first->next;
            second=second->next;
            last->next=NULL;
        }
    }
    
    if(first!=NULL){
        last->next=first;
    }else if(second!=NULL){
        last->next=second;
    }
}

#endif /* linked_list_class_h */

