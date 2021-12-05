//
//  main.cpp
//  AVL trees
//
//  Created by kalash kala on 14/07/21.
//

#include <iostream>
#include "AVL.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    // LL rotation demonstration
    
    AVL tll;
    
    tll.root = tll.Rinsert(tll.root, 30);
    tll.root = tll.Rinsert(tll.root, 20);
    tll.root = tll.Rinsert(tll.root, 10);
    
    tll.Inorder(tll.root);
    cout<<"\n";
    
    // RR rotation demonstration
    
    AVL trr;
    
    trr.root = trr.Rinsert(trr.root, 10);
    trr.root = trr.Rinsert(trr.root, 20);
    trr.root = trr.Rinsert(trr.root, 30);
    
    trr.Inorder(trr.root);
    cout<<"\n";
    
    // LR rotation demonstration
    
    AVL tlr;
    
    tlr.root = tlr.Rinsert(tlr.root, 30);
    tlr.root = tlr.Rinsert(tlr.root, 10);
    tlr.root = tlr.Rinsert(tlr.root, 20);
    
    tlr.Inorder(tlr.root);
    cout<<"\n";
    
    // RL rotation demonstration
    
    AVL trl;
    
    trl.root = trl.Rinsert(trl.root, 10);
    trl.root = trl.Rinsert(trl.root, 30);
    trl.root = trl.Rinsert(trl.root, 20);
    
    trl.Inorder(trl.root);
    cout<<"\n";
    
    AVL del;
    
    del.root = del.Rinsert(del.root, 10);
    del.root = del.Rinsert(del.root, 30);
    del.root = del.Rinsert(del.root, 20);
    del.root = del.Rinsert(del.root, 40);
    del.root = del.AVLdel(del.root, 40);
    
    del.Inorder(del.root);
    cout<<"\n";
    
    return 0;
}
