/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.cpp
 * Author: Juan
 * 
 * Created on December 6, 2018, 6:38 PM
 */

#include "Node.h"

//Default Constructor
Node::Node(){
    
}

//Custom Constructor
Node::Node(int d) {
    data=d;
    left=right=nullptr;
}


