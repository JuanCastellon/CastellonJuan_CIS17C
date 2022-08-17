/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: Juan
 *
 * Created on December 6, 2018, 6:38 PM
 */

#ifndef NODE_H
#define NODE_H

class Node {
public:
    //Default Constructor
    Node();
    //Custom Constructor
    Node(int);
    
private:
    int data;   //Data in the node  
    Node *left; //Left node
    Node *right;//Right node
};

#endif /* NODE_H */

