//
//  stack_class.h
//  stacks_cpp
//
//  Created by kalash kala on 17/05/21.
//

#ifndef stack_class_h
#define stack_class_h

#include <iostream>

using namespace std;

template<class T>

class stackClass{
    
public:
    int size;
    T * start;
    int top;
    
    stackClass(){
        size=10;
        start = new int[size];
        top=-1;
    }
    
    stackClass(int size){
        this->size=size;
        start = new T[size];
        top=-1;
    }
    
    void push(T data);
    T pop();
    T peek(int posn);
    bool isEmpty();
    bool isFull();
    T stackTop();
    int paranthesisMatching(string exp);
    
    ~stackClass(){
        //cout<<"object destroyed\n";
        start=NULL;
        delete start;
    }
};

template<class T>

void stackClass<T>::push(T data){
    if(top==size-1){
        cout<<"Stack Overflow\n";
    }else{
        top++;
        start[top]=data;
    }
}

template<class T>

T stackClass<T>::pop(){
    T x=-1;
    if(top==-1){
        cout<<"Stack Underflow\n";
    }else{
        x=start[top];
        top--;
    }
    return x;
}

template<class T>

T stackClass<T>::peek(int posn){
    T x=-1;
    
    if(posn>top+1){
        cout<<"Invalid Position\n";
    }else{
        x=start[top-posn+1];
    }
    return x;
}

template<class T>

bool stackClass<T>::isEmpty(){
    if(top==-1){
        return true;
    }
    return false;
}

template<class T>

bool stackClass<T>::isFull(){
    if(top==size-1){
        return true;
    }
    return false;
}

template<class T>

T stackClass<T>::stackTop(){
    if(top==-1){
        cout<<"No Element\n";
        return -1;
    }
    return start[top];
}

template<class T>

int stackClass<T>::paranthesisMatching(string exp){
    
    size_t len = exp.length();
    
    stackClass st(len);
    
    for(int i=0; i<len; i++){
        
        if(exp[i]=='('){
            push(1);
        }else if(exp[i]==')'){
            if(st.top==-1){
                cout<<"Imbalanced Expression\n";
                return -1;
            }
            pop();
        }
    }
    if(isEmpty()){
        cout<<"Balanced Expression\n";
    }else{
        cout<<"Imbalanced Expression\n";
    }
    
    return 0;
}


#endif /* stack_class_h */
