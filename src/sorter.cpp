#include <dummycmake/sorter.hpp>
#include <dummycmake/blinker.hpp>
// we did not include the vector include but it still worked
#include <vector>
// take in a vector of ints and output return a sorted copy

int partition(std::vector<int> &a, int low, int high);
 
void quicksort(std::vector<int> &a, int low, int high){
    if (low < high){
        int p = partition(a, low, high);
        quicksort(a, low, p);
        quicksort(a, p+1, high);
    }
}

int partition(std::vector<int> &a, int low, int high){
    int pivot = a[(int)((high + low)/2)];
    int i = low - 1;
    int j = high + 1;

    while (true){
        do{
            i = i + 1;
        } while (a[i] < pivot);
        do {
            j = j -1;
        } while(a[j] > pivot);

        if (i >= j) return j;
        
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp; 
    }
}