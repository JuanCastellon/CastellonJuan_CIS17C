/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <cmath>

using namespace std;

//User Libraries Here


//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
float g(float x) {
    //Checking to see if the absolute value 
   if(fabs(x)<1e-6) {
      return x-(pow(x,3)/6.0);
   }else{
      //Using the base condition to get -1<=x<=1
      float temp = g(x/2);
      return (2*temp)/(1+(temp*temp));
   }
}

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float x;
    cout<<"Input a number : "<<endl;
    cin>>x;
    cout<<g(x)<<endl;
    return 0;
    
}