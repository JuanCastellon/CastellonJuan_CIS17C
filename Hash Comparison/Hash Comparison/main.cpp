/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on July 19, 2016, 9:07 AM
 * Purpose:  Hello World Template
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
#include <list>
#include <map>
#include <iterator>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
string randStr(int);
unsigned int JSHash(const std::string& str);


//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declaring the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int size=80000000;
    int strsize=20;
    string *a1=new string[size];
    string *a2=new string[size];
    string *a3=new string[size];
    set<string> sortedA2;
    map<unsigned int, list<string> > hashes;
    int cnt1=0,cnt2=0,cnt3=0;
    string s;
    int begin,end;
    int loops;
    
    //Fill Arrays w/ Random Strings
    for(int i=0; i<size; i++){
        s=randStr(strsize);
        a1[i]=s;
        sortedA2.insert(s);
        a3[i]=s;
    }
    
    //Copies Sorted Set to Binary Search Array
    set<string>::iterator it=sortedA2.begin();
    int index=0;
    for(it=sortedA2.begin(); it!=sortedA2.end(); ++it){
        a2[index]=(*it);
        index++;
    }
    
    //Linear Search
    loops=25;
    begin=time(0);
    for(int j=0; j<loops; j++){
        for(int i=0; i<size; i++)
            if(s==a1[i]) cnt1++;
    }
    end=time(0);
    cout<<"Linear Search : "<<endl;
    cout<<"Array size         = "<<size<<endl;
    cout<<"Loops              = "<<loops<<endl;
    cout<<"String size        = "<<strsize<<endl;
    cout<<"Occurrences        = "<<cnt1<<endl;
    cout<<"Time               = "<<end-begin<<endl;
    
    //Binary Search
    s=a2[size-1];
    loops=16000000;
    begin=time(0);
    for(int i=0; i<loops; i++){
        int middle,min=0,max=size-1;;
        while (min<=max){
            middle=(int)(((max+min)/2)+0.5);
            if(s==a2[middle]){
                cnt2++;
                break;
            }else if(a2[middle]<s)
                min=middle+1;
            else
                max=middle-1;
        }
    }
    end=time(0);
    cout<<"Binary Search : "<<endl;
    cout<<"Array size    = "<<size<<endl;
    cout<<"Loops         = "<<loops<<endl;
    cout<<"String size   = "<<strsize<<endl;
    cout<<"Time          = "<<end-begin<<endl;
    
    //Hash Search
    for(int i=0; i<size; i++){
        unsigned int x=JSHash(a3[i]);
        hashes[x].push_back(a3[i]);
    }
    begin=time(0);
    loops=8000000;
    for(int i=0; i<loops; i++){
        unsigned int h=JSHash(s);
        if(hashes.count(h)==0) cnt3+=0;
     else {cnt3+=hashes[h].size(); break;}
    }
    end=time(0);
    cout<<"Hash Search : "<<endl;
    cout<<"Array size  = "<<size<<endl;
    cout<<"Loops       = "<<loops<<endl;
    cout<<"String size = "<<strsize<<endl;
    cout<<"Time        = "<<end-begin<<endl;
    
    delete [] a1;
    delete [] a2;
    delete [] a3;
    
    //Exits Program
    return 0;
}

//Random String Utility Function
string randStr(int strsize){
    string s="";
    for(int i=0; i<strsize; i++)
        s+=(48 + (rand() % (int)(122 - 48 + 1)));
    return s;
}

unsigned int JSHash(const std::string& str)
{
   unsigned int hash = 1315423911;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash ^= ((hash << 5) + str[i] + (hash >> 2));
   }

   return hash;
}

