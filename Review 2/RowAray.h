/* 
 * File:   RowAray.h
 * Author: Dr. Mark E. Lehr
 * Created on August 25th, 2018, 8:54 AM
 * Specification for the RowAray
 */

#ifndef ROWARAY_H
#define	ROWARAY_H

#include "AbsRow.h"
#include <cstdlib>

class RowAray:public AbsRow{
    public:
        RowAray(unsigned int);
        virtual ~RowAray();
        int getSize()const{return size;}
        int getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,int);
};

#endif	/* ROWARAY_H */