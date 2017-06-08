#include <iostream>
#include <array>

using namespace std;

void quickSort(int arr[], int left, int right);
void printArray(int arr[], int size);

int main(int argc, const char * argv[]) {
    
    int arr[] = {23, 84, 34, 27, 3, 8, 19, 54, 62, 99, 12, 43, 22, 91, 1, 5, 33, 51, 88, 32, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted array: \n");
    printArray(arr, n);
    
    quickSort(arr, 0, n - 1 );
    
    printf("Sorted array: \n");
    printArray(arr, n);
 
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

void printArray(int arr[], int size){
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

