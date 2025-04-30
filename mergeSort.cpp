#include <iostream>

using namespace std;
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void printArray(int arr[], int size);

int main(){

    int array[] = {3, 8, 6, 4, 5, 1, 2, 7};
    int size = sizeof(array) / sizeof(array[0]);

    cout<< "Unsorted: ";
    for(int i = 0; i < size; i++){
        cout<< array[i] << " ";
    }
    cout<< endl;

    mergeSort(array, 0, size - 1);

    printArray(array, size);

    return 0;
}

void mergeSort(int arr[], int left, int right){
    if(left < right){

        int mid =( left + right ) / 2;
        
        mergeSort(arr, left, mid);

        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}
void merge(int arr[], int left, int mid, int right){
    int i, j, k;
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    //initialize temporary arrays
    int leftArr[leftSize];
    int rightArr[rightSize];

    //pointer for left and right
    for(i = 0; i < leftSize; i++){
        leftArr[i] = arr[left + i];
    }
    for(j = 0; j < rightSize; j++){
        rightArr[j] = arr[mid + 1 + j];
    }

    //reinitialize value of i and j for indexes
    i = 0; //index of left array
    j = 0; //index of right array
    k = left; //index of original array

    while(i < leftSize && j < rightSize){
        if(leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++; //continue next index in left array
        }
        else{
            arr[k] = rightArr[j];
            j++;  //continue next index in right array
        }
        k++; //store value next index of original array
    } 

    while(i < leftSize){
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while(j < rightSize){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}
void printArray(int arr[], int size){
    cout<<"Sorted: ";
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}