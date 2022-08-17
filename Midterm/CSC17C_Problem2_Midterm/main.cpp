/* 
 * File:   main.cpp
 * Author: 
 * Created on November 5, 2018, 3:55 PM
 * Purpose:
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Oo,Oi,Oj,POs,tot;
int Oo2,Oi2,Oj2,POs2,Oif,tot2;

int *fillAry(int);
void prntAry(int *,int,int);
void mrkSort(int *,int);
void bubSort(int *,int);
void selSort(int *,int);
/*
 * 
 */
int main(int argc, char** argv) {
//Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables and initialize Here
    int size=100000;
    int mod=10;
    int *array=fillAry(size);
    int *array2=fillAry(size);
    //Print the resulting array
    //prntAry(array,size,mod);

    int begT1=time(0);
    bubSort(array,size);
    int endT=time(0);
    cout<<"Size of array : "<<size<<endl;
    cout<<"Bubble Sort Operations:"<<endl;
    cout<<"Outer Operations    = "<<Oo<<endl;
    cout<<"i loop Operations   = "<<Oi<<endl;
    cout<<"j loop Operations   = "<<Oj<<endl;
    cout<<"Swap Operations     = "<<POs<<endl;
    tot=Oo+Oi+Oj+POs;
    cout<<"Total Number of ops for Bubble Sort = "<<tot<<endl;
    cout<<"Time taken : "<<endT-begT1<<endl;
    int begT2=time(0);
    selSort(array2,size);
    int endT2=time(0);
    cout<<"Selection Sort Operations:"<<endl;
    cout<<"Outer operations    = "<<Oo2<<endl;
    cout<<"i loop operations   = "<<Oi2<<endl;
    cout<<"j loop operations   = "<<Oj2<<endl;
    cout<<"If operations       = "<<Oif<<endl;
    cout<<"Swap Operations     = "<<POs2<<endl;
    tot2=Oo2+Oi2+Oj2+POs2+Oif;
    cout<<"Total Number of ops for Selection Sort = "<<tot2<<endl;
    cout<<"Time taken : "<<endT2-begT2<<endl;
    
    delete []array;
    delete []array2;
    return 0;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    cout << "Printing out the array\n";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand()%16000;
    }
    return array;
}

void mrkSort(int *a,int n){
    int nm1=n-1;
    Oo+=3;
    for(int i=0;i<nm1;i++){
        Oi+=4;
        for(int j=i+1;j<n;j++){
            Oj+=3;
            if(a[i]>a[j]){
                POs+=6;
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}

void bubSort(int *a,int n){
    int temp;
    Oo+=2;// for temp and i=0
    for(int i=0; i<(n-1);i++){
        Oi+=3; // i<(n-1),i++, and j=0
        for(int j=0;j<(n-i-1);j++){
            Oj+=5; //j<(n-i-1),j++, a[j]>a[j+1]
            if(a[j]>a[j+1]){
                POs+=3;
                temp= a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void selSort(int *a,int n){
    int i, j, min_idx,temp;
    Oo2+=5;//i, j, min_idx,temp,i=0;
    for (int i=0;i<(n-1);i++){ 
        Oi2+=6; //i<(n-1),i++, min_idx = i; ,j=(i+1)
        min_idx = i; 
        for (int j=(i+1);j<n;j++){
            Oj2+=3;
            if (a[j]<a[min_idx]){
                Oif+=1;
              min_idx = j; 
            } 
        } 
        POs2+=3;
        temp = a[i];
        a[i]=a[min_idx];
        a[min_idx]=temp;
    } 
}
