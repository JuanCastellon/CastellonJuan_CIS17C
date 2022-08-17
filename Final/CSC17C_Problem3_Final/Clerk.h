/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clerk.h
 * Author: Juan
 *
 * Created on December 14, 2018, 7:46 PM
 */

#ifndef CLERK_H
#define CLERK_H
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Clerk {
public:
    //Default constructor
    Clerk();
    
    //Custom constructor
    Clerk(int);
    
    //The servicing function maybe
    void service(queue<int>);
    
    //Setter
    void setBusy(bool b){busy=b;}
    void setTime(int t){clerkTime=t;}
    void setNSer(int n){numServ+=n;}
    void setTSer(int t){timServ=t;}
    //Getter for Busy
    bool getBusy(){return busy;}
    int getTime(){return clerkTime;}
    int getNSer(){return numServ;}
    int getTSev(){return timServ;}
    
private:
    bool busy;
    int numServ;  //Number of served customers
    int timServ;  //Total time served
    int clerkTime;//How long the clerk will serve a customer for

};

#endif /* CLERK_H */

