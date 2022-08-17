/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dubLink.h
 * Author: Juan
 *
 * Created on October 8, 2018, 9:14 PM
 */

#ifndef DUBLINK_H
#define DUBLINK_H

struct Link{
    int data;  //Corresponding data
    Link *next;
    Link *prev;
};

Link *head;   //Head of the linked list
Link *tail;   //Tail of the linked list
Link *newNode;//New node of the linked list

#endif /* DUBLINK_H */

