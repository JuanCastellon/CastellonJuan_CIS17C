/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <list>    //For the array of linked lists
#include <vector>  //For the statistics
#include <cstdlib> //Random Function
#include <ctime>   //Time function

using namespace std;

//User Libraries Here


//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary


//Function Prototypes Here
unsigned int Hash(string);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    list<unsigned int> arr[512];//Array of linked lists of size 512
    vector<int> stats;
    string str;//The string we're going to be using to input the initials
    unsigned int index;
    int totHashes=0;
    
    //Initialize Variables
    str="";
    stats.resize(1);
    
    //For loop for inputting all the names
    for(int i=0;i<512;i++){
        
        //For loop for fill the string with random uppercase characters
        for(int j=0;j<3;j++){
            str[j]=(char)(rand()%26+65);//Uppercase character
        }
        
        //Passing the string into the hash function
        index=Hash(str);
        
        //Adding a node at the specified index as per the hash
        arr[index].push_back(index);
    }
    
    //Testing for the number of collisions
    for(int i=0;i<512;i++){
        //Declaring a temp variable to use
        int temp;
        
        //List size will determine size of vector
        //If size of the linked list is larger than the vector, it will resize
        if(stats.size()<arr[i].size()){
            stats.resize(arr[i].size());
        }
        
        //Size of the linked list will tell us how many collisions there were
        temp=arr[i].size();
        totHashes+=arr[i].size();
        
        //Increment the vector indexed by the number of collisions by 1
        stats[temp]++;
        
    }
    //Display Results
    for(int i=0;i<stats.size();i++){
        cout<<"Number of "<<i<<" collisions : "<<stats[i]<<endl;
    }
    cout<<"Total number of hashes = "<<totHashes<<endl;
    
    //Exit
    return 0;
}
unsigned int Hash(string str){
    //Declare variables
    unsigned int hash=0;//We will be returning this once we hash the string
    
    for(int i=0;i<3;i++){
        char temp=str[i];//don't want to type out array notation for the hash
        unsigned int j;
        
        //Hashing the characters of the string
        if(temp>=65&&temp<=67){j=2;}
        else if(temp>=68&&temp<=70){j=3;}
        else if(temp>=71&&temp<=73){j=4;}
        else if(temp>=74&&temp<=76){j=5;}
        else if(temp>=77&&temp<=79){j=6;}
        else if(temp>=80&&temp<=83){j=7;}
        else if(temp>=84&&temp<=86){j=8;}
        else if(temp>=85&&temp<=90){j=9;}
        
        //Adding onto the hash
        if(i==0){
           hash+=(j*100); 
        }
        if(i==1){
            hash+=(j*10);
        }
        if(i==2){
            hash+=j;
        }
    }
    //Modding it by 512 to give me a number between 0 and 512 as per array
    hash%=512;
    return hash;
}