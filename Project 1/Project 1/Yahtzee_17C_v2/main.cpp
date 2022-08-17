/* 
 * File:   main.cpp
 * Author: Juan Castellon
 * Created on: October 30th 2018
 * Purpose: Project 1 Yahtzee
*/

//System Libraries Here


using namespace std;

//User Libraries Here
#include "Player.h"
#include "Dice.h"


//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
void first(vector<Player>,int,vector<Dice>,int,map<string,int>);//Determining who goes first
void turn(vector<Dice>,int,vector<Player> &,int);//Cycling through the turns
void winner(vector<Player>,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    //Declare all Variables Here
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    
    //Maps for determining the order of player turn
    map <string,int> indxName;//Index with player name for deciding order of roll
    
    
    //Vector for Player objects
    vector<Player> plyr;
    
    //Decision making variables
    char deci;                  //Decision to play the game or not
    int turns=1;                //Game lasts 20 turns, starts at 1
    int nPlyr;                  //How many players are determined to play
    
    //Member Function Variables
    string name;
    float score;
    int yah;
    
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    //End of Variable Declaring
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    
    //Introduction
    cout<<"This program can play Yahtzee with 2-5 people."<<endl;
    cout<<"Press 'y' to play and 'n' to exit."<<endl;
    
    cin>>deci;
    
    while(deci!='y'&&deci!='n'){
        cout<<"Please input a valid response."<<endl;
        cin.ignore();
        cin>>deci;
    }
    
    //Exiting the program if the player chooses not to play
    if(deci=='n'){
        exit(0);
    }
    
    //Determining how many players are going to play the game
    cout<<"How many players are going to play the game? Pick from 2-5."<<endl;
    while(nPlyr<2||nPlyr>5){
        cin>>nPlyr;
        
        //Input Validation
        if(nPlyr<2||nPlyr>5){
            cout<<"Invalid number of players. Please enter a number from "
                    "2-5."<<endl;
            cin>>nPlyr;
        }
    }
    
    
    
    //Skips to the next line
    cin.ignore();
    
    //Resizing the vector to the number of inputted players
    plyr.resize(nPlyr);
    
    //Creating the vector for the dice, sort of dumb since it's only 1 element
    //but I figured since I already have all the functions from the class I 
    //wrote in 17A, I might as well just make the array of the Dice class
    //and use the pre-made functions.
    vector<Dice> dice;
    
    //Sizing the vector to the one dice object
    dice.resize(1);
    
    //Getting the players' names
    for(int i=0;i<nPlyr;i++){
        cout<<"Please input player "<<i+1<<"'s name."<<endl;
        getline(cin,name);
        
        //Setting the keys
        indxName.insert(pair<string,int> (name,0));
        
        //Getting the name of the player
        plyr[i].setName(name);
    }
    
    //Deciding who goes first, 5 comes from the number of dice
    first(plyr,plyr.size(),dice,5,indxName);
    
    //Turns of the game (there are 10 of them)
    do{
        cout<<"==========="<<endl;
        cout<<"==Turn "<<turns<<"=="<<endl;
        cout<<"==========="<<endl;
        turn(dice,5,plyr,plyr.size());
        turns++;
        
    }while(turns<=1);
    
    //Display Results
    winner(plyr,plyr.size());
    
    //Exit
    return 0;
}

//Function to determine who goes first
void first(vector<Player> plyr,int nPlyr,vector<Dice> dice,int nDice,
           map<string,int> indxName){
    
    
    
    //Prompting the player of what's going on
    cout<<"Players will now roll to see who will go first."<<endl;
    cout<<"========================"<<endl;
    
    
    //For Loop for determining
    for(int i=0;i<nPlyr;i++){
        cout<<plyr[i].getName()<<" is rolling..."<<endl;
        
        //Roll the dice
        dice[0].roll();
        
        //Set the index of the player to sum to later
        indxName[plyr[i].getName()]=dice[0].sum();
        
        
        //Displaying outcome
        cout<<plyr[i].getName()<<" rolled : ";
        cout<<indxName[plyr[i].getName()]<<endl;

        cout<<endl;
        cout<<"========================"<<endl;
        
    }
    
    //Comparing indexes and sorting based on who got the highest scores
    for(int i=0;i<nPlyr;i++){
        for(int j=i+1;j<nPlyr;j++){
            if(indxName[plyr[i].getName()]<indxName[plyr[j].getName()]){
                swap(plyr[i],plyr[j]);//Swap function from the STL Library
            }
        }
    }
    
    //Displaying who will go first
    for(int i=0;i<nPlyr;i++){
        cout<<plyr[i].getName()<<" will be player "<<i+1<<endl;
    }
}

//Cycling through the turns
void turn(vector<Dice> dice,int nDice,vector<Player> &plyr,int nPlyr){
    int choice; //The choice for scoring
    char deci; //Decision to reroll
    
    for(int i=0;i<nPlyr;i++){
        //Variables that need to be reset for the next player every time
        array<int,5> roll;  //Temp Array before I use something better
        int rolls=3;  //A player can reroll their dice 3 times per turn
        int counter=0;//A counter for scoring later on
        
        //Set the player's rolls to 3 to countdown
        plyr[i].setRoll(rolls);
        
        cout<<plyr[i].getName()<<" is rolling..."<<endl;
        
        //Rolling the dice for the player
        dice[0].roll();
        
        //Displaying the Results
        cout<<plyr[i].getName()<<" rolled : ";
        dice[0].display();
        cout<<endl;
        
        //Asking the player if they would like to reroll one of their die
        cout<<"Would you like to reroll a die?"<<endl;
        cout<<"y/n : ";
        cin>>deci;
        
        //Input Validation
        while(deci!='y'&&deci!='n'){
            cout<<"Please input a valid response."<<endl;
            cin.ignore();
            cin>>deci;
        }
        
        if(deci=='y'){
            do{
                cout<<"Which die would you like to reroll? ";
                cout<<"Input a number 1-5"<<endl;
                cin>>choice;
                
                //Input Validation
                while(choice>5&&choice<1){
                    cout<<"Please input a number from 1-5.";
                    cin>>choice;
                    
                    //Input Validation
                    while(choice<1&&choice>5){
                        cout<<"Please input a valid response."<<endl;
                        cin>>choice;
                    }
                    cout<<endl;
                }
                
                //Rerolling the dice themselves
                switch(choice){
                    case 1:
                        dice[0].setD1();
                        break;
                        
                    case 2:
                        dice[0].setD2();
                        break;
                        
                    case 3:
                        dice[0].setD3();
                        break;
                        
                    case 4:
                        dice[0].setD4();
                        break;
                        
                    case 5:
                        dice[0].setD5();
                        break;
                }
                
                //Display the dice after the change
                cout<<"========New Roll========= "<<endl;
                cout<<plyr[i].getName()<<" rolled : ";
                dice[0].display();
                cout<<endl;
                
                //Overloaded operator to decrement the amount of rerolls left
                --plyr[i];
                
                //Displaying the number of rerolls left
                cout<<"Rerolls left : "<<plyr[i].getRoll()<<endl;
                
                //Prompting the user to decide on rerolling again
                if(plyr[i].getRoll()!=0){
                    cout<<"Would you like to reroll again?"<<endl;
                    cout<<"y/n : ";
                    cin>>deci;
                    
                    //Input Validation
                    while(deci!='y'&&deci!='n'){
                        cout<<"Please input a valid response."<<endl;
                        cin.ignore();
                        cin>>deci;
                    }
                    
                    cout<<endl;
                }
            }while(deci=='y'&&plyr[i].getRoll()!=0);
        }
        
        //Copying values for now
        //Copying the numbers in the dice object to an array for easier scoring
        roll[0]=dice[0].getD1();
        roll[1]=dice[0].getD2();
        roll[2]=dice[0].getD3();
        roll[3]=dice[0].getD4();
        roll[4]=dice[0].getD5();
        
        //Testing to see if copied correctly
        for(int i=0;i<nDice;i++){
            cout<<roll[i]<<" ";
        }
        cout<<endl;
        
        //Scoring the dice rolls now
        cout<<"Which category would you like to score?"<<endl;
        cout<<"Aces           = 1"<<endl;
        cout<<"Twos           = 2"<<endl;
        cout<<"Threes         = 3"<<endl;
        cout<<"Fours          = 4"<<endl;
        cout<<"Fives          = 5"<<endl;
        cout<<"Sixes          = 6"<<endl;
        cout<<"3 of a Kind    = 7"<<endl;
        cout<<"4 of a Kind    = 8"<<endl;
        cout<<"Full House     = 9"<<endl;
        cout<<"Small Straight = 10"<<endl;
        cout<<"Large Straight = 11"<<endl;
        cout<<"Yahtzee        = 12"<<endl;
        cout<<"Chance         = 13"<<endl;
        cout<<"Note! You may only score by chance once!"<<endl;
        
        //Inputting the choice
        cin>>choice;
        
        //Input Validation
        while(choice>13&&choice<1){
            cout<<"Invalid choice. Please choose a number from 1-13."<<endl;
            cin>>choice;
        }
        
        while(plyr[i].getChan()>0){
            cout<<"You have already chosen the Chance category. Please "
                    "select another category."<<endl;
            cin>>choice;
        }
        
        //Checking if Chance category was selected
        if(choice==13){
            plyr[i].incChan();
        }
        
        switch(choice){
            case 1:{
                cout<<"Scoring Aces"<<endl;
                if(roll[0]==1){
                    plyr[i].setScre(1);
                }
                if(roll[1]==1){
                    plyr[i].setScre(1);
                }
                if(roll[2]==1){
                    plyr[i].setScre(1);
                }
                if(roll[3]==1){
                    plyr[i].setScre(1);
                }
                if(roll[4]==1){
                    plyr[i].setScre(1);
                }
                
                break;
            }
            case 2:{
                cout<<"Scoring Twos"<<endl;
                if(roll[0]==2){
                    plyr[i].setScre(2);
                }
                if(roll[1]==2){
                    plyr[i].setScre(2);
                }
                if(roll[2]==2){
                    plyr[i].setScre(2);
                }
                if(roll[3]==2){
                    plyr[i].setScre(2);
                }
                if(roll[4]==2){
                    plyr[i].setScre(2);
                }
                break;
            }
            case 3:{
                cout<<"Scoring Threes"<<endl;
                if(roll[0]==3){
                    plyr[i].setScre(3);
                }
                if(roll[1]==3){
                    plyr[i].setScre(3);
                }
                if(roll[2]==3){
                    plyr[i].setScre(3);
                }
                if(roll[3]==3){
                    plyr[i].setScre(3);
                }
                if(roll[4]==3){
                    plyr[i].setScre(3);
                }
                break;
            }
            case 4:{
                cout<<"Scoring Fours"<<endl;
                if(roll[0]==4){
                    plyr[i].setScre(4);
                }
                if(roll[1]==4){
                    plyr[i].setScre(4);
                }
                if(roll[2]==4){
                    plyr[i].setScre(4);
                }
                if(roll[3]==4){
                    plyr[i].setScre(4);
                }
                if(roll[4]==4){
                    plyr[i].setScre(4);
                }
                break;
            }
            case 5:{
                cout<<"Scoring Fives"<<endl;
                if(roll[0]==5){
                    plyr[i].setScre(5);
                }
                if(roll[1]==5){
                    plyr[i].setScre(5);
                }
                if(roll[2]==5){
                    plyr[i].setScre(5);
                }
                if(roll[3]==5){
                    plyr[i].setScre(5);
                }
                if(roll[4]==5){
                    plyr[i].setScre(5);
                }
                break;
            }
            case 6:{
                cout<<"Scoring Sixes"<<endl;
                if(roll[0]==6){
                    plyr[i].setScre(6);
                }
                if(roll[1]==6){
                    plyr[i].setScre(6);
                }
                if(roll[2]==6){
                    plyr[i].setScre(6);
                }
                if(roll[3]==6){
                    plyr[i].setScre(6);
                }
                if(roll[4]==6){
                    plyr[i].setScre(6);
                }
                break;
            }
            case 7:{
                cout<<"Scoring 3 of a Kind"<<endl;
                
                //Sorting with Iterators
                sort(roll.begin(),roll.begin()+5);
                
                int temp=roll[0];
                for(int count=0;count<nDice;count++){
                    roll[count]==temp?counter++:temp=roll[count];
                }
                if(counter==3){
                    for(int count=0;count<nDice;count++){
                        plyr[i].setScre(roll[count]);
                    }
                }
                break;
            }
            case 8:{
                cout<<"Scoring 4 of a Kind"<<endl;
                
                //Sorting with Iterators
                sort(roll.begin(),roll.begin()+5);
                
                int temp=roll[0];
                for(int count=0;count<nDice;count++){
                    if(roll[count]==temp){
                        counter++;    
                    }else{
                        temp=roll[count];
                    }
                }
                if(counter==4){
                    for(int count=0;count<nDice;count++){
                        plyr[i].setScre(roll[count]);
                    }
                }
                break;
            }
            case 9:{
                cout<<"Scoring Full House"<<endl;
                if(roll[0]==roll[1]){
                    if(roll[2]==roll[3]==roll[4]){
                        plyr[i].setScre(25);
                    }
                }
                if(roll[0]==roll[1]==roll[2]){
                    if(roll[4]==roll[5]){
                        plyr[i].setScre(25);
                    }
                }
                break;
            }
            case 10:{
                cout<<"Scoring Small Straight"<<endl;
                
                //Sorting with Iterators
                sort(roll.begin(),roll.begin()+5);
                
                //Scoring
                if((roll[4]-roll[3])==1){
                    if((roll[3]-roll[2]==1)){
                        if((roll[2]-roll[1]==1)){
                            plyr[i].setScre(30);
                        }
                    }
                }
                if((roll[3]-roll[2])==1){
                    if((roll[2]-roll[1]==1)){
                        if((roll[1]-roll[0]==1)){
                            plyr[i].setScre(30);
                        }
                    }
                }
                break;
            }
            case 11:{
                cout<<"Scoring Long Straight"<<endl;
                
                //Sorting with Iterators
                sort(roll.begin(),roll.begin()+5);
                
                //Scoring
                if((roll[4]-roll[3])==1){
                    if((roll[3]-roll[2]==1)){
                        if((roll[2]-roll[1]==1)){
                            if((roll[1]==roll[0])==1){
                                plyr[i].setScre(40);
                            }
                        }
                    }
                }
                break;
            }
            case 12:{
                cout<<"Scoring Yahtzee"<<endl;
                if(roll[0]==roll[1]==roll[2]==roll[3]==roll[4]){
                    if(plyr[i].getYaht()>0){
                        plyr[i].setScre(100);
                    }else if(&plyr[i].getYaht==0){
                        plyr[i].setScre(50);
                        ++plyr[i];
                    } 
                }
                break;
            }
            case 13:{
                cout<<"Scoring Chance"<<endl;
                for(int count=0;count<nDice;count++){
                    plyr[i].setScre(roll[count]);
                }
                break;
            }
        }
        cout<<plyr[i].getName()<<"'s score this turn = "<<plyr[i].getScre();
        cout<<endl;
        cout<<"========================"<<endl;
    }    
}
void winner(vector<Player> plyr,int nPlyr){
    //Outputting the winner of the game using a stack
    stack<string> placemnt;
    
    //Sorting the players based on score
    for(int i=0;i<nPlyr;i++){
        for(int j=i+1;j<nPlyr;j++){
            if(plyr[i].getScre()<plyr[j].getScre()){
                swap(plyr[i],plyr[j]);//Swap function from the STL Library
            }
        }
    }
    
    //Inserting the names into the stack
    for(int i=0;i<nPlyr;i++){
        placemnt.push(plyr[i].getName());
    }
    
    //Outputting the placements
    for(int i=0;i<nPlyr;i++){
        cout<<"#"<<i+1<<endl;
        cout<<placemnt.top()<<" score : "<<plyr[i].getScre()<<endl;
        
        //Popping off the name on the top of the stack to get to the next name
        placemnt.pop();
    }
    
}