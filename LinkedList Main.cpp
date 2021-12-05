//
//  main.cpp
//  linked_list
//
//  Created by kalash kala on 24/04/21.
//

#include <iostream>
#include "linked_list_class.h"
using namespace std;

struct doubleListeNode{
    doubleListeNode * prev;
    int data;
    doubleListeNode * next;
};

struct ListNode{
    int data;               // default value is taken as 0
    struct ListNode *next;  //initialising it as NULL is advised
};

struct ListNode *first;
ListNode * loop_list;
ListNode * linked_list;

void createList(int A[], int n, ListNode * &sub){ // creating a fresh linked list
    struct ListNode *t, *last;
    
    sub = new ListNode;
    sub->data=A[0];
    sub->next=NULL;
    last = sub;
    
    for(int i=1; i<n; i++){
        t=new ListNode;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void print(struct ListNode *head){ // traversing linked list
    struct ListNode *cur = head;
    
    for(;cur!=NULL;cur=cur->next){
        cout<<cur->data<<" ";
    }
    cout<<"\n";
}

void print_recursive(struct ListNode *head){

    if(head!=NULL){
        cout<<head->data<<" ";
        print_recursive(head->next);
    }else{
        cout<<"\n";
    }
}

int length(struct ListNode *head){ // counting number of elements in the list
    struct ListNode *cur = head;
    int count =0;
    for(;cur!=NULL; cur = cur->next){
        count++;
    }
    return count;
}

struct ListNode *insertAtBeginning(struct ListNode * &head, int data){
    struct ListNode *temp;
    
    temp = new ListNode;
    temp->data=data;
    temp->next=NULL;
    
    if(head==NULL){
        head=temp;
        head->next=NULL;
    }else{
        temp->next=head;
        head=temp;
    }

    return head;
}

struct ListNode *insertAtEnd(struct ListNode *head, int data){
    
    struct ListNode *temp, *cur;
    
    temp = new ListNode;
    temp->data=data;
    temp->next=NULL;
    cur = head;
    
    if(cur->next==NULL){
        cur->next = temp;
    }else{
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=temp;
    }
    return head;
}

struct ListNode *insertAtPosn(struct ListNode * &head, int data, int posn){
    
    struct ListNode *cur=head;
    
    struct ListNode *temp = new ListNode;
    temp->data=data;
    temp->next=NULL;
    
    if(posn==1){
        temp->next=head;
        return temp;
    }
    for(int i=1; i<posn-1; i++){
        if(cur->next==NULL){
            cout<<"not possible ";
            return NULL;
        }
        cur=cur->next;
    }
    temp->next=cur->next;
    cur->next=temp;
    
    return head;
}

int maximum(struct ListNode *head){
    
    int max=INT_MIN;
    
    struct ListNode * cur;
    cur=head;
    
    while(cur!=NULL){
        if(max<cur->data){
            max=cur->data;
        }
        cur=cur->next;
    }
    
    return max;
}

int minimum(struct ListNode * head){
    
    int min=INT_MAX;
    
    struct ListNode * cur;
    cur=head;
    
    while(cur!=NULL){
        if(min>cur->data){
            min=cur->data;
        }
        cur=cur->next;
    }
    
    return min;
}

int linearSearch(struct ListNode * head,int val){ // without transposition
    
    struct ListNode * cur = head;
    while(cur!=NULL){
        if(cur->data==val){
            cout<<"YES the element is there\n";
            return 0;
        }
        cur=cur->next;
    }
    cout<<"NO the element is not there\n";
    return 0;
}

ListNode * searchLinear(struct ListNode * &head,int val){ // with transposition
    
    struct ListNode * cur=head,* precur=head;
    while(cur!=NULL){
        if(cur->data==val){
            cout<<"YES the element is present there\n";
            precur->next=cur->next;
            cur->next=head;
            head=cur;
            first=head;
            return head;
        }
        precur=cur;
        cur=cur->next;
    }
    cout<<"NO the element is not there\n";
    return head;
}

ListNode *sorted_insert(ListNode * &head, int data){
    ListNode * precur=head, *cur=head;
    
    ListNode * temp = new ListNode;
    temp->data=data;
    temp->next=NULL;
    
    if(cur->data>data && cur->next==NULL){
        temp->next=head;
        head=temp;
        return head;
    }
    while(cur!=NULL && cur->data<data){
        precur=cur;
        cur=cur->next;
    }
    precur->next=temp;
    temp->next=cur;
    
    return head;
}

ListNode * DeleteBeginning(ListNode * &head){
    
    ListNode * p=head;
    head=head->next;
    delete p;
    cout<<p<<"\n";
    return head;
}

ListNode * DeleteAtPosn(ListNode * &head,int posn){
    
    ListNode * cur=head,* precur=head;
    
    if(posn==1){
        head=head->next;
        delete cur;
        return head;
    }
    
    while(cur!=NULL && posn-1>0){
        precur=cur;
        cur=cur->next;
        posn--;
    }
    if(cur==NULL){
        cout<<"NOT POSSIBLE\n";
        return 0;
    }
    
    precur->next=cur->next;
    delete cur;
    
    return head;
}

int checkSortedList(ListNode * head){
    
    ListNode *cur=head;
    int x=INT_MIN;
    
    while(cur!=NULL){
        if(x<=cur->data){
            x=cur->data;
        }else{
            cout<<"NOT SORTED\n";
            return 0;
        }
        cur=cur->next;
    }
    cout<<"YEP ITS SORTED\n";
    return 0;
}

void removeDuplicate(ListNode * &head){
    
    ListNode * cur=head->next;
    ListNode * precur=head;
    
    while(cur!=NULL){
        if(precur->data!=cur->data){
            precur=cur;
            cur=cur->next;
        }else{
            precur->next=cur->next;
            delete cur;
            cur=precur->next;
        }
    }
}

void reverseLinkedlist(ListNode * &head){//using sliding pointers
    ListNode *r=NULL,*q=NULL;
    
    while(head!=NULL){
        r=q;
        q=head;
        head=head->next;
        q->next=r;
    }
    head=q;
}

void reverseLinkedlistRecursion(ListNode * sub, ListNode * head, ListNode * &p){// worth analysing
    
    if(head!=NULL){
        reverseLinkedlistRecursion(head, head->next,p);
        head->next=sub;
    }else{
        p=sub;
    }
}

void concatenateLinkedlist(ListNode * head, ListNode * sub_head){
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=sub_head;
}

void mergeLinkedlist(ListNode * head, ListNode * sub_head, ListNode * &new_head){ // My Way using previous functions
    
     if(head->data>sub_head->data){
         
         new_head->data=sub_head->data;
         sub_head=sub_head->next;
     }else if(head->data<sub_head->data){
         
         new_head->data=head->data;
         head=head->next;
     }else{
         
         new_head->data=head->data;
         head=head->next;
         sub_head=sub_head->next;
     }
        
    while(head!=NULL && sub_head!=NULL){
        
        if(head->data==sub_head->data){
            
            insertAtEnd(new_head, head->data);
            head=head->next;
            sub_head=sub_head->next;
        
        }else if(head->data<sub_head->data){
            insertAtEnd(new_head, head->data);
            head=head->next;
            
        }else{
            insertAtEnd(new_head, sub_head->data);
            sub_head=sub_head->next;
        }
    }
    for(;head!=NULL; head=head->next){
        insertAtEnd(new_head, head->data);
    }
    for(;sub_head!=NULL; sub_head=sub_head->next){
        insertAtEnd(new_head, sub_head->data);
    }
}

void mergeLinkedlist2(ListNode * first, ListNode * second, ListNode * &finale){// actual way
    
    ListNode * last=NULL;
    
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

void isloop(ListNode * s){ // to check loop
    
    ListNode * p=NULL,* q=NULL;
    p=q=s;
    
    do {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
        
    }while (p && q && p!=q);
    
    if(p==q){
        cout<<"The linked list is looped\n";
    }else{
        cout<<"The linked list is not looped\n";
    }
}

void print_circularlist(ListNode * head){
    
    ListNode * cur=head;
    
    do {
        cout<<cur->data<<" ";
        cur=cur->next;
        
    } while (cur!=head);
    
    cout<<"\n";
}

void Rprint_circularlist(ListNode * h, ListNode * &head){ // recursive version
    static int flag=0;
    if(h!=head || flag==0){
        flag=1;
        cout<<h->data<<" ";
        Rprint_circularlist(h->next,head);
    }
    flag=0;
}

int length_circularLinkedList(ListNode * head){
    int length=1;
    ListNode *cur=head->next;
    
    while(cur!=head){
        length++;
        cur=cur->next;
    }
    
    return length;
}

void insert_circularLinkedList(ListNode * &head,int data, int posn){
    
    ListNode *cur=head;
    int length=length_circularLinkedList(head);
    
    ListNode * temp = new ListNode;
    temp->data=data;
    temp->next=NULL;
    
    if(posn==0){
        if(head==NULL){
            head=temp;
            head->next=head;
        }else{
            while(cur->next!=head){
                cur=cur->next;
            }
            cur->next=temp;
            temp->next=head;
            head=temp;
        }
    }else if(posn>0 && posn<=length){
        for(int i=0; i<posn-1; i++){
            cur=cur->next;
        }
        temp->next=cur->next;
        cur->next=temp;
    }
}

void delete_circularLinkedlist(ListNode * &head, int posn){
    
    ListNode *cur=head;
    ListNode *last;
    int length=length_circularLinkedList(head);
    
    if(posn==1){
        head=head->next;
        last=head;
        while(last->next!=cur){
            last=last->next;
        }
        last->next=head;
        cur->next=NULL;
        delete cur;
        
    }else if(posn>1 && posn<=length){
        last=cur->next;
        for(int i=1; i<posn-1; i++){
            last=last->next;
            cur=cur->next;
        }
        cur->next=last->next;
        last->next=NULL;
        delete last;
    }
}

void create_double_linkedlist(int A[], int n, doubleListeNode * &first){
    
    doubleListeNode *t;
    doubleListeNode *last;
    
    first = new doubleListeNode;
    first->next=NULL;
    first->prev=NULL;
    first->data=A[0];
    last=first;
    
    for(int i=1; i<n; i++){
        t = new doubleListeNode;
        t->data=A[i];
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
    }
    
}

void print_doubleLinkedlist(doubleListeNode * first){
    
    int length=0;
    
    while(first){
        cout<<first->data<<" ";
        first=first->next;
        length++;
    }
    cout<<"\n";
    cout<<"length of double linked list --> "<<length<<endl;
}

int length_doubleLinkedlist(doubleListeNode * first){
    
    int length=0;
    
    while(first){
        first=first->next;
        length++;
    }
    return length;
}

void insert_doubleLinkedList(doubleListeNode * &head, int data, int posn){
    
    doubleListeNode * t = new doubleListeNode;
    t->next=NULL;
    t->prev=NULL;
    t->data=data;
    
    doubleListeNode * last=head;
    
    int length = length_doubleLinkedlist(head);
    
    if(posn==0){
        t->next=head;
        head->prev=t;
        head=t;
    }else if(posn>0 && posn<=length){
        for(int i=1; i<posn; i++){
            last=last->next;
        }
        if(last->next){
            last->next->prev=t;
        }
        t->next=last->next;
        t->prev=last;
        last->next=t;
        
    }else{
        delete t;
    }
}

void Delete_doubleLinkedlist(doubleListeNode * &head, int posn){ // Redo pls
    
    doubleListeNode * last=head;
    int length = length_doubleLinkedlist(head);
    
    if(posn==1){
        if(last->next==NULL){
            delete last;
        }else{
            head=head->next;
            delete head->prev;
            head->prev=NULL;
        }
    }else{
        for(int i=1; i<posn; i++){
            last=last->next;
        }
        if(last->next==NULL){
            last->prev->next=last->next;
            delete last;
        }else{
            last->prev->next=last->next;
            last->next->prev=last->prev;
            delete last;
        }
    }
}

void Reverse_doubleLinkedList(doubleListeNode * head, doubleListeNode * &first){
    
    doubleListeNode * cur;
    int flag=0;
    
    while(head!=NULL){
        
        cur=head->next;
        head->next=head->prev;
        head->prev=cur;
        head=head->prev;
        
        if(flag==1){
            break;
        }
        
        if(head->next==NULL){
            first=head;
            flag=1;
        }
    }
}

void middleElementOfLinkedList(ListNode * head){
    
    int len = length(head);
    
    for(int i=1; i<len/2; i++){
        head=head->next;
    }
    cout<<"Middle data of list = "<<head->data<<"\n";
}

void middleElementOfLinkedList2(ListNode * head){
    
    ListNode *p=head,*q=head;
    
    while(q){
        q=q->next;
        if(q)
            q=q->next;
        if(q)
            p=p->next;
    }
    cout<<"Middle data of list = "<<p->data<<"\n";
}

/*
--> use referencing for inserting element in the beginning
--> Its not a compulsion if you are manipulating other elements
*/

int main(int argc, const char * argv[]) {
    
    cout<<"size of the structure "<<sizeof(ListNode)<<"\n";
    int A[]={1,2,3,4,5};
    
    createList(A, 5, first);
    print(first);
    print_recursive(first);
    
    insertAtPosn(first, 6, 3);
    insertAtEnd(first, 9);

    insertAtBeginning(first, 0);
    insertAtBeginning(first, -1);
    print(first);

    cout<<"max --> "<<maximum(first)<<"\n";
    cout<<"min --> "<<minimum(first)<<"\n";
    
    linearSearch(first, 5);
    linearSearch(first, 12);
    
    searchLinear(first, 5);
    searchLinear(first, 9);
    print(first);
    
    DeleteBeginning(first);
    print(first);
    DeleteAtPosn(first, 4);
    print(first);
    DeleteAtPosn(first, 1);
    print(first);
    //cout<<first->data<<"\n";
    
    cout<<"length of the linked list = "<<length(first)<<"\n";
    
    struct ListNode *List = new ListNode;
    List->data=6;
    List->next=NULL;
    
    insertAtEnd(List, 5);
    insertAtPosn(List, 7, 2);
    List = insertAtBeginning(List, 0);
    
    print(List);
    
    cout<<"length of the linked list = "<<length(List)<<"\n";
    
    ListNode * sortedlist= new ListNode;
    sortedlist->data=9;
    sortedlist->next=NULL;
    
    sorted_insert(sortedlist, 3);
    sorted_insert(sortedlist, 6);
    sorted_insert(sortedlist, 6);
    sorted_insert(sortedlist, 6);
    sorted_insert(sortedlist, 17);
    print(sortedlist);
    
    checkSortedList(sortedlist);
    checkSortedList(first);
    
    removeDuplicate(sortedlist);
    print(sortedlist);
    
    reverseLinkedlist(first);
    print(first);
    reverseLinkedlistRecursion(NULL, first, first);
    print(first);
    
    concatenateLinkedlist(List, sortedlist);
    print(List);
    print(sortedlist);
    
    ListNode * sortedlist2 = new ListNode;
    sortedlist2->data=2;
    sortedlist2->next=NULL;
    
    sorted_insert(sortedlist2, 5);
    sorted_insert(sortedlist2, 9);
    sorted_insert(sortedlist2, 10);
    sorted_insert(sortedlist2, 18);
    
    print(sortedlist2);
    
    ListNode * newList = new ListNode;
    newList->next=NULL;
    
    mergeLinkedlist(sortedlist, sortedlist2, newList);// my attempt of merging
    print(newList);
    
    ListNode * merge_list_ex = new ListNode;
    merge_list_ex->next=NULL;
    
    mergeLinkedlist2(sortedlist, sortedlist2, merge_list_ex);
    print(merge_list_ex);
    
    createList(A, 5, loop_list);
    ListNode * sub=loop_list;
    while(sub->next!=NULL){
        sub=sub->next;
    }
    sub->next=loop_list;
    
    createList(A, 5, linked_list);
    
    isloop(loop_list);
    isloop(linked_list);
    
    print_circularlist(loop_list);
    Rprint_circularlist(loop_list,loop_list);
    cout<<"\n";
    
    // can be used to check if the linked list is circular
    for(int i=0; i<10; i++){
        cout<<sub->data<<" ";
        sub=sub->next;
    }
    cout<<"\n";
    
    insert_circularLinkedList(loop_list, 0, 0); // inserting in the beginning
    print_circularlist(loop_list);
    
    insert_circularLinkedList(loop_list, 6, 6); // inserting at the end
    print_circularlist(loop_list);
    
    insert_circularLinkedList(loop_list, 10, 4); // indexing starts from 0
    print_circularlist(loop_list);
    
    cout<<"Lenght of circular linked list --> "<<length_circularLinkedList(loop_list)<<"\n";
    
    // deleting from circular linked list
    delete_circularLinkedlist(loop_list, 1);
    print_circularlist(loop_list);
    delete_circularLinkedlist(loop_list, 4);
    print_circularlist(loop_list);
    
    doubleListeNode * doubleList; // new double linked list
    
    create_double_linkedlist(A, 5, doubleList); // creating double linked list
    print_doubleLinkedlist(doubleList);
    
    insert_doubleLinkedList(doubleList, 0, 0); // inserting element at the beginning
    print_doubleLinkedlist(doubleList);
    
    insert_doubleLinkedList(doubleList, 6, 2); // inserting element in any posn
    print_doubleLinkedlist(doubleList);
    
    insert_doubleLinkedList(doubleList, 7, 7); // inserting list at the end posn
    print_doubleLinkedlist(doubleList);
    
    cout<<"doubly linked list deletion-->\n";
    
    Delete_doubleLinkedlist(doubleList, 1); // deleting first element
    print_doubleLinkedlist(doubleList);
    
    Delete_doubleLinkedlist(doubleList, 2); // deleting an element at a particular posn
    print_doubleLinkedlist(doubleList);
    
    Delete_doubleLinkedlist(doubleList, 6); // deleting end posn element
    print_doubleLinkedlist(doubleList);
    
    Reverse_doubleLinkedList(doubleList,doubleList); // reversing the connections of doubly linked list
    print_doubleLinkedlist(doubleList);
    
    print(first);
    middleElementOfLinkedList(first); // method 1
    middleElementOfLinkedList2(first); // method 2
    
    
    
    return 0;
}
