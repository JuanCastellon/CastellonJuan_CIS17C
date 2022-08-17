
// C++ program for implementation of Heap Sort 
#include <iostream> 
#include <ctime>
#include <cstdlib>
  
using namespace std; 
  
// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
/* The main function that implements QuickSort 
 arr[] --> Array to be sorted, 
  low  --> Starting index, 
  high  --> Ending index */
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 

  
// Driver program 
int main() 
{   
    srand(static_cast<unsigned int>(time(0)));
    int size;
    int *arr;
    cout<<"Input the size of the array : ";
    cin>>size;
    arr=new int[size];
    for(int i=0;i<size;i++){
        arr[i]=rand();
    }
     
    
    int beg=time(0);
    quickSort(arr,0,size-1);
    int end=time(0);
    
    cout << "Execution time = "<<end-beg<<endl;
    
    delete [] arr;
    
    return 0;
} 