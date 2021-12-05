//
//  main.cpp
//  recursion_practice_cpp
//
//  Created by kalash kala on 01/04/21.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
void indirect_recursion_A(int n);
void indirect_recursion_B(int n);

int nested_recursion(int n){
    
    if(n>100){
        return n-10;
    }
    return nested_recursion(nested_recursion(n+11));
}

void tree_recursion(int n){
    
    if(n>0){
        cout<<n<<endl;
        tree_recursion(n-1);
        tree_recursion(n-1);
    }
    
}

int func1(int n){
    
    static int x = 0;
    
    if(n>0){
        x++;
        return func1(n-1) + x;
    }
    
    return 0;
}

int func(int n){
    
    if(n>0){
        return func(n-1) + n;
    }
    
    return 0;
}

int factorial(int n){
    
    if(n==0 || n==1){
        return 1;
    }
    return n * factorial(n-1);
}

int power(int n , int m){
    
    if(n==0){
        return 1;
    }
    return m * power(n-1, m);
}

int power1(int n ,int m){
    
    if(n==0){
        return 1;
    }else if(n%2==0){
        return power1(n/2, m*m);
    }
    
    return m * power1((n-1)/2, m*m);
}

float taylor_series(int n,int x){
    
    if(n==0){
        return 1;
    }
    
    return float(power1(n, x)/factorial(n) + taylor_series(n-1, x));
}

float taylor_series_1(float n , float x){ // using horners rule
    
    static float j = n+1;
    
    if(n==0){
        return 1;
    }

    return 1 + (x/(j-n))*taylor_series_1(n-1, x);
}

//memoization is trick to reduce the number of recursive calls in a function

int fib(int n){ // O(n) time complexity the trick used is called memoization
    
    if(n<=1){
    
        v[n]=n;
        return n;
    
    }
        
    if(v[n-2]==-1){
        v[n-2]=fib(n-2);
    }
    
    if(v[n-1]==-1){
        v[n-1]=fib(n-1);
    }
    
    return v[n-1] + v[n-2];

}

int ncr(int n, int r){ // using pascals triangle logic
    
    if(r==0 || r==n){
        return 1;
    }
    
    return ncr(n-1,r-1) + ncr(n-1,r);
}

void tower_of_hanoi(int n, int A,int B ,int C){
    
    if(n>0){
        tower_of_hanoi(n-1, A, C, B);
        cout<<"("<<A<<","<<C<<")"<<endl;
        tower_of_hanoi(n-1, B, A, C);
    }
}

int main(int argc, const char * argv[]) {
    
    int n = 5;
    
    cout<<"non static variable function output = "<<func(n)<<endl;
    cout<<"static variable function output = "<<func1(n)<<endl;
    cout<<"running static variable function once again = "<<func1(n)<<endl;
    cout<<"tree recursion example"<<endl;
    tree_recursion(3);
    cout<<"----------------------------------------------"<<endl;
    indirect_recursion_A(20);
    cout<<nested_recursion(95)<<endl;
    cout<<power(3,3)<<endl;
    cout<<power1(9, 2)<<endl;;
    cout<<taylor_series(3,4)<<endl;
    cout<<taylor_series_1(3,6)<<endl;
    v.assign(n+1, -1);
    cout<<fib(n)<<endl;
    cout<<ncr(n+1,5)<<endl;
    tower_of_hanoi(3, 1, 2, 3);
    return 0;
}

void indirect_recursion_B(int n){
    
    if(n>0){
        cout<<n<<endl;
        indirect_recursion_A(n/2);
    }
}

void indirect_recursion_A(int n){
    
    if(n>0){
        cout<<n<<endl;
        indirect_recursion_B(n-1);
    }
}

