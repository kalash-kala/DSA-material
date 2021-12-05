//
//  BST.h
//  Binary Search Tree
//
//  Created by kalash kala on 30/06/21.
//

#ifndef BST_h
#define BST_h

#include <iostream>
#include <queue>
#include <stack>


using namespace std;

template <class T>

class NodeTree{
    
public:
    NodeTree * Lchild;
    T data;
    NodeTree * Rchild;
};


template<class T>

class BST{

public:
    
    NodeTree<T> * root = new NodeTree<T>;    
    
    BST(){
        root->Lchild=NULL;
        root->Rchild=NULL;
    };
    
    void createTree();
    void createTreePreorder(T arg[], int n);
    void inorderTraversal(NodeTree<T>* node);
    int height(NodeTree<T>*node);
    void searchBST(NodeTree<T>* node,T key);
    int searchBST_iterative(T key);
    int insert(T key);
    NodeTree<T>* insert(NodeTree<T>* node,T key);// recursive version
    NodeTree<T>* inorderPredecessor(NodeTree<T>* node); // very important function
    NodeTree<T>* inorderSuccessor(NodeTree<T>* node); // very important function
    NodeTree<T>* del(NodeTree<T>* node,T key); // very important function
    
};

template <class T>

void BST<T>::createTree(){
    
    int rootData;
    cout<<"Enter the value of the root node \n";
    cin>>rootData;
    
    root->data=rootData;
    
    queue<NodeTree<T>*>Q;
    Q.push(root);
    
    NodeTree<T>*p,*q;
    
    while(!Q.empty()){
        
        p = Q.front();
        Q.pop();
        
        int x=0;
        
        cout<<"Enter the value of Lchild of "<<p->data<<" (if empty enter -1)\n";
        cin>>x;
        
        if(x!=-1){
            q = new NodeTree<T>;
            p->Lchild=q;
            q->data = x;
            q->Lchild=NULL;
            q->Rchild=NULL;
            
            Q.push(q);
        }
        
        cout<<"Enter the value of Rchild of "<<p->data<<" (if empty enter -1)\n";
        cin>>x;
        
        if(x!=-1){
            q = new NodeTree<T>;
            p->Rchild=q;
            q->data = x;
            q->Lchild=NULL;
            q->Rchild=NULL;
            
            Q.push(q);
        }
        
    }
    
}

template <class T>

int BST<T>::height(NodeTree<T> *node){
    
    if(node==NULL){
        return 0;
    }
    
    int L = height(node->Lchild);
    int R = height(node->Rchild);
    
    if(L>R){
        return L+1;
    }
    
    return R+1;
}

template <class T>

void BST<T>::inorderTraversal(NodeTree<T>* node){
    
    if(node){
        inorderTraversal(node->Lchild);
        cout<<node->data<<" ";
        inorderTraversal(node->Rchild);
    }
    
}

template <class T>

void BST<T>::searchBST(NodeTree<T>* node,T key){
    
    if(!node){
        cout<<"Element not present \n";
    }else if(node->data==key){
        cout<<"Element is present \n";
    }else if(node->data>key){
        searchBST(node->Lchild, key);
    }else{
        searchBST(node->Rchild, key);
    }
    
}

template <class T>

int BST<T>::searchBST_iterative(T key){
    
    NodeTree<T>* temp = root;
    
    while(temp){
        
        if(temp->data==key){
            cout<<"Element is present \n";
            return 1;
        }else if(temp->data>key){
            temp=temp->Lchild;
        }else{
            temp=temp->Rchild;
        }
    }
    
    cout<<"Element not present\n";
    return 0;
}

template <class T>

int BST<T>::insert(T key){

    NodeTree<T>* temp = root;
    NodeTree<T>* prev=NULL, *New=NULL;
    
    while(temp){
        
        prev = temp;
        if(temp->data==key){
            cout<<"Element is present \n";
            return 1;
        }else if(temp->data>key){
            temp=temp->Lchild;
        }else{
            temp=temp->Rchild;
        }
    }
    
    New = new NodeTree<T>;
    New->data=key;
    New->Lchild=New->Rchild=NULL;
    
    if(key>prev->data){
        prev->Rchild=New;
    }else{
        prev->Lchild=New;
    }
    
    return 0;
}

template <class T>

NodeTree<T>* BST<T>::insert(NodeTree<T> *node, T key){
    
    if(!node){
        NodeTree<T>* temp = new NodeTree<T>;
        temp->data=key;
        temp->Lchild=temp->Rchild=NULL;
        return temp;
    }
    if(node->data>key){
        node->Lchild=insert(node->Lchild, key);
    }else if(node->data<key){
        node->Rchild=insert(node->Rchild, key);
    }
    
    return node;
}

template <class T>

NodeTree<T>* BST<T>::inorderPredecessor(NodeTree<T> *node){
    
    while(node!=NULL && node->Rchild!=NULL){
        node = node->Rchild;
    }
    
    return node;
}

template<class T>

NodeTree<T>* BST<T>::inorderSuccessor(NodeTree<T> *node){
    
    while(node!=NULL && node->Lchild!=NULL){
        node = node->Lchild;
    }
    
    return node;
}

template<class T>

NodeTree<T>* BST<T>::del(NodeTree<T> *node, T key){ // important concept wise
    
    NodeTree<T>* temp;
    
    if(node==NULL){
        return NULL;  // if the element doesnt exist
    }
    
    if(node->Lchild==NULL && node->Rchild==NULL){
        if(node==root){
            root = NULL; // if there is only one element
        }
        
        delete node;
        return NULL; // to return the inorder predecessor or successor
    }
    
    // literally searching in binary tree
    if(node->data==key){
            
        if(height(node->Lchild)>height(node->Rchild)){
            temp = inorderPredecessor(node->Lchild);
            node->data = temp->data;
            node->Lchild = del(node->Lchild,temp->data);
        }else{
            temp = inorderSuccessor(node->Rchild);
            node->data = temp->data;
            node->Rchild = del(node->Rchild, temp->data);
        }
            
    }else if(node->data>key){
        node->Lchild=del(node->Lchild, key);
    }else{
        node->Rchild=del(node->Rchild, key);
    }
    
    
    return node;
}

template<class T>

void BST<T>::createTreePreorder(T arg[], int n){
    
    stack<NodeTree<T>*>st;
    NodeTree<T> *node;
    NodeTree<T> *cur = root;
    
    int i = 0;
    
    root->data = arg[i++];
    root->Lchild = NULL;
    root->Rchild = NULL;
    
    while(i<n){
        if(arg[i]<cur->data){
            
            node = new NodeTree<T>;
            node->data = arg[i++];
            node->Lchild = NULL;
            node->Rchild = NULL;
            
            cur->Lchild = node;
            st.push(cur);
            
            cur = node;
        }else{
            
            int check = st.empty() ? INT_MAX : st.top()->data;// nice way of using ternary operator
            
            if(arg[i]>cur->data && arg[i] < check){
                
                node = new NodeTree<T>;
                node->data = arg[i++];
                node->Lchild = NULL;
                node->Rchild = NULL;
                
                cur->Rchild = node;
                cur = node;
                
            }else{
                cur = st.top();
                st.pop();
            }
        }
    }
    
}

#endif /* BST_h */
