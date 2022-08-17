/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose: CSC17C Midterm Problem 9
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <cstdlib> //Random Function
#include <ctime>

using namespace std;

//User Libraries Here


//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int i;     //Counter variable
    int trial; //How many trials the program will test for
    int succ;  //Successfully within 30% margin
    float prob;//Calculated probability
    
    int rolls[5];//Array to keep track of the probabilities
    
    //Initialize Variables
    i=0;          //Setting the counter to 0
    trial=1000000;//One million trials
    succ=0;       //Setting the successes to 0
    
    //Process Input/Output
    while(i<=trial){
        //Rolling for probabilities
        rolls[1]=rand()%100+1;
        rolls[2]=rand()%100+1;
        rolls[3]=rand()%100+1;
        rolls[4]=rand()%100+1;
        rolls[5]=rand()%100+1;
        
        if(rolls[1]<=30&&rolls[2]<=30&&rolls[3]<=30&&rolls[4]<=30&&
           rolls[5]<=30){
            succ++;//If all are equal, increment successes
        }
        
        //Incrementing until 1 million is reached
        i++;
    }
    
    //Display Results
    prob=static_cast<float>(succ)/trial;//Successes divided by number of trials
    cout<<"Probability of falling in the filled area is : "<<prob<<"%"<<endl;
    
    //Exit
    return 0;
}