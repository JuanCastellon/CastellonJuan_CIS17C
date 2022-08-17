/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.h
 * Author: Juan
 *
 * Created on September 25, 2018, 11:37 PM
 */

#ifndef TABLE_H
#define TABLE_H

#include "RowAray.h"

template<class T>
class Table{
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns;
    public:
        Table(unsigned int,unsigned int);
        Table(const Table<T> &);
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        T getData(int,int)const;
        void setData(int,int,T);
        Table<T> operator+(const Table<T> &);
};

template<class T>
Table<T>::Table(unsigned int x, unsigned int y){
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
    
    columns=new RowAray<T>*[szRow];
    
    for(int i=0;i<szRow;i++){
        columns[i]=new RowAray<T>(szCol);
    }
}

template<class T>
Table<T>::Table(const Table<T> &a){
    szRow=a.getSzRow();
    szCol=a.getSzCol();
    
    columns=new RowAray<T>*[szRow];
    
    for(int i=0;i<szRow;i++){
        columns[i]=new RowAray<T>(szCol);
    }
    
    for(int i=0;i<szRow;i++){
        for(int j=0;j<szCol;j++){
            columns[i]->setData(j,a.getData(i,j));
        }
    }
    
}

template<class T>
Table<T>::~Table(){
    for(int i=0;i<szRow;i++){
        delete columns[i];
    }
    
    delete [] columns;
}

template<class T>
T Table<T>::getData(int x,int y)const{
    return columns[x]->getData(y);
}

template<class T>
void Table<T>::setData(int x, int y, T z){
    columns[x]->setData(y,z);
}
template<class T>
Table<T> Table<T>::operator +(const Table<T>&a){
    Table temp(szRow,szCol);
    
    for(int i=0;i<szRow;i++){
        for(int j=0;j<szCol;j++){
            temp.setData(i,j,a.getData(i,j)+getData(i,j));
        }
    }
    
    return temp;
}

#endif /* TABLE_H */

