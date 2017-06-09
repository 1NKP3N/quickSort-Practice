#include <iostream>
#include <array>
#include <vector>
#include <time.h>
#include <stdlib.h>

using namespace std;

void quickSort(int arr[], int left, int right);
void printArray(int arr[], int size);
void quickSortHelper();


int main(int argc, const char * argv[]) {

    srand((unsigned)time(0));
    quickSortHelper();
    

}

void quickSort(int arr[], int left, int right){
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    
    while(i <= j){
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i <= j){
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if(left < j){
        quickSort(arr, left, j);
    }
    if(i < right){
        quickSort(arr, i, right);
    }
}

void printArray(int array[], int size){
    int i;
    cout << "[";
    for (i=0; i < size; i++){
        cout << array[i];
        if(i != size - 1){
            cout << ", ";
        }
    }
    cout << "]";
}

void quickSortHelper(){
    
    int size;
    cout << "How big do you want the array? ";
    cin >> size;
    
    int* arr = new int[size];
    for(int i = 0; i < size; i++){
        arr[i] = (rand() % 100) + 1;
    }
    
    cout << "\nUnsorted Array: ";
    printArray(arr, size);
    cout << endl << endl;
    
    quickSort(arr, 0, size - 1);
    
    cout << "Sorted Array: ";
    printArray(arr, size);
    cout << endl;
    
}

