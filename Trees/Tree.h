/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.h
 * Author: Juan
 *
 * Created on December 6, 2018, 6:23 PM
 */

#ifndef TREE_H
#define TREE_H
#include "Node.h"

class Tree : public Node{
public:
    //Default constructor
    Tree();
    
    //Custom Constructor 
    Tree(int key);
    
    //
    
private:
    Node *root;//The root of the tree
};

#endif /* TREE_H */

