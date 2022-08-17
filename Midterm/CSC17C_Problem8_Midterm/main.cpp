/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

//User Libraries Here


//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Setting the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    vector<int> dice;
    int pair1;  //1 Pair counter
    int pair2;  //2 Pair counter
    int threeK; //3 of a kind counter
    int fourK;  //4 of a kind counter
    int ones,
        twos,
        threes,
        fours,
        fives,
        sixes;
    float cycles;
    
    //Initialize Variables
    pair1=pair2=threeK=fourK=0;//Setting all the counters 0
    dice.resize(4);            //4 die
    ones=twos=threes=fours=fives=sixes=0;
    cycles=1000000;
    
    
    for(int i=1;i<cycles;i++){
        //Filling the vector
        for(int j=0;j<dice.size();j++){
            dice[j]=rand()%6+1;
        }

        //Ones place
        if(dice[0]==1){ones++;}
        if(dice[1]==1){ones++;}
        if(dice[2]==1){ones++;}
        if(dice[3]==1){ones++;}

        //Twos place
        if(dice[0]==2){twos++;}
        if(dice[1]==2){twos++;}
        if(dice[2]==2){twos++;}
        if(dice[3]==2){twos++;}

        //Threes place
        if(dice[0]==3){threes++;}
        if(dice[1]==3){threes++;}
        if(dice[2]==3){threes++;}
        if(dice[3]==3){threes++;}

        //Fours place
        if(dice[0]==4){fours++;}
        if(dice[1]==4){fours++;}
        if(dice[2]==4){fours++;}
        if(dice[3]==4){fours++;}

        //Fives place
        if(dice[0]==5){fives++;}
        if(dice[1]==5){fives++;}
        if(dice[2]==5){fives++;}
        if(dice[3]==5){fives++;}

        //Sixes place
        if(dice[0]==6){sixes++;}
        if(dice[1]==6){sixes++;}
        if(dice[2]==6){sixes++;}
        if(dice[3]==6){sixes++;}

        //Testing for the cases
        
        //4 of a Kind
        if(ones==4||twos==4||threes==4||fours==4||fives==4||sixes==4){
            fourK++;
        }
        
        //3 of a Kind
        if(ones==3||twos==3||threes==3||fours==3||fives==3||sixes==3){
            threeK++;
        }
        
        //2 Pairs
        if(ones==2){
            if(twos==2){
                pair2++;
            }
            if(threes==2){
                pair2++;
            }
            if(fours==2){
                pair2++;
            }
            if(fives==2){
                pair2++;
            }
            if(sixes==2){
                pair2++;
            }
        }
        if(twos==2){
            if(ones==2){
                pair2++;
            }
            if(threes==2){
                pair2++;
            }
            if(fours==2){
                pair2++;
            }
            if(fives==2){
                pair2++;
            }
            if(sixes==2){
                pair2++;
            }
        }
        if(threes==2){
            if(twos==2){
                pair2++;
            }
            if(ones==2){
                pair2++;
            }
            if(fours==2){
                pair2++;
            }
            if(fives==2){
                pair2++;
            }
            if(sixes==2){
                pair2++;
            }
        }
        if(fours==2){
            if(twos==2){
                pair2++;
            }
            if(threes==2){
                pair2++;
            }
            if(ones==2){
                pair2++;
            }
            if(fives==2){
                pair2++;
            }
            if(sixes==2){
                pair2++;
            }
        }
        if(fives==2){
            if(twos==2){
                pair2++;
            }
            if(threes==2){
                pair2++;
            }
            if(fours==2){
                pair2++;
            }
            if(ones==2){
                pair2++;
            }
            if(sixes==2){
                pair2++;
            }
        }
        if(sixes==2){
            if(twos==2){
                pair2++;
            }
            if(threes==2){
                pair2++;
            }
            if(fours==2){
                pair2++;
            }
            if(fives==2){
                pair2++;
            }
            if(ones==2){
                pair2++;
            }
        }
        
        if(ones==2||twos==2||threes==2||fours==2||fives==2||sixes==2){
            pair1++;
        }
        
        ones=twos=threes=fours=fives=sixes=0;
        
    }
    
    cout<<pair1<<endl;
    cout<<pair2<<endl;
    cout<<threeK<<endl;
    cout<<fourK<<endl;
    
    //Display Results
    cout<<"Probability of 1 pair : "<<pair1/cycles*100<<"%"<<endl;
    cout<<"Probability of 2 pair : "<<pair2/cycles*100<<"%"<<endl;
    cout<<"Probability of 3 of a kind : "<<threeK/cycles*100<<"%"<<endl;
    cout<<"Probability of 4 of a kind : "<<fourK/cycles*100<<"%"<<endl;
    
    //Exit
    return 0;
}