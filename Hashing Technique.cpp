//
//  main.cpp
//  hashing techniques
//
//  Created by kalash kala on 10/09/21.
//

#include <iostream>
#include <list>
#include <iterator>

#define PRIME 7
#define SIZE 10

using namespace std;


int hashFunc(int x){
    return x%10;
}

// functions related to linear probing

int linearProbe(int H[], int key){
    
    int index=hashFunc(key);
    int i=0;
    while(H[(index+i)%10]!=0){
        i++;
    }
    
    return (index+i)%10;
    
}

void insert(int H[], int key){
    
    int index = hashFunc(key);
    
    if(H[index]!=0){
        index = linearProbe(H, key);
    }
    
    H[index] = key;
}

int Search(int H[], int key){

    int index = hashFunc(key);

    int i=0;

    while(H[(index+i)%10]!=key){
        i++;
        if(H[(index+i)%10]==0){
            cout<<"element not present\n";
            return -1;
        }
    }
    return (index+i)%10;
}

// functions related to Quadratic probing

int quadraticProbing(int H[], int key){
    
    int index = hashFunc(key);
    int i=0;
    
    while(H[(index+i*i)%10]!=0){
        i++;
    }
    
    return (index+i*i)%10;
}

void insertQuad(int H[], int key){
    
    int index = hashFunc(key);
    
    if(H[index]!=0){
        index = quadraticProbing(H, key);
    }
    
    H[index] = key;
}

int SearchQuad(int H[], int key){
    
    int index = hashFunc(key);
    int i=0;
    
    while(H[(index+i*i)%10]!=key){
        i++;
        if(H[(index+i*i)%10]==0){
            cout<<"element not find\n";
            return i;
        }
    }
    
    return (index+i*i)%10;
}

// functions related to double hashing

int primeHash(int key){
    return PRIME - (key%PRIME);
}

int doubleHash(int H[], int key){
    
    int index = hashFunc(key);
    int i=0;
    
    while(H[(hashFunc(key) + i*primeHash(key)) % SIZE] != 0){
        i++;
    }
    
    return (index + i*primeHash(key))%SIZE;
}

void insertDoubleHash(int H[], int key){
    
    int index = hashFunc(key);
    
    if(H[index]!=0){
        index = doubleHash(H, key);
    }
    
    H[index] = key;
}

int searchDoubleHash(int H[], int key){
    
    int index = hashFunc(key);
    int i=0;
    
    while(H[(hashFunc(key) + i*primeHash(key)) % SIZE] != key){
        i++;
        if(H[(hashFunc(key) + i*primeHash(key)) % SIZE] == 0){
            return -1;
        }
    }
    return (hashFunc(key) + i*primeHash(key)) % SIZE;
}

int main(int argc, const char * argv[]) {
    
    // chaining 
    
    list<int> l[10];
    
    int arg[]={456,12,98,765,567,1236,9,10,37,288,94};
    
    for(auto i : arg){
        l[hashFunc(i)].push_back(i);
    }
    
    for(int i=0; i<10; i++){
        if(l[i].size()){
            l[i].sort();
        }
    }
    
    for(int i=0; i<10; i++){
        cout<<i<<" -> ";
        for(auto it = l[i].begin(); it!=l[i].end(); it++){
            cout<<*it<<" ";
        }
        cout<<"\n";
    }
    
    //linear probing
    
    int H[10] = {0};
    
    insert(H, 12);
    insert(H, 25);
    insert(H, 35);
    insert(H, 26);
    
    cout<<"key 26 found at : "<<Search(H, 26)<<"\n";
    
    // Quadratic probing
    
    int HQ[10] = {0};
    
    insertQuad(HQ, 13);
    insertQuad(HQ, 23);
    insertQuad(HQ, 43);
    insertQuad(HQ, 27);
    
    cout<<"key 27 found at : "<<SearchQuad(HQ, 27)<<"\n";
    
    // double hashing
    
    int store[5] = {5,25,15,35,95};
    int HD[10] = {0};
    
    for(int i=0; i<5; i++){
        insertDoubleHash(HD, store[i]);
    }
    
    if(searchDoubleHash(HD, 35)!=-1){
        cout<<"element is present at posn : "<<searchDoubleHash(HD, 35)<<"\n";
    }else{
        cout<<"element is not present \n";
    }
    
    return 0;
}
