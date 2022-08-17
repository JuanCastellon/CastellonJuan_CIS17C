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
#include "Clerk.h"

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    queue<int> clients;  //Clients to pull off the queue
    vector<Clerk> clerks;//Vector of clerks
    int runTime;         //How long the program will run for
    int wait=0;          //Wait time
    int totCust=0;       //Total customers in line
    bool waiting=true;   //Test if customers are waiting
    
    //Initialize Variables
    cout<<"How many 'hours' do you want to run the program for? : ";
    cin>>runTime;
    
    runTime*=60*60;
    
    clerks.push_back(Clerk(60)); //Fast clerk in the vector
    clerks.push_back(Clerk(120));//Medium clerk in the vector
    clerks.push_back(Clerk(80)); //Slow clerk in the vector
    
    //This is the loop that simulates the time, increments every second
    for(int time=0;time<=runTime;time++){
        bool free=false;
        
        //A check to see if the clerks are done servicing their clients
        for(int i=0;i<clerks.size();i++){
            int delta=clerks[i].getTime();//Getting time clerk services for
            
            //Checking if the current clerk is busy
            if(clerks[i].getBusy()){
                if(clerks[i].getTSev()+delta==time){
                    clerks[i].setBusy(0);
                    clerks[i].setTSer(0);
                    clerks[i].setNSer(1);
                    free=true;
                }
            }
            //Adds a customer every 4 minutes (240 seconds) 
            if(time%240==0){
                clients.push(1);
                totCust++;
            }
            //Now we check to see if there are customers to service
            waiting=true;
            if(clients.size()>0){
                //Check to see if the clerks are free
                for(int i=0;i<clerks.size();i++){
                    //The check to see if the clerk is busy & and client in line
                    if(!(clerks[i].getBusy())&&clients.size()){
                        waiting=false;
                        clerks[i].setBusy(1);
                        clerks[i].setTSer(time);
                        clients.pop();
                    }
                }
                if(waiting){
                    wait+=(clients.size());
                }
            }
        }
        //If there are more than 5 clients and no clerks 
        if(clients.size()>5&&!free){
            clerks.push_back(Clerk(60));
        }
        if(clients.size()==0&&clerks.size()>3){
            clerks.pop_back();
        }
    }
    
    
    //Display Results
    cout<<"Total customers   : "<<totCust<<endl;
    cout<<"Wait time         : "<<wait<<" sec"<<endl;
    cout<<"Average Wait Time : "<<(wait/60.0f)*totCust<<" minutes"<<endl;
    
    //Exit
    return 0;
}
