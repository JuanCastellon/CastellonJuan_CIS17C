/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include "dubLink.h"
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries Here


//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
void makeLst(int);
void prntLst(Link *, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Setting the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int listSze;
    int perLine=10;    
    
    //Initialize Variables
    cout<<"Input how you big you want the size of the list to be : ";
    cin>>listSze;
    
    //Process Input/Output
    makeLst(listSze);
    prntLst(head,perLine);
    
    //Display Results
    
    
    //Exit
    return 0;
}
void makeLst(int listSze){
    //Creating the first link and setting the data equal to a random number
    newNode=new Link;
    newNode->data=rand()%90+10;
    
    //Popping the node to the front of the list, making the previous one null
    newNode->prev=NULL;
    
    //Head and tail pointers now point to the middle node
    head=newNode;
    tail=newNode;
    
    //Creating the linked list itself
    for(int i=1;i<listSze;i++){
        newNode=new Link;
        newNode->data=rand()%90+10;
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
        
    }
    
    //Making sure the next node in the linked list doesn't point to anything
    tail->next=NULL;
    
}

void prntLst(Link *head,int perLine){
    int colCnt=0;
    Link *temp=head;
    
    while(temp!=NULL){
        cout<<temp->data<<" ";
        if(colCnt++%perLine==(perLine-1)){
            cout<<endl;
        }
        temp=temp->next;
    }
    
}