/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.cpp
 * Author: Juan
 * 
 * Created on September 18, 2018, 9:36 PM
 */

#include "Table.h"

//Constructor
Table::Table(unsigned int x,unsigned int y):AbsTabl(){
    if(x<1){
        szRow=2;
    }
    else{
        szRow=x;
    }
    if(y<1){
        szCol=2;
    }
    else{
        szCol=y;
    }
    
    columns=new RowAray*[szRow];
    
    for(int i=0;i<szRow;i++){
        columns[i]=new RowAray(szCol);
    }
    
}

//Copy Constructor
Table::Table(const Table &x){
    szRow=x.getSzRow();
    szCol=x.getSzCol();
    
    columns=new RowAray*[szRow];
    
    for(int i=0;i<szRow;i++){
        columns[i]=new RowAray(szCol);
    }
    
    for(int i=0;i<szRow;i++){
        for(int j=0;j<szCol;j++){
            columns[i]->setData(j,x.getData(i,j));
        }
    }
}

Table::~Table() {
    for(int i=0;i<szRow;i++){
        delete columns[i];
    }
    
    delete [] columns;
}

int Table::getData(int x, int y) const{
    return columns[x]->getData(y);
}

void Table::setData(int x, int y, int z){
    columns[x]->setData(y,z);
}

