/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PlusTab.cpp
 * Author: Juan
 * 
 * Created on September 18, 2018, 9:32 PM
 */

#include "PlusTab.h"

PlusTab PlusTab::operator +(const PlusTab &x){
    PlusTab temp(szRow,szCol);
    
    for(int i=0;i<szRow;i++){
        for(int j=0;j<szCol;j++){
            temp.setData(i,j,x.getData(i,j)+getData(i,j));
        }
    }
    
    return temp;
    
}
