//
//  treesClass.h
//  Trees
//
//  Created by kalash kala on 11/06/21.
//

#ifndef treesClass_h
#define treesClass_h

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template<class T>

class NodeTree{
public:
    NodeTree * Lchild;
    T data;
    NodeTree * Rchild;
    
    NodeTree(){
        Lchild=NULL;
        Rchild=NULL;
    };
    
    NodeTree(T val){
        Lchild=NULL;
        this->data=val;
        Rchild=NULL;
    }
};

template<class T>

class Tree{
public:
    NodeTree<T> * root= new NodeTree<T>;
    
    void createTree();
    void preorder(NodeTree<T> * &tree);
    void postorder(NodeTree<T> * &tree);
    void inorder(NodeTree<T> * &tree);
    int height(NodeTree<T> * &tree);
    void iterative_preorder();
    void iterative_postorder(); //important implementation
    void iterative_inorder();
    void levelOrder();
    int countNodes(NodeTree<T> * &tree);
    int count1Nodes(NodeTree<T> * &tree); // used XOR important
    int count0Nodes(NodeTree<T> * &tree);
    int count2Nodes(NodeTree<T> * &tree);
    int searchInorder(int arr[], int data, int start, int end);
    NodeTree<T>* createTreePreorderInorder(int preorder[], int inorder[], int start, int end);
    
};

template<class T>

void Tree<T>::createTree(){
    T rootData;
    queue<NodeTree<T> *>Q;
    
    NodeTree<T> * temp1, * temp2;
    
    cout<<"Enter the root data\n";
    cin>>rootData;
    
    root->data=rootData;
    root->Lchild=NULL;
    root->Rchild=NULL;
    
    Q.push(root);
    
    while(!Q.empty()){
        temp1=Q.front();
        Q.pop();
        
        T x;
        cout<<"Enter the data of the left child of "<<temp1->data<<" (if empty enter -1)\n";
        cin>>x;
        
        if(x!=-1){
            temp2 = new NodeTree<T>;
            temp2->data=x;
            temp2->Lchild = NULL;
            temp2->Rchild = NULL;
            
            temp1->Lchild=temp2;
            Q.push(temp2);
        }
        
        cout<<"Enter the data of the right child "<<temp1->data<<" (if empty enter -1)\n";
        cin>>x;
        
        if(x!=-1){
            temp2 = new NodeTree<T>;
            temp2->data=x;
            temp2->Lchild=NULL;
            temp2->Rchild=NULL;
            
            temp1->Rchild=temp2;
            Q.push(temp2);
        }
        
    }
}

template<class T>

void Tree<T>::preorder(NodeTree<T> *&tree){
    
    if(tree!=NULL){
        cout<<tree->data<<" ";
        preorder(tree->Lchild);
        preorder(tree->Rchild);
    }
}

template<class T>

void Tree<T>::postorder(NodeTree<T> *&tree){
    
    if(tree!=NULL){
        postorder(tree->Lchild);
        postorder(tree->Rchild);
        cout<<tree->data<<" ";
    }
}

template<class T>

void Tree<T>::inorder(NodeTree<T> *&tree){
    
    if(tree!=NULL){
        inorder(tree->Lchild);
        cout<<tree->data<<" ";
        inorder(tree->Rchild);
    }
}

template<class T>

int Tree<T>::height(NodeTree<T> * &tree){

    if(tree==NULL){
        return 0;
    }
    
    int L = height(tree->Lchild);
    int R = height(tree->Rchild);
    
    if(L>R){
        return L+1;
    }
    return R+1;
}

template<class T>

void Tree<T>::iterative_preorder(){
    
    if(root!=NULL){
        cout<<root->data<<" ";
        stack<NodeTree<T>*> st;
        
        if(root->Rchild!=NULL){
            st.push(root->Rchild);
        }
        if(root->Lchild!=NULL){
            st.push(root->Lchild);
        }
        
        while(!st.empty()){
            NodeTree<T>*temp = st.top();
            cout<<temp->data<<" ";
            st.pop();
            
            if(temp->Rchild!=NULL){
                st.push(temp->Rchild);
            }
            if(temp->Lchild!=NULL){
                st.push(temp->Lchild);
            }
        }
    }else{
        cout<<"Tree empty\n";
    }

}

template <class T>

void Tree<T>::iterative_inorder(){
    
    NodeTree<T>* temp = root;
    stack<NodeTree<T>*>st;
    
    while(temp!=NULL || !st.empty()){
        
        if(temp!=NULL){
            st.push(temp);
            temp=temp->Lchild;
            
        }else{
            temp=st.top();
            cout<<temp->data<<" ";
            st.pop();
            temp=temp->Rchild;
        }
    }

}

template<class T>

void Tree<T>::iterative_postorder(){ // important implementation
    
    NodeTree<T> * temp = root;
    stack<long int> st;
    long int t;
    
    while(temp!=NULL || !st.empty()){
        
        if(temp!=NULL){
            st.push((long int)temp);
            temp=temp->Lchild;
        }else{
            t = st.top();
            st.pop();
            if(t>0){
                st.push(-t);
                temp = ((NodeTree<T> *)t)->Rchild;
            }else{
                cout<<((NodeTree<T>*)(-1*t))->data<<" ";
                temp=NULL;
            }
        }
    }
    cout<<"\n";
}

template<class T>

void Tree<T>::levelOrder(){
    
    NodeTree<T>* temp = root;
    queue<NodeTree<T>*>Q;
    
    Q.push(root);
    cout<<root->data<<" ";
    
    while(!Q.empty()){
        
        temp = Q.front();
        Q.pop();
        
        if(temp->Lchild!=NULL){
            cout<<temp->Lchild->data<<" ";
            Q.push(temp->Lchild);
        }
        
        if(temp->Rchild!=NULL){
            cout<<temp->Rchild->data<<" ";
            Q.push(temp->Rchild);
        }
    }
    
    cout<<"\n";
    
}

template<class T>

int Tree<T>::countNodes(NodeTree<T> *&tree){
    
    if(tree!=NULL){
        
        int L = countNodes(tree->Lchild);
        int R = countNodes(tree->Rchild);
        
        return L+R+1;
    }
    
    return 0;
}

template<class T>

int Tree<T>::count1Nodes(NodeTree<T> *&tree){
    
    if(tree==NULL){
        return 0;
    }
    
    int L = count1Nodes(tree->Lchild);
    int R = count1Nodes(tree->Rchild);
    
    if(tree->Lchild==NULL ^ tree->Rchild==NULL){
        //cout<<tree->data<<"\n"; to check which nodes it is refering to
        return L+R+1;
    }
    
    return L+R;
}

template<class T>

int Tree<T>::count0Nodes(NodeTree<T> *&tree){
    
    if(tree==NULL){
        return 0;
    }
    
    int L = count0Nodes(tree->Lchild);
    int R = count0Nodes(tree->Rchild);
    
    if(tree->Rchild==NULL && tree->Lchild==NULL){
        //cout<<tree->data<<"\n"; to check which nodes it is refering to
        return L+R+1;
    }
    
    return L+R;
    
}

template<class T>

int Tree<T>::count2Nodes(NodeTree<T> *&tree){
    
    if(tree==NULL){
        return 0;
    }
    
    int L = count2Nodes(tree->Lchild);
    int R = count2Nodes(tree->Rchild);
    
    if(tree->Lchild!=NULL && tree->Rchild!=NULL){
        //cout<<tree->data<<"\n"; to check which nodes it is refering to 
        return L+R+1;
    }
    
    return L+R;
    
}

template<class T>

int Tree<T>::searchInorder(int *arr, int data, int start, int end){
    
    for(int i=start; i<=end; i++){
        if(arr[i]==data){
            return i;
        }
    }
    
    return -1;
}

template<class T>

NodeTree<T>* Tree<T>::createTreePreorderInorder(int *preorder, int *inorder, int start, int end){
    
    static int preIndex = 0;
    
    if(start>end){
        return NULL;
    }
    
    NodeTree<T>* temp = new NodeTree<T>(preorder[preIndex++]);
    
    int splitIndex = searchInorder(inorder, temp->data, start, end);
    
    temp->Lchild = createTreePreorderInorder(preorder, inorder, start, splitIndex-1);
    temp->Rchild = createTreePreorderInorder(preorder, inorder, splitIndex+1, end);
    
    return temp;
}

#endif /* treesClass_h */
