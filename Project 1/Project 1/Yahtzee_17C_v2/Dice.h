/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dice.h
 * Author: Juan
 *
 * Created on October 30, 2018, 12:56 PM
 */

#ifndef DICE_H
#define DICE_H

#include "Player.h"

class Dice {
public:
    //Default Constructor
    Dice();
    //Destructor
    ~Dice();
    
    //Setter Functions for rerolls primarily
    void setD1();
    void setD2();
    void setD3();
    void setD4();
    void setD5();
    
    //Getter Functions
    int getD1();
    int getD2();
    int getD3();
    int getD4();
    int getD5();
    
    //Game Functions
    void roll();
    void display();
    int sum();
    
private:
    int d1;
    int d2;
    int d3;
    int d4;
    int d5;
};

#endif /* DICE_H */

