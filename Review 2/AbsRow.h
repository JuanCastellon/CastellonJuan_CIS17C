/* 
 * Author: Dr. Mark E. Lehr
 * Created on August 25th, 2018, 8:54 AM
 * Specification for the Abstract Row Array Class
 */

#ifndef ABSROW_H
#define	ABSROW_H

class AbsRow{
    protected:
        int size;
        int *rowData;
    public:
        virtual int getSize()const = 0;
        virtual int getData(int)const = 0;
};

#endif	/* ABSROW_H */

