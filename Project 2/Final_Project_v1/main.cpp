/* 
 * File:   main.cpp
 * Author: Juan Castellon
 * Created on: October 30th 2018
 * Purpose: Project 2 Yahtzee
*/

//System Libraries Here


using namespace std;

//User Libraries Here
#include "Player.h"
#include "Node.h"


//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here
void turn(int [],int,vector<Player> &,int);//Cycling through the turns
void winner(vector<Player>,int);         //Determines the winner
struct Node *newNode(int);               //New node for the binary tree
Node* insert(Node*, int);                //Inserts the node
void storeSorted(Node *, int [], int &); //Places the node properly
void treeSort(int [], int);            //Sorts the tree
void recurRoll(int [],int);              //Recursively generates the dice rolls
int diceSum(int []);                     //Sums up the dice
void disDice(int []);                    //Displays the dice
void rollDie(int [],int);                //Rolls an individual dice
void recurBubSort(int [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    //Declare all Variables Here
    //12341234123412341234123412341234123412341234123412341234123412341234123412
    
    //Temp variables for the names in the player vector
    string name1;
    string name2;
    
    //Vector for Player objects
    vector<Player> plyr;
    
    //Array for the 5 die
    int dice[5];
    
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
    cout<<"This program can play Yahtzee with 2 people."<<endl;
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
    cout<<"=====Two players will play the game====="<<endl;
    
    cout<<"Please enter the first name  : ";
    cin>>name1;
    cout<<"Please enter the second name : ";
    cin>>name2;
    cout<<endl;
    
    //Resizing the vector to 2 players
    plyr.resize(2);
    
    //Will be randomly choosing first player using a tree with a recursive sort
    int arr[20]={};
    for(int i=0; i<20; i++){
        arr[i]=rand()%90+10;
    }
    treeSort(arr,20);
    int indx1=rand()%20,
        indx2=rand()%20;

    //Initialize Player Objects
    if(indx1>indx2){
        cout<<name1<<" will be player 1"<<endl;
        cout<<name2<<" will be player 2"<<endl;
        plyr[0].setName(name1);
        plyr[1].setName(name2);
    }
    else{
        cout<<name2<<" will be player 1"<<endl;
        cout<<name1<<" will be player 2"<<endl;
        plyr[0].setName(name2);
        plyr[1].setName(name1);
    }
    
    //Turns of the game (there are 10 of them)
    do{
        cout<<"==========="<<endl;
        cout<<"==Turn "<<turns<<"=="<<endl;
        cout<<"==========="<<endl;
        turn(dice,5,plyr,plyr.size());
        turns++;
        
    }while(turns<=10);
    
    //Display Results
    winner(plyr,plyr.size());
    
    //Exit
    return 0;
}

//Cycling through the turns
void turn(int dice[],int nDice,vector<Player> &plyr,int nPlyr){
    int choice; //The choice for scoring
    char deci; //Decision to reroll
    int cnt=0;
    
    for(int i=0;i<nPlyr;i++){
        //Variables that need to be reset for the next player every time
        array<int,5> roll;  //Temp Array before I use something better
        int rolls=3;  //A player can reroll their dice 3 times per turn
        int counter=0;//A counter for scoring later on
        
        //Set the player's rolls to 3 to countdown
        plyr[i].setRoll(rolls);
        
        cout<<plyr[i].getName()<<" is rolling..."<<endl;
        
        //Rolling the dice for the player
        recurRoll(dice,cnt);
        cout<<endl;
        
        //Displaying the Results
        cout<<plyr[i].getName()<<" rolled : ";
        disDice(dice);
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
                //Had to include the - 1 so that the index is accessed properly
                switch(choice){
                    case 1:
                        rollDie(dice,choice-1);
                        break;
                        
                    case 2:
                        rollDie(dice,choice-1);
                        break;
                        
                    case 3:
                        rollDie(dice,choice-1);
                        break;
                        
                    case 4:
                        rollDie(dice,choice-1);
                        break;
                        
                    case 5:
                        rollDie(dice,choice-1);
                        break;
                }
                
                //Display the dice after the change
                cout<<"========New Roll========= "<<endl;
                cout<<plyr[i].getName()<<" rolled : ";
                disDice(dice);
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
                if(dice[0]==1){
                    plyr[i].setScre(1);
                }
                if(dice[1]==1){
                    plyr[i].setScre(1);
                }
                if(dice[2]==1){
                    plyr[i].setScre(1);
                }
                if(dice[3]==1){
                    plyr[i].setScre(1);
                }
                if(dice[4]==1){
                    plyr[i].setScre(1);
                }
                
                break;
            }
            case 2:{
                cout<<"Scoring Twos"<<endl;
                if(dice[0]==2){
                    plyr[i].setScre(2);
                }
                if(dice[1]==2){
                    plyr[i].setScre(2);
                }
                if(dice[2]==2){
                    plyr[i].setScre(2);
                }
                if(dice[3]==2){
                    plyr[i].setScre(2);
                }
                if(dice[4]==2){
                    plyr[i].setScre(2);
                }
                break;
            }
            case 3:{
                cout<<"Scoring Threes"<<endl;
                if(dice[0]==3){
                    plyr[i].setScre(3);
                }
                if(dice[1]==3){
                    plyr[i].setScre(3);
                }
                if(dice[2]==3){
                    plyr[i].setScre(3);
                }
                if(dice[3]==3){
                    plyr[i].setScre(3);
                }
                if(dice[4]==3){
                    plyr[i].setScre(3);
                }
                break;
            }
            case 4:{
                cout<<"Scoring Fours"<<endl;
                if(dice[0]==4){
                    plyr[i].setScre(4);
                }
                if(dice[1]==4){
                    plyr[i].setScre(4);
                }
                if(dice[2]==4){
                    plyr[i].setScre(4);
                }
                if(dice[3]==4){
                    plyr[i].setScre(4);
                }
                if(dice[4]==4){
                    plyr[i].setScre(4);
                }
                break;
            }
            case 5:{
                cout<<"Scoring Fives"<<endl;
                if(dice[0]==5){
                    plyr[i].setScre(5);
                }
                if(dice[1]==5){
                    plyr[i].setScre(5);
                }
                if(dice[2]==5){
                    plyr[i].setScre(5);
                }
                if(dice[3]==5){
                    plyr[i].setScre(5);
                }
                if(dice[4]==5){
                    plyr[i].setScre(5);
                }
                break;
            }
            case 6:{
                cout<<"Scoring Sixes"<<endl;
                if(dice[0]==6){
                    plyr[i].setScre(6);
                }
                if(dice[1]==6){
                    plyr[i].setScre(6);
                }
                if(dice[2]==6){
                    plyr[i].setScre(6);
                }
                if(dice[3]==6){
                    plyr[i].setScre(6);
                }
                if(dice[4]==6){
                    plyr[i].setScre(6);
                }
                break;
            }
            case 7:{
                cout<<"Scoring 3 of a Kind"<<endl;
                
                //Recursive Bubble Sort
                recurBubSort(dice,5);
                
                int temp=dice[0];
                for(int count=0;count<nDice;count++){
                    dice[count]==temp?counter++:temp=dice[count];
                }
                if(counter==3){
                    for(int count=0;count<nDice;count++){
                        plyr[i].setScre(dice[count]);
                    }
                }
                break;
            }
            case 8:{
                cout<<"Scoring 4 of a Kind"<<endl;
                
                //Recursive Bubble Sort
                recurBubSort(dice,5);
                
                int temp=dice[0];
                for(int count=0;count<nDice;count++){
                    if(dice[count]==temp){
                        counter++;    
                    }else{
                        temp=dice[count];
                    }
                }
                if(counter==4){
                    for(int count=0;count<nDice;count++){
                        plyr[i].setScre(dice[count]);
                    }
                }
                break;
            }
            case 9:{
                cout<<"Scoring Full House"<<endl;
                if(dice[0]==dice[1]){
                    if(dice[2]==dice[3]==dice[4]){
                        plyr[i].setScre(25);
                    }
                }
                if(dice[0]==dice[1]==dice[2]){
                    if(dice[4]==dice[5]){
                        plyr[i].setScre(25);
                    }
                }
                break;
            }
            case 10:{
                cout<<"Scoring Small Straight"<<endl;
                
                //Recursive Bubbble Sort
                recurBubSort(dice,5);
                
                //Scoring
                if((dice[4]-dice[3])==1){
                    if((dice[3]-dice[2]==1)){
                        if((dice[2]-dice[1]==1)){
                            plyr[i].setScre(30);
                        }
                    }
                }
                if((dice[3]-dice[2])==1){
                    if((dice[2]-dice[1]==1)){
                        if((dice[1]-dice[0]==1)){
                            plyr[i].setScre(30);
                        }
                    }
                }
                break;
            }
            case 11:{
                cout<<"Scoring Long Straight"<<endl;
                
                //Recursive Bubble Sort
                recurBubSort(dice,5);
                
                //Scoring
                if((dice[4]-dice[3])==1){
                    if((dice[3]-dice[2]==1)){
                        if((dice[2]-dice[1]==1)){
                            if((dice[1]==dice[0])==1){
                                plyr[i].setScre(40);
                            }
                        }
                    }
                }
                break;
            }
            case 12:{
                cout<<"Scoring Yahtzee"<<endl;
                if(dice[0]==dice[1]==dice[2]==dice[3]==dice[4]){
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
                    plyr[i].setScre(dice[count]);
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
//Utility Function to create a new BST node
struct Node *newNode(int item){ 
    struct Node *temp = new Node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
Node* insert(Node* node, int key){ 
    /* If the tree is empty, return a new Node */
    if(node == NULL){return newNode(key);} 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) Node pointer */
    return node; 
} 
void storeSorted(Node *root, int arr[], int &i) { 
    if (root != NULL) { 
        storeSorted(root->left, arr, i); 
        arr[i++] = root->key; 
        storeSorted(root->right, arr, i); 
    } 
} 
void treeSort(int arr[], int n){
    struct Node *root = NULL;
  
    // Construct the BST
    root = insert(root, arr[0]);
    for (int i=1; i<n; i++){
        insert(root, arr[i]);
    }
    int i = 0;
    storeSorted(root, arr, i);
}
void recurRoll(int dice[],int n){
    if(n<5){
        dice[n]=rand()%6+1;
        n++;
        recurRoll(dice,n);
    }
}
int diceSum(int dice[]){
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=dice[i];
    }
    return sum;
}
void disDice(int dice[]){
    for(int i=0;i<5;i++){
        cout<<dice[i]<<" ";
    }
}
void rollDie(int dice[],int num){
    dice[num]=rand()%6+1;
}
void recurBubSort(int arr[], int n){ 
    // Base case 
    if (n==1){ 
        return;
    }
    
    for (int i=0;i<n-1;i++){
        if (arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
        }
    }
    
    recurBubSort(arr, n-1); 
} 