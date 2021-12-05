//
//  main.cpp
//  Graph
//
//  Created by kalash kala on 17/09/21.
//

#include <iostream>
#include <queue>
#include <stack>

#define I INT_MAX

using namespace std;

void BFS(int vtx, int A[][8], int n){

    cout<<vtx<<" ";
    
    queue<int> q;
    int visited[8]={0};
    visited[vtx] = 1;
    q.emplace(vtx);
    
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=1; v<=n; v++){
            if(A[u][v]==1 && visited[v]==0){
                cout<<v<<" ";
                visited[v] = 1;
                q.emplace(v);
            }
        }
    }
    
    cout<<"\n";
}

void DFS(int u, int A[][8], int n){
    
    static int visited[8] = {0};
    
    if(visited[u]==0){
        cout<<u<<" ";
        visited[u] = 1;
        
        for(int v=1; v<n; v++){
            if(A[u][v]==1 && visited[v]==0){
                DFS(v, A, n);
            }
        }
    }
}

void DFS_stack(int u, int A[][8], int n){
    
    stack<int> st;
    int visited[8]={0};
    
    st.push(u);
    visited[u]=1;
    cout<<u<<" ";
    
    while(!st.empty()){
        
        int store = st.top();
        
        for(int i=1; i<n; i++){
            if(A[store][i]==1 && visited[i]==0){
                
                st.push(i);
                visited[i]=1;
                store = st.top();
                cout<<store<<" ";
                i=1;
            }
        }
        st.pop();
    }
    
    cout<<"\n";
}

void primsAlgorithm(int cost[][8],int t[][7],int near[]){
    
    int min = I,n = 8,u=0,v=0;
    
    for(int i=1; i<n; i++){
        for(int j=i; j<n; j++){
            if(min>cost[i][j]){
                min = cost[i][j];
                u=i;
                v=j;
            }
        }
    }
    
    t[0][0]=u;
    t[1][0]=v;
    near[u]=near[v]=0;
    
    for(int i=1; i<n; i++){

        if(near[i]!=0){
            if(cost[u][i]<cost[v][i]){
                near[i] = u;
            }else{
                near[i] = v;
            }
        }
    }
    
    int k=0;
    
    for(int i=1; i<n-1; i++){
        
        min = I;
        for(int j=1; j<n; j++){
            if(near[j]!=0 && cost[j][near[j]]<min){
                min = cost[j][near[j]];
                k=j;
            }
        }
        
        t[0][i]=k;
        t[1][i]=near[k];
        near[k]=0;
        
        for(int j=1; j<n; j++){
            if(near[j]!=0 && cost[j][k]<cost[j][near[j]]){
                near[j] = k;
            }
        }
    }
    
    for(int i=0; i<n-1; i++){
        cout<<"("<<t[0][i]<<","<<t[1][i]<<")\n";
    }
}

// Disjoint set function weighted union and find

void weightedUnion(int u, int v, int set[]){
    if(set[u]<set[v]){
        set[u] += set[v];
        set[v] = u;
    }else{
        set[v]+=set[u];
        set[u] = v;
    }
}

int find(int u, int set[]){
    int x = u,v=0;
    
    while(set[x]>0){
        x = set[x];
    }
    
    while(u!=x){
        
        v=set[u];
        set[u]=x;
        u=v;
    }
    
    return x;
}

void kruskalsProgram(int edges[][9], int set[], int included[], int tt[][6]){
    int i=0,j,k,n=7,e=9,min,u,v;
    
    while(i<n-1){
        min = I;
        for(j=0; j<e; j++){
            if(included[j]==0 && edges[2][j]<min){
                min = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }
        
        if(find(u,set)!=find(v,set)){
            tt[0][i] = u;
            tt[1][i] = v;
            weightedUnion(find(u,set), find(v,set), set);
            i++;
        }
        included[k]=1;
    }
    
    for(int i=0; i<n-1; i++){
        cout<<"("<<tt[0][i]<<","<<tt[1][i]<<")\n";
    }
}

int main(int argc, const char * argv[]) {
    
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
    
    cout<<"BFS : \n";
 
    cout<<"Vertex: 1 -> ";
    BFS(1, A, 8);
 
    cout<<"Vertex: 4 -> ";
    BFS(4, A, 8);
    
    cout<<"DFS : \n";
    cout<<"Vertex: 4 -> ";
    DFS(4, A, 8);
    cout<<"\n";
    
    cout<<"Vertex: 1 -> ";
    DFS_stack(1, A, 8);
    
    int B[8][8] = {{I, I, I, I, I, I, I, I},
                   {I, I, 25, I, I, I, 5, I},
                   {I, 25, I, 12, I, I, I, 10},
                   {I, I, 12, I, 8, I, I, I},
                   {I, I, I, 8, I, 16, I, 14},
                   {I, I, I, I, 16, I, 20, 18},
                   {I, 5, I, I, I, 20, I, I},
                   {I, I, 10, I, 14, 18, I, I}};
    
    int near[8] = {I,I,I,I,I,I,I,I};
    int t[2][7];
    
    cout<<"Prims Algorithm : \n";
    primsAlgorithm(B, t, near);
    
    int edges[3][9] = {{1,1,2,2,3,4,4,5,5},
                       {2,6,3,7,4,5,7,6,7},
                       {25,5,12,10,8,16,14,20,18}};
    int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
    int included[9] = {0};
    int tt[2][6];
    
    cout<<"Kruskals Algorithm : \n";
    kruskalsProgram(edges, set, included, tt);
    
    return 0;
}
