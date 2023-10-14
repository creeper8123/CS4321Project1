// Anthony - Uniquenes

//Group #16
//array size 10 to 100, inc 10
//values from 1600 to 16000
//run 1000 times

#include "prob1.h"

int main(int argc, char** argv){
    int temp[11] = {1, 2, 3, 4, 5, 6, 11, 7, 8, 9, 10};
    printf("result: %d\n", time(NULL));
    return 0;
}

bool uniqueElementAlg(int* array, int arraySize){
    for (int i = 0; i < arraySize-1; i++){
        for (int j = i+1; j < arraySize; j++){
            if(array[i] == array[j]){
                return false;
            }
        }
    }

    return true;
}

/*
Alg directly from notes:

for(i from 0 to n-2){ //if n-1, would compare with itself
    for(j from i+1 to n-1){
        if(A[i] == A[j]){
            return false;
        }
    }
}
*/