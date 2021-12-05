//
//  main.cpp
//  Binary Search Tree
//
//  Created by kalash kala on 30/06/21.
//

#include <iostream>
#include "BST.h"

using namespace std;

int main(int argc, const char * argv[]) {

    BST<int> * tree = new BST<int>;
    
    tree->createTree();
    tree->inorderTraversal(tree->root);
    cout<<"\n";
    
    tree->searchBST(tree->root, 25);
    tree->searchBST(tree->root, 259);
    
    tree->searchBST_iterative(50);
    tree->searchBST_iterative(60);
    
    tree->insert(60);
    tree->insert(tree->root,5);
    
    tree->inorderTraversal(tree->root);
    cout<<"\n";
    
    tree->del(tree->root, 42);
    
    tree->inorderTraversal(tree->root);
    cout<<"\n";
    
    
    BST<int> *tree1 = new BST<int>;
    
    int arg[]={30,20,10,15,25,40,50,45};
    tree1->createTreePreorder(arg, 8);
    tree1->inorderTraversal(tree1->root);
    cout<<"\n";

    return 0;
}
