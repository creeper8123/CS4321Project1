// Anthony - Uniquenes

//Group #16
//array size 10 to 100, inc 10
//values from 1600 to 16000
//run 1000 times

#include "prob1.h"

int main(int argc, char** argv){
    FILE* file = fopen("prob1out.csv", "w");

    //Confirm file exists
    if(file == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    //Add header
    fprintf(file, "Iteration Number,n=10,n=20,n=30,n=40,n=50,n=60,n=70,n=80,n=90,n=100\n");

    //Calculate important values
    int upper = 16000;
    int lower = 1600;
    int* array = malloc(sizeof(int) * 100);

    //Repeat for many tests
    for (int i = 1; i <= NUM_OF_ITERATIONS; i++){
        fprintf(file, "%d,", i); //add iteration number

        //Repeat for different array sizes
        for (int j = 10; j <= 100; j+=10){

            //Fill array with new values
            for (int k = 0; k < j; k++){
                array[k] = (rand() % (upper - lower + 1)) + lower;
            }

            //Add data to file
            fprintf(file, "%d,", uniqueElementAlg(array, j));
        }
        fprintf(file, "\n");
    }
    
    //Clean up
    free(array);
    fclose(file);

    return 0;
}

int uniqueElementAlg(int* array, int arraySize){
    int numOfCollisions = 0;

    for (int i = 0; i < arraySize-1; i++){
        for (int j = i+1; j < arraySize; j++){
            if(array[i] == array[j]){
                numOfCollisions++;
            }
        }
    }

    return numOfCollisions;
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