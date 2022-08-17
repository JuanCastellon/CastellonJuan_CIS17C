/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <cmath>
#include "BinaryTree.h"


using namespace std;

//User Libraries Here


//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    int size = 1000;
    BinaryTree<string> *tree = new BinaryTree<string>;
    cout<<"Tree contains"<<endl;
    string str = "   ";
    
    //Inserting the 3 Initials into the string
    for(int i=0;i<size;i++){
        //This will put a random upper case character into the string0
        str[0]=(rand() % 26 + 65);
        str[1]=(rand() % 26 + 65);
        str[2]=(rand() % 26 + 65);
        
        //Inserting the string into a tree
        tree->insert(str);
    }
    
    cout<<endl;
    cout<<"At most it will take "<<ceil(log(size)/log(2))+1<<" times to find";
    
    //Deleting the memory allocated with the tree pointer
    delete tree;
    
    //Exit Stage Right
    return 0;
}