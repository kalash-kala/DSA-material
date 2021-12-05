//
//  main.cpp
//  stacks_cpp
//
//  Created by kalash kala on 17/05/21.
//

#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_class.h"
#include "stack_class_LinkedList.h"

using namespace std;

struct stack{
    int size;
    int top=-1;
    int *start;
};

struct stackNode{
    int data;
    stackNode * next;
};

void createStack(stack * st){
    cout<<"Enter the size\n";
    cin>>st->size;
    st->top=-1;
    st->start=new int[st->size];
}

void Display(stack st){
    for(int i=st.top; i>=0; i--){
        cout<<st.start[i]<<"\n";
    }
}

void push(stack * st,int data){
    if(st->top==st->size-1){
        cout<<"Stack Overflow\n";
    }else{
        st->top++;
        st->start[st->top]=data;
    }
}

int pop(stack * st){
    int x=-1;
    if(st->top==-1){
        cout<<"Stack Underflow";
    }else{
        x=st->start[st->top];
        st->top--;
    }
    return x;
}

int peek(stack st,int posn){
    int x=-1;
    
    if(posn>st.top+1){
        cout<<"Invalid Position\n";
    }else{
        x=st.start[st.top-posn+1];
    }
    return x;
}

bool isEmpty(stack st){
    if(st.top==-1){
        return true;
    }
    return false;
}

bool isFull(stack st){
    if(st.top==st.size-1){
        return true;
    }
    return false;
}

int stackTop(stack st){
    if(st.top==-1){
        cout<<"No Element\n";
        return -1;
    }
    return st.start[st.top];
}

void push(stackNode * &st,int data){ // Function overloaded
    stackNode *temp = new stackNode;
    if(temp==NULL){
        cout<<"Stack Overflow\n";
    }else{
        temp->next=st;
        temp->data=data;
        st=temp;
    }
}

int pop(stackNode * &st){ //Function overloaded
    int x=-1;
    if(st==NULL){
        cout<<"Stack Underflow\n";
    }else{
        stackNode * cur=st;
        x=cur->data;
        st=st->next;
        cur=NULL;
        delete cur;
    }
    return x;
}

void Display(stackNode * st){ //Funtion Overloaded
    stackNode * cur=st;
    while(cur->next!=NULL){
        cout<<cur->data<<" ";
        cur=cur->next;
    }
    cout<<"\n";
}

bool isEmpty(stackNode * st){ //Function Overloaded
    if(st==NULL){
        return true;
    }
    return false;
}

bool isFull(){ // Function Overloaded
    stackNode * temp = new stackNode;
    if(temp==NULL){
        delete temp;
        return true;
    }
    delete temp;
    return false;
}

int stackTop(stackNode * st){ // Function Overloaded
    if(st==NULL){
        cout<<"No Element\n";
        return -1;
    }
    return st->data;
}

int peek(stackNode * st,int posn){ //Function Overloaded
    
    for(int i=0; i<posn-1 && st!=NULL ; i++){
        st=st->next;
    }
    if(st==NULL){
        cout<<"Inavlid position\n";
        return -1;
    }
    return st->data;
}

int paranthesisMatching(string exp){ // important
    
    size_t len = exp.length();
    
    stack st;
    st.start=new int[len];
    st.top=-1;
    
    for(int i=0; i<len; i++){
        
        if(exp[i]=='('){
            push(&st, 1);
        }else if(exp[i]==')'){
            if(st.top==-1){
                cout<<"Imbalanced Expression\n";
                return -1;
            }
            pop(&st);
        }
    }
    if(isEmpty(st)){
        cout<<"Balanced Expression\n";
    }else{
        cout<<"Imbalanced Expression\n";
    }
    
    return 0;
}

int diffParanthesisMatching(string exp){ // important
    
    int len=(int)exp.length();
    
    stackClass<char> st(len);
    char res='\0';
    
    for(int i=0; i<len; i++){
        
        if(exp[i]=='{' || exp[i]=='[' || exp[i]=='('){
            st.push(exp[i]);
            res=exp[i];
        }else{
            if(st.top==-1){
                cout<<"Imbalanced Expression\n";
                return -1;
            }
            if(res=='[' && exp[i]==']'){
                st.pop();
            }else if(res=='{' && exp[i]=='}'){
                st.pop();
            }else if(res=='(' && exp[i]==')'){
                st.pop();
            }else{
                cout<<"Imbalanced Expression\n";
                return -1;
            }

            res=st.start[st.top];
        }
    }
    
    if(st.isEmpty()){
        cout<<"Balanced\n";
    }else{
        cout<<"Imbalanced\n";
    }
    
    return 0;
}

int precedence(char c){ // for the infix to postfix
    
    if(c=='*' || c=='/'){
        return 2;
    }
    return 1;
}

void infixToPostfix1(string exp){ // Type 1 (excluding associativity and paranthesising)
    
    int size = (int)exp.length();
    stackClass<char>st(size);
    string postfixExp;
    
    int i=0;
    while(exp[i]){
        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='/' || exp[i]=='*'){
            
            if(st.top==-1){
                st.push(exp[i++]);
            }else if(precedence(exp[i])>precedence(st.start[st.top])){
                st.push(exp[i++]);
            }else{
                postfixExp+=st.pop();
            }
        }else{
            postfixExp+=exp[i++];
        }
    }
    while(!st.isEmpty()){
        postfixExp+=st.pop();
    }
    
    cout<<postfixExp<<"\n";
}

int outStackPre(char c){
    
    if(c=='+' || c=='-'){
        return 1;
    }else if(c=='*' || c=='/'){
        return 3;
    }else if(c=='^'){
        return 6;
    }else if(c=='('){
        return 7;
    }else if(c==')'){
        return 0;
    }
    return -1; // for something nonsense
}

/*
 if the difference between outStackPre
 and inStackPre is +ve then the associativity is L->R
 if it is -ve then it is R->L
 */

int inStackPre(char c){
    
    if(c=='+' || c=='-'){
        return 2;
    }else if(c=='*' || c=='/'){
        return 4;
    }else if(c=='^'){
        return 5;
    }else if(c=='('){
        return 0;
    }
        return -1; // if c==') or something nonsense'
}

string infixToPostfix2(string exp){
    
    int size = (int)exp.length();
    stackClass<char>st(size);
    string postfixExp;
    
    int i=0;
    char x;
    while(exp[i]){
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'||exp[i]=='/'||exp[i]=='^'||exp[i]=='('||exp[i]==')'){
            
            if(st.top==-1){
                st.push(exp[i++]);
            }else if(outStackPre(exp[i])>inStackPre(st.start[st.top])){
                st.push(exp[i++]);
            }else{
                x=st.pop();
                if(x!='('){
                    postfixExp +=x;
                }
            }
        }else{
            postfixExp+=exp[i++];
        }
    }
    while(!st.isEmpty() && st.start[st.top]!=')'){
        postfixExp+=st.pop();
    }
    
    return postfixExp;
}

int postfixVal(string s){
    
    int len = (int)s.length();
    stackClass<int>st(len);
    
    int i=0,a=0,b=0;
    
    while(s[i]){
        
        if(s[i]=='+'){
            b=st.pop();
            a=st.pop();
            st.push(a+b);
        }else if(s[i]=='-'){
            b=st.pop();
            a=st.pop();
            st.push(a-b);
        }else if(s[i]=='*'){
            b=st.pop();
            a=st.pop();
            st.push(a*b);
        }else if(s[i]=='/'){
            b=st.pop();
            a=st.pop();
            st.push(a/b);
        }else if(s[i]=='^'){
            b=st.pop();
            a=st.pop();
            st.push(pow(a, b));
        }else{
            st.push((int)s[i]-48);
        }
        i++;
    }
    
    cout<<st.start[st.top]<<"\n";
    
    return 0;
}

/*
 stacks using linked list the pointer variable acts as Top variable
 */

int main(int argc, const char * argv[]) {
    
    // array stack
     stack st;
     cout<<"Enter size of stack\n";
     cin>>st.size;
     cout<<"-------------------\n";
     
     if(isEmpty(st)){
         cout<<"Empty Stack\n";
     }
     
     st.start=new int[st.size];
     
     for(int i=0; i<st.size; i++){
         push(&st, i+1);
     }
     cout<<"After pushing\n";
     Display(st);
     
     cout<<"element at 4th posn from the top = "<<peek(st, 4)<<"\n";
     // to check the value at a particular stack level
     
     for(int i=0; i<st.size-2; i++){
         pop(&st);
     }
     cout<<"-------------------\n";
     cout<<"After popping\n";
     Display(st);
     
     cout<<"Topmost element = "<<stackTop(st)<<"\n";
     
     st.start=NULL;
     delete st.start;
     
     // stack linked list
     stackNode * Top = NULL;
     
     cout<<"-------------------\n";
     if(isEmpty(Top)){
         cout<<"Empty Stack\n";
     }
     
     Top =new stackNode;
     
     for(int i=10; i<=100; i+=10){
         push(Top, i);
     }
     
     cout<<"After pushing\n";
     Display(Top);
     
     for(int i=0; i<5; i++){
         pop(Top);
     }
     cout<<"-------------------\n";
     cout<<"After popping\n";
     Display(Top);
     
     cout<<"Topmost element = "<<stackTop(Top)<<"\n";
     cout<<"element at 4th posn from the top = "<<peek(Top, 4)<<"\n";
     
     cout<<"-------------------\n";
     cout<<"Enter an Expression\n";
     
     string str;
     cin>>str;
     
     paranthesisMatching(str);
     
     cout<<"Enter another Expression\n";
     string str1;
     cin>>str1;
     
     diffParanthesisMatching(str1);
     
    
    
    cout<<"Enter another Expression\n";
    string str2;
    cin>>str2;
     
    infixToPostfix1(str2);
     
    cout<<"Enter another Expression\n";
    string str3;
    cin>>str3;
    
    cout<<infixToPostfix2(str3)<<"\n";
    postfixVal(infixToPostfix2(str3));
     
    postfixVal("15+66/*8-");
    
    return 0;
}
