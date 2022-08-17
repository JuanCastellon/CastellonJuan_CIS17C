/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: Juan
 *
 * Created on October 30, 2018, 12:18 AM
 */

#include <iostream>//Input Output Stream
#include <cstdlib> //Random Function
#include <ctime>   //Time Function
#include <iomanip> //Formatting Library
#include <vector>  //Vector from STL
#include <array>   //Array from STL

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    //Default Constructor inline
    Player(){
        score=0;
        yah=0;
        chance=0;
        index=0;
    }
    //Constructor
    Player(string);
    //Destructor
    ~Player();
    
    //Setter Functions
    void setName(string);
    void setScre(float);
    void setIndx(int);
    void setYaht(int);
    void setRoll(int);
    
    
    //Getter Functions
    string getName();
    float getScre();
    int getYaht();
    int getIndx();
    int getChan();
    int getRoll();
    
    
    
    //Game functions
    void incYaht();//Increments the amount of yahtzees a player has gotten
    void incChan();//Increments the chance counter of the player
    void incTurn();//Decrements the turns
    
    
    
    //Overloaded Operator Functions
    Player operator ++ ();//Overloaded ++
    Player operator -- ();//Overloaded --
    
    
protected:
    int chance; //Chance counter for each player
    int index;  //For determining who goes first
    string name;//Name of Player
    float score;//Score of Player
    int yah;    //Yahtzee counter for each player
    int rolls;
};

#endif /* PLAYER_H */

