//
//  main.cpp
//  Segmented Tree
//
//  Created by kalash kala on 02/12/21.
//

#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void buildTree(ll* arr, ll* tree, int start, int end, int treeNode){
    
    if(start==end){ // base case
        tree[treeNode] = arr[start];
        return;
    }
    
    int mid = start + (end-start)/2;
    
    // first go to the base cases and then calculate the early values
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    
    // using next 2 values to calculate the current one
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

void updateTree(ll* arr, ll* tree, int start, int end, int treeNode, ll idx, ll val){
    
    if(start==end){// base case
        arr[idx] = val;
        tree[treeNode] = val;
        return;
    }
    
    int mid = start + (end-start)/2;
    
    if(idx>mid){ // if index is greater than mid then that index is present on right side
        updateTree(arr, tree, mid+1, end, 2*treeNode+1, idx, val);
    }else{ // if index is less than mid then that index is present on left side
        updateTree(arr, tree, start, mid, 2*treeNode, idx, val);
    }
    
    tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

ll query(ll* tree, int start, int end,int treeNode, ll L, ll R){
    
    // completely outside range return 0
    if(start>R || end<L){
        return 0;
    }
    // if the subarray is in range
    if(start>=L && end<=R){
        return tree[treeNode];
    }
    // if it is partially in range
    int mid = start + (end-start)/2;
    ll ans1 = query(tree,start,mid,2*treeNode,L,R);
    ll ans2 = query(tree,mid+1,end,2*treeNode+1,L,R);
    
    return ans1+ans2;
}


void implementationOfSegmentedTree(){
    
        ll arr[] = {1,2,3,4,5,6,7,8,9};
        ll tree[18];
        // size of tree = 2n-1 (only for this case else we should take 4n)
        // we are assuming the start of the array from index 1;
        buildTree(arr, tree, 0, 8, 1);
        
        for(int i=1; i<18; i++){
            cout<<tree[i]<<" ";
        }
        cout<<"\n";
        
        ll arr1[] = {1,2,3,4,5};
        ll tree1[10];
        
        buildTree(arr1, tree1, 0, 4, 1);
        cout<<"Before Update\n";
        for(int i=1; i<10; i++){
            cout<<tree1[i]<<" ";
        }
        cout<<"\n";
        
        updateTree(arr1, tree1, 0, 4, 1, 2, 10);
        cout<<"After Update\n";
        for(int i=1; i<10; i++){
            cout<<tree1[i]<<" ";
        }
        cout<<"\n";
        
        cout<<"Finding sum of [2,4] interval elements : ";
        ll ans = query(tree1,0,4,1,2,4);
        cout<<ans<<"\n";
        
}

void buildTreeMin(ll* arr, ll* tree, int start, int end, int treeNode){
    
    if(start==end){ // base case
        tree[treeNode] = arr[start];
        return;
    }
    
    int mid = start + (end-start)/2;
    
    // first go to the base cases and then calculate the early values
    buildTreeMin(arr, tree, start, mid, 2*treeNode);
    buildTreeMin(arr, tree, mid+1, end, 2*treeNode+1);
    
    // using next 2 values to calculate the current one
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
}

void updateTreeMin(ll* arr, ll* tree, int start, int end, int treeNode, ll idx, ll val){
    
    if(start==end){// base case
        arr[idx] = val;
        tree[treeNode] = val;
        return;
    }
    
    int mid = start + (end-start)/2;
    
    if(idx>mid){ // if index is greater than mid then that index is present on right side
        updateTreeMin(arr, tree, mid+1, end, 2*treeNode+1, idx, val);
    }else{ // if index is less than mid then that index is present on left side
        updateTreeMin(arr, tree, start, mid, 2*treeNode, idx, val);
    }
    
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
}

ll queryMin(ll* tree, int start, int end,int treeNode, ll L, ll R){
    
    // completely outside range return 0
    if(start>R || end<L){
        return INT_MAX;
    }
    // if the subarray is in range
    if(start>=L && end<=R){
        return tree[treeNode];
    }
    // if it is partially in range
    int mid = start + (end-start)/2;
    ll ans1 = queryMin(tree,start,mid,2*treeNode,L,R);
    ll ans2 = queryMin(tree,mid+1,end,2*treeNode+1,L,R);
    
    return min(ans1,ans2);
}

void minimunNumberInSubArray(){
    
    int n = 0, q = 0;
    cin>>n>>q;
    
    ll arg[n];
    for(int i=0; i<n; i++){
        cin>>arg[i];
    }
    
    ll tree[4*n];
    buildTreeMin(arg, tree, 0, n-1, 1);
    
    vector<char> order(q);
    vector<pair<ll,ll>> val(q);
    
    for(int i=0; i<q; i++){
        cin>>order[i];
        cin>>val[i].first>>val[i].second;
        if(order[i]=='q'){
            cout<<queryMin(tree,0,n-1,1,val[i].first-1,val[i].second-1)<<"\n";
        }else{
            updateTreeMin(arg,tree,0,n-1,1,val[i].first-1,val[i].second);
        }
    }
}

void build(ll* arg, vector<pair<ll, ll>>& tree, int start, int end, int treeNode){
    
    if(start==end){
        tree[treeNode] = make_pair(arg[start], -1);
        return;
    }
    
    int mid = start + (end-start)/2;
    
    build(arg, tree, start, mid, 2*treeNode);
    build(arg, tree, mid+1, end, 2*treeNode+1);
    
    ll store[4] = {0};
    store[0] = tree[2*treeNode].first;
    store[1] = tree[2*treeNode].second;
    store[2] = tree[2*treeNode+1].first;
    store[3] = tree[2*treeNode+1].second;
    
    sort(store, store+4);
    
    tree[treeNode] = make_pair(store[2], store[3]);
}

void update(ll* arg, vector<pair<ll, ll>>& tree, int start, int end, int treeNode, ll idx, ll val){
    
    if(start==end){
        arg[idx] = val;
        tree[treeNode] = make_pair(val, -1);
        return;
    }
    
    int mid = start + (end-start)/2;
    
    if(idx>mid){
        update(arg, tree, mid+1, end, 2*treeNode+1, idx, val);
    }else{
        update(arg, tree, start, mid, 2*treeNode, idx, val);
    }
    
    ll store[4] = {0};
    store[0] = tree[2*treeNode].first;
    store[1] = tree[2*treeNode].second;
    store[2] = tree[2*treeNode+1].first;
    store[3] = tree[2*treeNode+1].second;
    
    sort(store, store+4);
    
    tree[treeNode] = make_pair(store[2], store[3]);
    
}

pair<ll, ll> queryMaxPairSum(ll* arg, vector<pair<ll, ll>>& tree, int start, int end, int treeNode, int L, int R){
    
    if(start>R || end<L){
        return make_pair(-1, -1);
    }
    
    if(start>=L && end<=R){
        return tree[treeNode];
    }
    
    int mid = start + (end-start)/2;
    
    pair<ll, ll> ans1 = queryMaxPairSum(arg, tree, start, mid, 2*treeNode, L, R);
    pair<ll, ll> ans2 = queryMaxPairSum(arg, tree, mid+1, end, 2*treeNode+1, L, R);
    
    ll store[4] = {0};
    store[0] = ans1.first;
    store[1] = ans1.second;
    store[2] = ans2.first;
    store[3] = ans2.second;
    
    sort(store, store+4);
    
    return make_pair(store[2], store[3]);
}

void maximumSumPair(){
    
    int n = 0;
    cin>>n;
    
    ll arg[n];
    for(int i=0; i<n; i++){
        cin>>arg[i];
    }
    
    vector<pair<ll, ll>> tree(4*n);
    build(arg, tree, 0, n-1, 1);
    
    int q=0;
    cin>>q;
    
    vector<char> queries(q);
    vector<pair<ll, ll>> val(q);
    
    for(int i=0; i<q; i++){
        cin>>queries[i];
        cin>>val[i].first>>val[i].second;
        
        if(queries[i]=='Q'){
            pair<ll, ll> ans = queryMaxPairSum(arg, tree, 0, n-1, 1, val[i].first-1, val[i].second-1);
            cout<<ans.first+ans.second<<"\n";
        }else{
            update(arg, tree, 0, n-1, 1, val[i].first-1, val[i].second);
        }
    }
    
}

struct node{
    ll maxSum = 0;
    ll sum = 0;
    ll BPS = 0;
    ll BSS = 0;
};

void buildMaxSubArraySum(ll* arg, node* tree, int start, int end, int treeNode){
    
    if(start==end){
        tree[treeNode].maxSum=arg[start];
        tree[treeNode].BPS=arg[start];
        tree[treeNode].BSS=arg[start];
        tree[treeNode].sum=arg[start];
        return;
    }
    
    int mid = start + (end-start)/2;
    
    buildMaxSubArraySum(arg, tree, start, mid, 2*treeNode);
    buildMaxSubArraySum(arg, tree, mid+1, end, 2*treeNode+1);
    
    ll right = 2*treeNode+1;
    ll left = 2*treeNode;
    
    tree[treeNode].sum = tree[left].sum + tree[right].sum;
    tree[treeNode].BPS = max(tree[left].BPS,tree[left].sum + tree[right].BPS);
    tree[treeNode].BSS = max(tree[right].BSS,tree[right].sum + tree[left].BSS);
        
    ll store[5] = {tree[left].maxSum, tree[right].maxSum, tree[left].sum + tree[right].BPS, tree[right].sum + tree[left].BSS, tree[left].BSS + tree[right].BPS};
    
    tree[treeNode].maxSum = *max_element(store, store+5);
    
}

void updateMaxSubArraySum(ll* arg, node* tree, int start, int end, int treeNode, ll idx, ll val){
    
    if(start==end){
        arg[idx] = val;
        tree[treeNode].maxSum=val;
        tree[treeNode].BPS=val;
        tree[treeNode].BSS=val;
        tree[treeNode].sum=val;
        return;
    }
    
    int mid = start + (end-start)/2;
    int right = 2*treeNode+1;
    int left = 2*treeNode;
    
    if(idx>mid){
        updateMaxSubArraySum(arg, tree, mid+1, end, right, idx, val);
    }else{
        updateMaxSubArraySum(arg, tree, start, mid, left, idx, val);
    }
    
    tree[treeNode].sum = tree[left].sum + tree[right].sum;
    tree[treeNode].BPS = max(tree[left].BPS,tree[left].sum + tree[right].BPS);
    tree[treeNode].BSS = max(tree[right].BSS,tree[right].sum + tree[left].BSS);
        
    ll store[5] = {tree[left].maxSum, tree[right].maxSum, tree[left].sum + tree[right].BPS, tree[right].sum + tree[left].BSS, tree[left].BSS + tree[right].BPS};
    
    tree[treeNode].maxSum = *max_element(store, store+5);
    
}

node queryMaxSubArraySum(node* tree, int start, int end, int treeNode, ll L, ll R){
    
    if(start>R || end<L){
        node temp;
        temp.sum = INT_MIN;
        temp.maxSum = INT_MIN;
        temp.BSS = INT_MIN;
        temp.BPS = INT_MIN;
        return temp;
    }
    
    if(start>=L && end<=R){
        return tree[treeNode];
    }
    
    int mid = start + (end-start)/2;
    int right = 2*treeNode+1;
    int left = 2*treeNode;
    
    node ans1 = queryMaxSubArraySum(tree,start,mid,left,L,R);
    node ans2 = queryMaxSubArraySum(tree,mid+1,end,right,L,R);
    node temp;
    
    temp.sum = ans1.sum + ans2.sum;
    temp.BPS = max(ans1.BPS,ans1.sum + ans2.BPS);
    temp.BSS = max(ans2.BSS,ans2.sum + ans1.BSS);
        
    ll store[5] = {ans1.maxSum, ans2.maxSum, ans1.sum + ans2.BPS, ans2.sum + ans1.BSS, ans1.BSS + ans2.BPS};
    
    temp.maxSum = *max_element(store, store+5);
    
    return temp;
}

void maximumSubArraySum(){
    
    int n = 0;
    cin>>n;
    
    ll arg[n];
    for(int i=0; i<n; i++){
        cin>>arg[i];
    }
    
    node tree[4*n];
    buildMaxSubArraySum(arg, tree, 0, n-1, 1);
    
    int q = 0;
    cin>>q;
    
    for(int i=0; i<q; i++){
        ll L=0, R=0;
        cin>>L>>R;
        
        node temp = queryMaxSubArraySum(tree, 0, n-1, 1, L-1, R-1);
        cout<<temp.maxSum<<"\n";
    }
    
}

void buildTreeLazy(int* arg, int* tree, int start, int end, int treeNode){
    
    if(start==end){
        tree[treeNode] = arg[start];
        return;
    }
    
    int mid = start + (end-start)/2;
    
    buildTreeLazy(arg, tree, start, mid, 2*treeNode);
    buildTreeLazy(arg, tree, mid+1, end, 2*treeNode+1);
    
    tree[treeNode] = min(tree[2*treeNode],tree[2*treeNode+1]);
}

void updateSegmentTreeLazy(int* tree, int* lazy, int low, int high, int startR, int endR, int currPos, int inc){
    
    // currpos is same as treeNode, inc=increment, [startR,endR] the range where increment should take place
    // low is equivalent to start and high is equivalent to end
    
    if(low > high){
        return;
    }
    
    if(lazy[currPos]!=0){
        tree[currPos]+=lazy[currPos];
        
        if(low!=high){
            lazy[2*currPos]+=lazy[currPos];
            lazy[2*currPos+1]+=lazy[currPos];
        }
        
        lazy[currPos] = 0;
    }
    
    // No overlap
    if(startR>high || endR<low){
        return;
    }
    
    if(startR<=low && high<=endR){
        tree[currPos]+=inc;
        if(low!=high){
            lazy[2*currPos]+=inc;
            lazy[2*currPos+1]+=inc;
        }
        return;
    }
    
    int mid = low + (high-low)/2;
    updateSegmentTreeLazy(tree, lazy, low, mid, startR, endR, 2*currPos, inc);
    updateSegmentTreeLazy(tree, lazy, mid+1, high, startR, endR, 2*currPos+1, inc);
    
    tree[currPos] = min(tree[2*currPos],tree[2*currPos+1]);
    
}

void lazyPropagationImplementation(){
    
    int arr[] = {1,3,-2,4};
    int tree[12] = {0};
    buildTreeLazy(arr, tree, 0, 3, 1);
    int lazy[12] = {0};
    
    updateSegmentTreeLazy(tree, lazy, 0, 3, 0, 3, 1, 3);
    updateSegmentTreeLazy(tree, lazy, 0, 3, 0, 1, 1, 2);
    
    cout<<"segment tree\n";
    for(int i=0; i<12; i++){
        cout<<tree[i]<<" ";
    }
    cout<<"\n";
    
    cout<<"lazy tree\n";
    for(int i=0; i<12; i++){
        cout<<lazy[i]<<" ";
    }
    cout<<"\n";
}

// the size of the segment tree we should take is 4n

struct sparta{
    ll strength = 0;
    ll cowardice = 0;
    ll index = 0;
};

void buildSparta(sparta* arg, sparta* tree, int start, int end, int treeNode){
    
    if(start==end){
        tree[treeNode] = arg[start];
        return;
    }
    
    int mid = start + ((end-start)>>1);
    int left = 2*treeNode;
    int right = 2*treeNode+1;
    
    buildSparta(arg, tree, start, mid, left);
    buildSparta(arg, tree, mid+1, end, right);
    
    if(tree[left].strength>tree[right].strength){
        tree[treeNode] = tree[left];
    }else if(tree[right].strength>tree[left].strength){
        tree[treeNode] = tree[right];
    }else{
        if(tree[left].cowardice<tree[right].cowardice){
            tree[treeNode] = tree[left];
        }else if(tree[right].cowardice<tree[left].cowardice){
            tree[treeNode] = tree[right];
        }else{
            if(tree[left].index<tree[right].index){
                tree[treeNode] = tree[left];
            }else{
                tree[treeNode] = tree[right];
            }
        }
    }
    
}

sparta querySparta(sparta* tree, int start, int end, int treeNode, int L, int R){
    
    if(start>R || end<L){
        sparta temp;
        temp.strength = INT_MIN;
        temp.cowardice = INT_MAX;
        temp.index = INT_MAX;
        return temp;
    }
    
    if(start>=L && end<=R){
        return tree[treeNode];
    }
    
    int mid = start + ((end-start)>>1);
    int left = 2*treeNode;
    int right = 2*treeNode+1;

    sparta ans1 = querySparta(tree, start, mid, left, L, R);
    sparta ans2 = querySparta(tree, mid+1, end, right, L, R);
    sparta result;
    
    if(ans1.strength>ans2.strength){
        result = ans1;
    }else if(ans2.strength>ans1.strength){
        result = ans2;
    }else{
        if(ans1.cowardice<ans2.cowardice){
            result = ans1;
        }else if(ans2.cowardice<ans1.cowardice){
            result = ans2;
        }else{
            if(ans1.index<ans2.index){
                result = ans1;
            }else{
                result = ans2;
            }
        }
    }
    
    return result;
    
}

int main(int argc, const char * argv[]) {
    
    int n = 0;
    cin>>n;
    
    sparta s[n+1];
    for(int i=1; i<=n; i++){
        cin>>s[i].strength;
        s[i].index = i;
    }
    
    for(int i=1; i<=n; i++){
        cin>>s[i].cowardice;
    }
    
    sparta tree[4*n];
    buildSparta(s, tree, 1, n, 1);
    
    int q = 0;
    cin>>q;
    
    for(int i=0; i<q; i++){
        int L=0,R=0;
        cin>>L>>R;
        
        sparta ans = querySparta(tree, 1, n, 1, L, R);
        cout<<ans.index<<"\n";
    }
    
    return 0;
}
