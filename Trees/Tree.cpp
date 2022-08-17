/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.cpp
 * Author: Juan
 * 
 * Created on December 6, 2018, 6:23 PM
 */

#include "Tree.h"

Tree::Tree(){
    root=nullptr; 
}

Tree::Tree(int k){
    root=new Node(k);
}

