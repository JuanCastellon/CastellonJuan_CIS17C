/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RowAray.cpp
 * Author: Juan
 * 
 * Created on September 11, 2018, 9:51 PM
 */

#include "RowAray.h"

RowAray::RowAray(int a) {
    rowData=new int[a];
}

RowAray::~RowAray() {
    delete [] rowData;
}

