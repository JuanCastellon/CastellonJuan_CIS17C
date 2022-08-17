/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 1st, 2018, 7:45 PM
 */

//Libraries
#include <iostream>
#include <cstdlib>//Random Function
#include <ctime>  //Time Function
#include <set>
#include <map>
#include <vector>
#include <iterator>
using namespace std;

//No Global Constants

//Function Prototypes
int *fillAry(int,int,short);
void prntAry(int *,int,int);
void mode(int *ary, int arySize, int modNum);

//Execution begins here
int main(int argc, char*argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables and fill
    int arySize=35;
    int modNum=10;
    int *ary=fillAry(arySize,modNum, 0);
    mode(ary, arySize, modNum);
    ary=fillAry(arySize,modNum, 1);
    mode(ary, arySize, modNum);
    ary=fillAry(arySize,modNum, 2);
    mode(ary, arySize, modNum);
    return 0;
}

void mode(int *ary, int arySize, int modNum) {
    multiset<int, less<int>> s;
    multiset<int, greater<int>> set2;
    map<int, int> map1;
    for (int i = 0; i < arySize; i++) {
        s.insert(ary[i]);
    }
    for (int i = 0; i < 35; i++) {
        int count = s.count(ary[i]);
        set2.insert(count);
        map1.insert(pair<int,int>(ary[i], count));
    }
    cout<<endl;
    prntAry(ary,arySize,10);
    cout<<"Mode Freq = "<<*set2.begin()<<endl;
    vector<int> modes;
    cout<<"The mode set = { ";
    if (*set2.begin()==1){
        cout << "no mode }" << endl;
        cout << "The number of modes = 0" << endl;
        return;
    }
    for (auto elem : map1) {
        if (elem.second == *set2.begin()) {
            cout << elem.first << " ";
            modes.push_back(elem.second);
        }
    }
    cout << "}" <<endl;
    cout << "The number of modes = " << modes.size() << endl;
}

void prntAry(int *array,int n,int perLine){
    //Output the array
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(array+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n, int modNum, short type){
    //Allocate memory
    int *array=new int[n];
    //Fill the array with 2 digit numbers
    for(int i=0;i<n;i++){
        if (type == 0) {
            *(array+i)=i;
        } else if (type == 1) {
            *(array+i)=i%modNum;
        } else if (type == 2) {
            if (i == 2) {
                // 1 mode
                *(array+i)=0;
            } else {
                *(array+i)=i;
            }
        }
        //*(array+i)=rand()%modNum;
    }
    //Exit function
    return array;
}
