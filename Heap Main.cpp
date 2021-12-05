//
//  main.cpp
//  Heap
//
//  Created by kalash kala on 21/08/21.
//

#include <iostream>
#include <vector>

using namespace std;

void insertHeapMax(vector<int> &v, int data){

    v.push_back(data);

    int cur = (int)v.size();
    int i = (int)v.size()/2;

    while(i!=0 && v[i-1]<data){ // for max heap we use <

        swap(v[i-1], v[cur-1]);

        data = v[i-1];
        cur/=2;
        i/=2;
    }
}

void insertHeapMin(vector<int> &v, int data){
    
    v.push_back(data);
    
    int cur = (int)v.size();
    int i = (int)v.size()/2;
    
    while(i!=0 && v[i-1]>data){ // for min heap we use >
        
        swap(v[i-1], v[cur-1]);
        
        data = v[i-1];
        cur/=2;
        i/=2;
    }
}

int delHeapMax(vector<int> &v){
    
    swap(v.front(), v.back());
    int element = v.back();
    v.pop_back();
    
    int i=0,size=(int)v.size();
    
    while(2*i+2<size){
                
        if(v[2*i+1]<v[2*i+2] && v[i]<v[2*i+2]){
            swap(v[i], v[2*i+2]);
            i=2*i+2;
        }else if(v[2*i+1]>v[2*i+2] && v[i]<v[2*i+1]){
            swap(v[i], v[2*i+1]);
            i=2*i+1;
        }else{
            break;
        }
    
    }
    
    return element;
    
}

int delHeapMin(vector<int> &v){
    
    swap(v.front(), v.back());
    int element = v.back();
    v.pop_back();
    
    int i=0,size=(int)v.size();
    
    while(2*i+2<size){
                
        if(v[2*i+1]>v[2*i+2] && v[i]>v[2*i+2]){
            swap(v[i], v[2*i+2]);
            i=2*i+2;
        }else if(v[2*i+1]<v[2*i+2] && v[i]>v[2*i+1]){
            swap(v[i], v[2*i+1]);
            i=2*i+1;
        }else{
            break;
        }
    
    }
    
    return element;
    
}

/*
 heap sort :
 1. insert n elements
 2. delete n elements
 */

void heapSortAscending(vector<int> &v){
    
    vector<int> sub;

    int size = (int)v.size();
    
    for(int i=0; i<size ; i++){
        insertHeapMin(sub, v[i]);
    }
    
    for(int i=0; i<size; i++){
        cout<<delHeapMin(sub)<<" ";
    }
    cout<<"\n";
}

void heapSortDescending(vector<int> &v){
    
    
    vector<int> sub;

    int size = (int)v.size();
    
    for(int i=0; i<size ; i++){
        insertHeapMax(sub, v[i]);
    }
    
    for(int i=0; i<size; i++){
        cout<<delHeapMax(sub)<<" ";
    }
    cout<<"\n";
    
}

void heapifyMax(vector<int> &v, int n, int i){
    
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left<n && v[largest]<v[left]){
        largest=left;
    }
    
    if(right<n && v[largest]<v[right]){
        largest=right;
    }
    
    if(largest!=i){
        swap(v[i], v[largest]);
        heapifyMax(v, n, largest);
    }
    
}

void heapifyMin(vector<int> &v, int n, int i){
    
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    
    if(left<n && v[smallest]>v[left]){
        smallest=left;
    }
    
    if(right<n && v[smallest]>v[right]){
        smallest=right;
    }
    
    if(smallest!=i){
        swap(v[i], v[smallest]);
        heapifyMin(v, n, smallest);
    }
    
}

int main(int argc, const char * argv[]) {
    
    vector<int> v = {30,20,15,5,10,12,6}; //sample heap
    
    insertHeapMax(v,40); //inserting 40
    insertHeapMax(v,35); //inserting 35
    
    for(auto it=v.begin(); it!=v.end(); it++){
        cout<<*it<<" ";
    }
    cout<<"\n";
    
    vector<int> H;
    int data = 0;
    /*
     for(int i=0; i<7; i++){ //creating heap using insert function
         cout<<"enter a data : \n";
         cin>>data;
         insertHeapMax(H, data);
     }
     
     for(auto it=H.begin(); it!=H.end(); it++){
         cout<<*it<<" ";
     }
     cout<<"\n";
     
     delHeapMax(H); //deleting the max element
     
     for(auto it=H.begin(); it!=H.end(); it++){
         cout<<*it<<" ";
     }
     cout<<"\n";
     */
    
    cout<<"heap sort \n";
    vector<int> heapsort = {30,2,80,94,69,4,54};
    
    cout<<"unsorted array : ";
    for(auto it = heapsort.begin(); it!=heapsort.end(); it++){
        cout<<*it<<" ";
    }
    cout<<"\n";
    
    cout<<"sorted array (Ascending): ";
    heapSortAscending(heapsort);
    
    cout<<"sorted array (Descending): ";
    heapSortDescending(heapsort);
    
    cout<<"heapify\n";
    vector<int> heapify={5,10,30,20,35,40,15};
    int size = heapify.size();
    
    for(int i=size/2-1; i>=0; i--){
        heapifyMax(heapify, size, i);
    }
    
    for(auto it=heapify.begin(); it<heapify.end(); it++){
        cout<<*it<<" ";
    }
    cout<<"\n";
    
    //converting max to min heap
    
    for(int i=size/2-1; i>=0; i--){
        heapifyMin(heapify, size, i);
    }
    
    for(auto it=heapify.begin(); it<heapify.end(); it++){
        cout<<*it<<" ";
    }
    cout<<"\n";
    
    return 0;
}
