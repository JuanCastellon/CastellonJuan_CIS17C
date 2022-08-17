/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Clerk.cpp
 * Author: Juan
 * 
 * Created on December 14, 2018, 7:46 PM
 */

#include "Clerk.h"

Clerk::Clerk() {
    busy=false;
    numServ=0;
    timServ=0;
}
Clerk::Clerk(int i){
    Clerk();
    clerkTime=i;
}
void Clerk::service(queue<int> clients){
    busy=true;
    clients.pop();
    busy=false;
}


