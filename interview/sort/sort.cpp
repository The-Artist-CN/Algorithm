#include <iostream>



void BubbleSort(int arr[] , int n){
    for ( int i = 0; i < n - 1 ; i++ ){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1]){
                std::swap(arr[j],arr[j+1]);
            }
        }
    }
}

//Apr 2 9:00AM

void BubbleSortV2(int arr[] , int size){
    for (int i = 0 ; i < size-1 ; i++){
        for (int j = 0 ; j < size - i - 1 ;j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;

            }
        }
    }
}

void SelectionSort(int arr[] , int n){
    for (int i = 0 ; i < n - 1; i++){
        int minIndex = i;
        for (int j = i + 1 ; j < n - 1 - i ; j++){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }

        std::swap(arr[i],arr[minIndex]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}


int main(){
    int arr[] = {3,2,5,4,7,6,8,0,9,1,10,19,18,14,13,12,16,17};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int a : arr){
        std::cout << a << " ";
    }

    std::cout << std::endl;

    BubbleSort(arr,n);

    for (int a : arr){
        std::cout << a << " ";
    }

    BubbleSortV2(arr,n);


    return 0;
}
