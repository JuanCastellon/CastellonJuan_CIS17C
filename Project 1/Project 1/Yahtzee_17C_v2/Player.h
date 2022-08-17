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

#include <iostream> //cin,cout
#include <cstdlib>  //Random Function
#include <ctime>    //Time function
#include <vector>   //Vector from STL
#include <utility>  //Swapping function from STL
#include <algorithm>//Algorithm from STL
#include <array>    //Array from STL
#include <stack>    //Stack from STL
#include <map>      //Map from STL

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    //Default Constructor inline
    Player(){
        index=0;
        name="";
        score=0;
        yah=0;
        rolls=0;
        chance=0;
    }
    //Constructor
    Player(string);
    //Destructor
    ~Player();
    
    //Setter Functions
    void setName(string);
    void setScre(int);
    void setIndx(int);
    void setYaht(int);
    void setRoll(int);
    
    //Getter Functions
    string getName();
    int getScre();
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
    
    
private:
    int index;  //For determining who goes first
    string name;//Name of Player
    int score;//Score of Player
    
    //Game-keeping variables
    int yah;    //Yahtzee counter for each player
    int rolls;  //Amount of rolls the player has left when rerolling
    int chance; //Chance counter for each player
};

#endif /* PLAYER_H */

