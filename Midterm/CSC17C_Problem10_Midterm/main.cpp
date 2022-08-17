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

//Function Prototypes Here
int power(int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    int x,exp,ans;
    cout<<"Enter a number and the exponent : "<<endl;
    cin>>x;
    cin>>exp;
    ans=power(x,exp);
    cout<<x<<"^"<<exp<<" = "<<ans<<endl;
    return 0;
}

int power(int x,int n){
    int tmp;
    if(n==0){
        //any number to the 0 power is 1
        return 1;
    }
    
    //Recursive call splitting the power in half
    tmp=power(x,n/2);
    
    //If else statement, checking if the exponent is even or odd
    if(n%2==0){
        //Even we just multiple temps together
        return tmp*tmp;
    }
    else{
        //Odd we multiply by the argument (x) to get the original
        return x*tmp*tmp;
    }
}