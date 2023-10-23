#include "prob2.h"
// Collin - Insurtion
// John - Bubble


int main(int argc, char** argv){

    int n = 10;
    int* array = malloc(sizeof(int) * n);
    int teamNumber = 16;

    for(int i = 0; i < n; i++){
        array[i] = (rand() % 100000) * teamNumber;
    }


    clock_t start, end;
    // Testing algorithm1
    start = clock();
    insertionSort(array, n);
    end = clock();
    double time_taken_alg1 = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Insertion sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg1, n);

    for(int i = 0; i<n; i++){
        printf(" %d\n ", array[i]);
    }

    for(int i = 0; i < n; i++){
        array[i] = (rand() % 100000)  * teamNumber;
    }



    // Testing algorithm2
    start = clock();
    bubbleSort(array, n);
    end = clock();
    double time_taken_alg2 = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Bubble sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg2, n);

    for(int i = 0; i<n; i++){
        printf(" %d\n ", array[i]);
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
    //fprintf(file, "%d,", timeForInsertion));
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

void bubbleSort(int size[], int m){
    int index;
    for(int i = 0; i < m -2; i++){

        for (int j = 0; j< m-2-1; j++ ){
            index = size[j];

            if (size[j+1]<size[j]){
                size[j] = size[j+1];
                size[j+1] = index;
            }
        }

    }

}

