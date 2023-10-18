
#include "prob2.h"

// Collin - Insurtion
// Jon - Bubble


int main(int argc, char** argv){

    int n = 10;
    int* array = malloc(sizeof(int) * n);
    int teamNumber = 16;

    for(int i = 0; i < n; i++){
        array[i] = rand() * teamNumber;
    }

    //Create file
    FILE* file = fopen("prob2out.csv", "w");

    //Confirm file exists
    if(file == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    //Add header
    fprintf(file, "n Size,insertion,bubble\n");

    //START LOOP HERE
    fprintf(file, "%d,", n);
    //#####################
    //INERTION HERE
    //fprintf(file, "%d,", timeForInsertion);
    //BUBBLE HERE
    //fprintf(file, "%d,", timeForBubble);
    //####################

    //END LOOP HERE

    //Clean up
    fclose(file);
    free(array);

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

