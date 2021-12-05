//
//  main.cpp
//  sorting techniques
//
//  Created by kalash kala on 03/09/21.
//

#include <iostream>

using namespace std;

// Quick Sort

int partition(int A[], int l, int h){
    
    int pivot = A[l];
    int i=l, j=h;
    
    do{
        
        do{
            i++;
        }while(A[i]<=pivot);
        
        do{
            j--;
        }while(A[j]>pivot);
        
        if(i<j){
            swap(A[i], A[j]);
        }
                
    }while (i<=j);
    
    swap(A[l], A[j]);
    
    return j;
}

void quickSort(int A[], int l, int h){
    
    if(l<h){
        int j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j+1, h);
    }
}

//merge sort

void mergeSingle(int A[], int l, int mid, int h){
    
    int i=l;
    int k=l;
    int j=mid+1;
    
    int B[h+1];
    
    while(i<=mid && j<=h){
        if(A[i]<=A[j]){
            B[k++]=A[i++];
        }else{
            B[k++]=A[j++];
        }
        
    }
    
    for(;i<=mid; i++){
        B[k++]=A[i];
    }
    
    for(;j<=h; j++){
        B[k++]=A[j];
    }
    
    
    for(int x=l; x<=h; x++){
        A[x]=B[x];
    }
    
}

void iterativeMergeSort(int A[], int n){
    
    int p=0,l=0,h=0,mid=0;
    
    for(p=2 ; p<=n; p*=2){
        
        for(int i=0; i+p-1<n; i+=p){
            
            l=i;
            h=i+p-1;
            mid = (l+h)/2;
            mergeSingle(A, l, mid, h);
        }
    }
    
    if(p/2<n){
        mergeSingle(A, 0, p/2-1, n);
    }
    
}

void recursiveMergeSort(int A[], int l, int h){
    
    int mid;
    
    if(l<h){
        mid = (l+h)/2;
        recursiveMergeSort(A, l, mid);
        recursiveMergeSort(A, mid+1, h);
        mergeSingle(A, l, mid, h);
    }
    
}

// count sort

void countSort(int A[], int n){
    
    int m = *max_element(A, A+n);
    
    int c[m+1];
    
    for(int i=0; i<m+1; i++){
        c[i]=0;
    }
    
    for(int i=0; i<n; i++){
        c[A[i]]++;
    }
    
    int i=0, j=0;
    
    while(i<m+1){
        if(c[i]>0){
            A[j++]=i;
            c[i]--;
        }else{
            i++;
        }
    }
}

// Radix sort

void Count(int arg[], int n, int exp){
    
    int output[n];
    int count[10]={0};
    
    for(int i=0; i<n; i++){
        count[(arg[i]/exp)%10]++;
    }
    
    for(int i=1; i<10; i++){
        count[i]+=count[i-1];
    }
    
    for(int i=n-1; i>=0; i--){
        output[count[(arg[i]/exp)%10]-1] = arg[i];
        count[(arg[i]/exp)%10]--;
    }
    
    
    for(int i=0; i<n; i++){
        arg[i]=output[i];
    }
    
}

void radixSort(int arg[], int n){
    
    int m = *max_element(arg, arg+n);
    
    for(int i=1; i<m; i*=10){
        Count(arg, n, i);
    }
    
}

void shellSort(int arg[], int n){

     for(int gap=n/2; gap>=1; gap/=2){
        
        for(int i=gap; i<n; i++){
            
            int temp = arg[i];
            int j=i-gap;
            
            while(j>=0 && arg[j]>temp){
                arg[j+gap]=arg[j];
                j-=gap;
            }
            
            arg[j+gap] = temp;
        }
    }

}

int main(int argc, const char * argv[]) {

    int arg[]={7,5,9,1,3,6,2,8,INT_MAX};
    
    quickSort(arg, 0, 8);
    cout<<"QuickSort\n";
    for(int i=0; i<8; i++){
        cout<<arg[i]<<" ";
    }
    cout<<"\n";
    
    int arg1[]={7,5,9,1,3,6,2,8,10};
    
    iterativeMergeSort(arg1, 9);
    cout<<"Iterative MergeSort\n";
    for(int i=0; i<9; i++){
        cout<<arg1[i]<<" ";
    }
    cout<<"\n";
    
    int arg2[]={7,5,9,1,3,6,2,8,10};
    
    recursiveMergeSort(arg2, 0, 8);
    cout<<"Recursive Mergesort\n";
    for(int i=0; i<9; i++){
        cout<<arg2[i]<<" ";
    }
    cout<<"\n";
    
    int arg3[]={7,5,9,1,3,6,2,8,10};
    
    countSort(arg3, 9);
    cout<<"Count Sort\n";
    for(int i=0; i<9; i++){
        cout<<arg3[i]<<" ";
    }
    cout<<"\n";
    
    int arg4[]={170,45,75,90,802,24,2,66};
    
    radixSort(arg4, 8);
    cout<<"Radix Sort\n";
    for(int i=0; i<8; i++){
        cout<<arg4[i]<<" ";
    }
    cout<<"\n";
    
    int arg5[]={170,45,75,90,802,24,2,66};
    
    shellSort(arg5, 8);
    cout<<"Shell Sort\n";
    for(int i=0; i<8; i++){
        cout<<arg5[i]<<" ";
    }
    cout<<"\n";
    
    return 0;
}
