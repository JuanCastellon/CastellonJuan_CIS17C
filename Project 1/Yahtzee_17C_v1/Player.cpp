/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: Juan
 * 
 * Created on October 30, 2018, 12:18 AM
 */

#include "Player.h"
//Constructor
Player::Player(string s){
    name=s;
}

Player::~Player() {
    
}

//Setter Functions
void Player::setName(string s){
    name=s;
}
void Player::setScre(float s){
    score+=s;
}
void Player::setIndx(int i){
    index=i;
}
void Player::setYaht(int y){
    yah=y;
}
void Player::setRoll(int r){
    rolls=r;
}

//Getter Functions
string Player::getName(){
    return name;
}
float Player::getScre(){
    return score;
}
int Player::getIndx(){
    return index;
}
int Player::getChan(){
    return chance;
}
int Player::getYaht(){
    return yah;
}
int Player::getRoll(){
    return rolls;
}

//Game Functions
void Player::incYaht(){
    yah++;
}
void Player::incChan(){
    chance++;
}

//Operator Overloads
Player Player::operator ++ (){
    ++yah;
    return *this;
}
Player Player::operator -- (){
    --rolls;
    return *this;
}