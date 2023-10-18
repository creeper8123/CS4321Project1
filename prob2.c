#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <prob2.h>
// Collin - Insurtion
// Jon - Bubble


int main(int argc, char** argv){

    int n = 10;
    int array[n];
    int teamNumber = 16;

    for(int i = 0; i < n; i++){
        array[i] = rand() * teamNumber;
    }

    insertionSort(array, n);


    return 0;
}


void insertionSort(int array[], int n){

    int j;
    int key;
    for (int i = 1; i < n; i++) {

        key = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

