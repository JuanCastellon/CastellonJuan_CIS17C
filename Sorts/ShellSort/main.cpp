
// C++ program for implementation of Heap Sort 
#include <iostream> 
#include <ctime>
#include <cstdlib>
using namespace std; 
  
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
// Start with a big gap, then reduce the gap 
int shellSort(int *arr,int n){
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted  
        for (int i = gap; i < n; i += 1) 
        { 
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = arr[i]; 
  
            // shift earlier gap-sorted elements up until the correct  
            // location for a[i] is found 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
              
            //  put temp (the original a[i]) in its correct location 
            arr[j] = temp; 
        } 
    }
    return 0;
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
    shellSort(arr, size); 
    int end=time(0);
    
    cout << "Execution time = "<<end-beg<<endl;
    
    delete [] arr;
    
    return 0;
} 