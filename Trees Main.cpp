//
//  main.cpp
//  Trees
//
//  Created by kalash kala on 03/06/21.
//

#include <iostream>
#include <queue>
#include "treesClass.h"

using namespace std;

/*
 we will be using queue from stl library
 */

struct treeNode{
    treeNode * Lchild;
    int data;
    treeNode * Rchild;
};


void createTree(treeNode * &root){
    
    int rootData = 0;
    queue<treeNode *> Q;
    
    treeNode * temp1 = NULL, * temp2 = NULL;
    root = new treeNode;
    
    cout<<"Enter root data\n";
    cin>>rootData;
    root->data=rootData;
    root->Lchild=NULL;
    root->Rchild=NULL;
    
    Q.push(root);
    
    while(!Q.empty()){
        temp1 = Q.front();
        Q.pop();
        
        int x=0;
        cout<<"Enter the value of left child :\n (if empty enter -1)\n";
        cin>>x;
        
        if(x!=-1){
            temp2 = new treeNode;
            
            temp2->data=x;
            temp2->Lchild=NULL;
            temp2->Rchild=NULL;
            
            temp1->Lchild=temp2;
            Q.push(temp1->Lchild);
        }
        
        cout<<"Enter the value of right child :\n (if empty enter -1)\n";
        cin>>x;
        
        if(x!=-1){
            temp2 = new treeNode;
            
            temp2->data=x;
            temp2->Lchild=NULL;
            temp2->Rchild=NULL;
            
            temp1->Rchild=temp2;
            Q.push(temp1->Rchild);
        }
        
    }
}

void preorder(treeNode * &temp){
    
    if(temp!=NULL){
        cout<<temp->data<<" ";
        preorder(temp->Lchild);
        preorder(temp->Rchild);
    }
    
}

int main(int argc, const char * argv[]) {
    /*
     treeNode * tree;
     createTree(tree);
     preorder(tree);
     cout<<"\n";
     */
    
    Tree<int> *trees = new Tree<int>;
    trees->createTree();
    
    cout<<"preorder traversal (recursive) : ";
    trees->preorder(trees->root);
    cout<<"\npreorder traversal (iterative) : ";
    trees->iterative_preorder();
    cout<<"\n";
    
    cout<<"postorder traversal (recursive) : ";
    trees->postorder(trees->root);
    cout<<"\npostorder traversal (iterative) : ";
    trees->iterative_postorder();
    
    cout<<"inorder traversal (recursive) : ";
    trees->inorder(trees->root);
    cout<<"\ninorder traversal (iterative) : ";
    trees->iterative_inorder();
    cout<<"\n";
    
    cout<<"levelorder traversal (Iterative) : ";
    trees->levelOrder();
    
    cout<<"height of the tree : "<<trees->height(trees->root)<<"\n";
    cout<<"number of nodes : "<<trees->countNodes(trees->root)<<"\n";
    cout<<"number of 1º nodes : "<<trees->count1Nodes(trees->root)<<"\n";
    cout<<"number of 0º nodes : "<<trees->count0Nodes(trees->root)<<"\n";
    cout<<"number of 2º nodes : "<<trees->count2Nodes(trees->root)<<"\n";
    
    
    Tree<int> * trees1 = new Tree<int>;
    
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    
    trees1->root = trees1->createTreePreorderInorder(preorder, inorder, 0, 8);
    
    cout<<"Postorder traversal of createTreePreorderInorder function :\n";
    trees1->postorder(trees1->root);
    cout<<"\n";
    
    return 0;
}
