/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <cstdlib> //Random Function
#include <ctime>   //Time function
#include <cmath>   //For trig functions
#include <stack>   //Stack container for the program
#include <iomanip> //Formatting

using namespace std;

//User Libraries Here


//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
float h(float,stack<float> &,stack<float> &);//Sinh Function
float g(float,stack<float> &,stack<float> &);//Cosh Function

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    stack<float> sinCall;
    stack<float> cosCall;
    int prevSinCall=0;
    int prevCosCall=0;
    
    //Testing out recursive trig functions
    float angDeg=45;
    float angRad=angDeg*atan(1)/45;
    cout<<"Angle = "<<angDeg<<" sinh = "<<sinh(angRad)<<
            " our h = "<<h(angRad,sinCall,cosCall)<<endl;
    cout<<"Angle = "<<angDeg<<" cosh = "<<cosh(angRad)<<
            " our g = "<<g(angRad,sinCall,cosCall)<<endl;
    
    //For loop for increasing the radians from -1 to 1
    for(float rad=-1;rad<1.1;rad+=.1){
        cout<<"============================="<<endl;
        //Setting up the table
        cout<<"Radians";
        cout<<setw(20)<<"Hyp Sin";
        cout<<setw(20)<<"h function";
        cout<<setw(20)<<"Hyp Cos";
        cout<<setw(20)<<"g function"<<endl;
        
        //Outputting the results
        cout<<setw(5)<<rad;
        cout<<setw(22)<<sinh(rad);
        cout<<setw(18)<<h(rad,sinCall,cosCall);
        cout<<setw(22)<<cosh(rad);
        cout<<setw(18)<<g(rad,sinCall,cosCall)<<endl;
        
        cout<<"Sin Stack Call = "<<cosCall.size()-prevCosCall<<endl;
        cout<<"Cos Stack Call = "<<sinCall.size()-prevSinCall<<endl;
        
        prevSinCall=sinCall.size();
        prevCosCall=cosCall.size();
    }
    
    
    
    //Process Input/Output
    
    
    //Display Results
    
    
    //Exit
    return 0;
}
//Sinh Function
float h(float angR,stack<float> &sinh,stack<float> &cosh){
    sinh.push(angR);
    float tol=1e-6;
    if(angR>-tol&&angR<tol)return angR+angR*angR*angR/6;
    return 2*h(angR/2,sinh,cosh)*g(angR/2,sinh,cosh);
}
//Cosh Function
float g(float angR,stack<float> &sinh,stack<float> &cosh){
    cosh.push(angR);
    float tol=1e-6;
    if(angR>-tol&&angR<tol)return 1+angR*angR/2;
    float b=h(angR/2,sinh,cosh);
    return 1+2*b*b;
}