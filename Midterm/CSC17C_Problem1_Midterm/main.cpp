/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout

using namespace std;

//User Libraries Here


//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
int Oo,Oi,Oj,POs,Ow,tot;

//Function Prototypes Here
int *fillAry(int);
void prntAry(int *,int,int);
void linSrch(int *,int);
void mrkSort(int *,int);
void binSrch(int *,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables and initialize Here
    int size=150000000;
    int mod=10;
    int *array=fillAry(size);
    
    
    //Print the resulting array
    //prntAry(array,size,mod);
    
    
    //Sort the array
    //mrkSort(array,size)
    cout<<"Size of Array : "<<size<<endl;
    int begT=time(0);
    linSrch(array,size);
    int endT=time(0);
    
    cout<<"Linear Search Operations"<<endl;
    cout<<"Outer Operations    = "<<Oo<<endl;
    cout<<"i loop Operations   = "<<Oi<<endl;
    cout<<"If Operations       = "<<POs<<endl;
    tot=Oo+Oi+Oj+POs;
    cout<<"Total Number of ops for Linear Search = "<<tot<<endl;
    cout<<"Time taken : "<<endT-begT<<endl;
    
    Oo=Oi=POs=Ow=tot=0;
    
    int begT2=time(0);
    
    binSrch(array,0,size);
    
    int endT2=time(0);
    cout<<"Binary Search Operations"<<endl;
    cout<<"Outer Operations        = "<<Oo<<endl;
    cout<<"While loop Operations   = "<<Ow<<endl;
    cout<<"If Operations           = "<<POs<<endl;
    tot=Oo+Ow+POs;
    cout<<"Total Number of ops for Binary Search = "<<tot<<endl;
    cout<<"Time taken : "<<endT-begT<<endl;
    
    //Output Located Here
    //prntAry(array,size,mod);
    
    //Clean Memory
    delete []array;

    //Exit
    return 0;
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
void linSrch(int *a, int n){ 
    Oo+=1;
    for (int i = 0; i < n; i++){
        int x=rand()%100+1;//Random number to search
        if (a[i] == x){
            Oi+=6;
            POs+=1;//Due to the return
            //normally would return i here 
        }
        else{
            Oi+=7;
        }
        
        //normally would return -1 here 
    }
} 

void binSrch(int *arr, int l, int r) 
{   
    Oo+=1;
    while (l <= r) 
    {   int x=rand()%100+1;//Random number to search
        int m = l + (r-l)/2; 
  
        // Check if x is present at mid 
        if (arr[m] == x) 
            POs+=1;
            //return m; 
  
        // If x greater, ignore left half 
        if (arr[m] < x){ 
            POs+=2;
            l = m + 1; 
        }
  
        // If x is smaller, ignore right half 
        else{
            Ow+=2;
            r = m - 1; 
        }
        Ow+=8;
    } 
  
    // if we reach here, then element was 
    // not present 
    Oo+=1;
    //return -1;
  
    
} 

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand()%100+1;
    }
    return array;
}