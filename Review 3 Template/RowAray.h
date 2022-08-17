/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RowAray.h
 * Author: Juan
 *
 * Created on September 25, 2018, 11:38 PM
 */

#ifndef ROWARAY_H
#define ROWARAY_H

template<class T>
class RowAray{
    protected:
        int size;
        T *rowData;
    public:
        RowAray(int);
        virtual ~RowAray();
        int getSize()const{return size;}
        T getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,T);
};
template<class T>
RowAray<T>::RowAray(int x){
    if(x<1){
        x=2;
    }
    else{
        size=x;
    }
    
    rowData=new T[size];
    
}
template<class T>
RowAray<T>::~RowAray(){
    delete [] rowData;
}

template<class T>
void RowAray<T>::setData(int x, T y){
    rowData[x]=y;
}


#endif /* ROWARAY_H */

