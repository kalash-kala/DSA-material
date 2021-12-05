//
//  array_h_ex.h
//  array_practice_cpp
//
//  Created by kalash kala on 18/04/21.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#ifndef array_h_ex_h
#define array_h_ex_h

using namespace std;

template <class T>

class ARR{

private:

    T *A=NULL;
    int size;
    int length;

public:

    ARR(){
        size=0;
        length=0;
    }
    
    ARR(int size, int length){
        this->size=size;
        this->length=length;
        A = new T[size];
    }
    
    void get(){
        if(size==0 && length==0){
            cout<<"Enter the size\n";
            cin>>size;
            cout<<"Enter the length\n";
            cin>>length;
            A=new T[size];
            for(int i=0; i<length; i++){
                cin>>A[i];
            }
        }else{
            for(int i=0; i<length; i++){
                cin>>A[i];
            }
        }
    }
    
    void Display();
    void Delete(int index);
    void Insert(int index, T val);
    ARR * union_array(ARR B);
    void pair_sum(int arr[], int k, int n);
    
};

template <class T>

void ARR<T>::Display(){
    
    for(int i=0; i<length; i++){
        cout<<A[i]<<" ";
    }
    cout<<"\n";
}

template <class T>

void ARR<T>::Delete(int index){
    
    for(int i=index; i<length-1; i++){
        A[i]=A[i+1];
    }
    A[length-1]=0;
}

template <class T>

void ARR<T>::Insert(int index, T val){
    
    if(length>=size || index<0 || index>length){
        cout<<"Not Possible \n";
    }else{
        length++;
        for(int i=length;i>index;i--){
            A[i]=A[i-1];
        }
        A[index]=val;
        length++;
    }
}

template <class T>

ARR<T> * ARR<T>::union_array(ARR<T> B){
    
    int i=0,j=0,k=0;
    ARR<T> *C;
    C=new ARR<T>(100,length+B.length);
    while(i<length && j<B.length){
        if(A[i]<B.A[j]){
            C->A[k++]=A[i++];
        }else if(A[i]>B.A[j]){
            C->A[k++]=B.A[j++];
        }else{
            C->A[k++]=A[i++];
            j++;
        }
    }
    for(;i<length;i++)
        C->A[k++]=A[i];
    for(;j<B.length;j++)
        C->A[k++]=B.A[j];
    C->length=k;
    return C;
}

template <class T>

void ARR<T>::pair_sum(int *arr, int k, int n){
    
    int count = 0;
    
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j]==k-arr[i]){
                count++;
            }
        }
    }
    cout<<count<<"\n";
}

#endif /* array_h_ex_h */
