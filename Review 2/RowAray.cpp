/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RowAray.cpp
 * Author: Juan
 * 
 * Created on September 18, 2018, 9:32 PM
 */

#include "RowAray.h"
    
RowAray::RowAray(unsigned int x):AbsRow() {
    if(x<1){
        size=2;
    }
    else{
        size=x;
    }
    
    rowData=new int[size];
    for(int i=0;i<size;i++){
        rowData[i]=rand()%90+10;
    }
    
    
    
}

RowAray::~RowAray() {
    delete [] rowData;
}

void RowAray::setData(int x, int y){
    rowData[x]=y;
}
