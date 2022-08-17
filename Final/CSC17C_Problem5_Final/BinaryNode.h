/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryNode.h
 * Author: Juan
 *
 * Created on December 15, 2018, 5:26 PM
 */

#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T>
class BinaryNode {
private:
	BinaryNode *left;
	BinaryNode *right;
	T data;
public:
	BinaryNode(T d) {
            data=d;
            left=NULL;
            right=NULL;
	}
        //Destructor
	virtual~BinaryNode(){
            delete left;
            delete right;
	}
	void setData(T d){
            data=d;
	}
	T getData()const{
            return data;
	}
	void setRight(BinaryNode* righ){
            right=righ;
	}

	BinaryNode* getRight()const{
            return right;
	}

	void setLeft(BinaryNode* lef) {
            left=lef;
	}

	BinaryNode* getLeft()const{
            return left;
	}
};

#endif /* BINARYNODE_H */

