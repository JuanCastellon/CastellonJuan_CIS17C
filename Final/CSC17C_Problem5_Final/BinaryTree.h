/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryTree.h
 * Author: Juan
 *
 * Created on December 15, 2018, 5:24 PM
 */

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <cstdlib>
#include <iostream>
#include "BinaryNode.h"

using namespace std;

template <class T>
class BinaryTree {
private:
	int size;
	BinaryNode<T> *root;
	void rInOrder(BinaryNode<T> *node) {
            if(node){
                rInOrder(node->getLeft());
                cout<<node->getData()<<", ";
                rInOrder(node->getRight());
            }
	}
	void rPostOrder(BinaryNode<T> *node) {
            if (node){
                rPostOrder(node->getLeft());
                rPostOrder(node->getRight());
                cout<<node->getData()<<", ";
            }
	}
	void rPreOrder(BinaryNode<T> *node) {
            if (node){
                cout<<node->getData()<<", ";
                rPreOrder(node->getLeft());
                rPreOrder(node->getRight());
            }
	}
	void insertNode(T data, BinaryNode<T> *node) {
            if (data <= node->getData()) {
                if(node->getLeft()){
                    insertNode(data, node->getLeft());
                }
                else {
                    cout << node->getData() << " - L,  ";
                    if (++size % 10 == 0)cout << endl;
                    BinaryNode<T> *tempNode = new BinaryNode<T>(data);
                    node->setLeft(tempNode);
                }
            }
            else{
                if(node->getRight()){
                    insertNode(data, node->getRight());
                }
                else{
                    BinaryNode<T> *tempNode = new BinaryNode<T>(data);
                    cout<<node->getData()<<" - R,  ";
                    if(++size%10==0){cout<<endl;}
                    node->setRight(tempNode);
                }
            }

	}

	bool rFind(T data, BinaryNode<T> *node, int &count) {
            if(node){
                if(data<node->getData()){
                    return rFind(data, node->getLeft(), ++count);
                }
                else if(data > node->getData()){
                    return rFind(data, node->getRight(),++count);
                }
                else{
                    cout<<data<<" == "<<node->getData()<<endl;
                    return true;
                }
            }
            return false;
	}
public:
	BinaryTree(){
            root=NULL;
            size=0;
	}
	virtual ~BinaryTree() {
            delete root;
	}
	void inOrder() {
            rInOrder(root);
            cout<<endl;
	}
	void postOrder() {
            rPostOrder(root);
            cout<<endl;
	}
	void preOrder() {
            rPreOrder(root);
            cout<<endl;
	}

	void insert(T data){
            if(root){
                insertNode(data,root);
            }
            else {
                BinaryNode<T> *tempNode = new BinaryNode<T>(data);
                root = tempNode;
            }
	}

	void find(T data){
            int count = 0;
            if(rFind(data, root, count)){
                cout<<"found after "<<count<<"times"<<endl;
            }
            else{
                cout<<"searched "<<count<<" times without finding"<<endl;
            }
	}
};

#endif /* BINARYTREE_H */


