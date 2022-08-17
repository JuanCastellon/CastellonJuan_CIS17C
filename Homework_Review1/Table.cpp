/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.cpp
 * Author: Juan
 * 
 * Created on September 11, 2018, 9:52 PM
 */

#include "Table.h"

Table::Table(int a,int b) {
    records=new RowAray*[a];
    for(int i=0;i<a;i++){
        records[a]=new RowAray[b];
    }
}

Table::~Table() {
    delete [] records;
}

Table::getData(int a, int b){
    
}

