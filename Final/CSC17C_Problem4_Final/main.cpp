/* 
 * File:   main.cpp
 * Author: 
 * Created on:
 * Purpose:
*/

//System Libraries Here
#include <iostream>//cin,cout
#include <cstdlib>
#include <ctime>


using namespace std;


//User Libraries Here


//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
int selCnt=0;
int merCnt=0;

//Function Prototypes Here
void merge(short int [],int l,int m,int r);
void mergeSort(short int [],int l, int r);
void selectionSort(short int [],int n);
void swap(int *,int *);
void fill(short int []);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    short int toSel[100000];
    short int toMer[100000];
    int p;
    
    //Initialize Variables
    
    cout<<"Input a value for p : ";
    cin>>p;
    cout<<endl;
    
    fill(toMer);
    
    //Copy Contents
    for(int i=0;i<100000;i++){
        toSel[i]=toMer[i];
        
    }
    cout<<"First element in the list : "<<toSel[0]<<endl;
    
    
    //Process Input/Output
    mergeSort(toMer,0,99999);
    selectionSort(toSel,p);
    
    cout<<"Top "<<p<<" elements in the list"<<endl;
    cout<<"Merge Sort       Selection Sort"<<endl;
    for(int i=0;i<p;i++){
        cout<<"  "<<toMer[i]<<"            "<<toSel[i]<<endl;
    }
    
    cout<<"Selection Sort Operations = "<<selCnt<<endl;
    cout<<"Merge Sort Operations     = "<<merCnt<<endl;
    
    //Display Results
    
    
    //Exit
    return 0;
}
void selectionSort(short int arr[], int n) {

      int i, j, minIndex;
      short int tmp;
       
      selCnt++;
      for (i = 0; i < n - 1; i++) {

            minIndex = i;
            
            selCnt+=6;

            for (j = i + 1; j < n; j++){
                selCnt+=3;
                if (arr[j] > arr[minIndex]){ 
                    minIndex = j;
                    selCnt++;
                }
            }
                  
            selCnt++;
            if (minIndex != i) {

                  tmp = arr[i];

                  arr[i] = arr[minIndex];

                  arr[minIndex] = tmp;
                  
                  selCnt++;

            }

      }

}
void merge(short int a[], int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
        
        merCnt+=6;
 
	// Merge the two parts into temp[].
        
        merCnt+=3;
        
	while (i <= mid && j <= high){
            merCnt+=4;
            if (a[i] > a[j])
            {
                temp[k] = a[i];
                k++;
                i++;
                merCnt+=3;
            }
            else
            {
                temp[k] = a[j];
                k++;
                j++;
                merCnt+=3;
            }
	}
 
	// Insert all the remaining values from i to mid into temp[].
        merCnt++;
	while (i <= mid){
            temp[k] = a[i];
            k++;
            i++;
            merCnt+=3;
	}
 
	// Insert all the remaining values from j to high into temp[].
        merCnt++;
	while (j <= high){
            temp[k] = a[j];
            k++;
            j++;
            merCnt++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
        merCnt++;
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
                merCnt+=4;
	}
}
 
// A function to split array into two parts.
void mergeSort(short int a[], int low, int high)
{
	int mid;
        merCnt++;
	if (low < high){
            mid=(low+high)/2;
            // Split the data into two half.
            mergeSort(a, low, mid);
            mergeSort(a, mid+1, high);

            // Merge them to get sorted output.
            merge(a, low, high, mid);
            merCnt+=3;
	}
}
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void fill(short int arr[]){
    for(int i=0;i<100000;i++){
        arr[i]=rand();
    }
}