#include "prob2.h"
// Collin - Insurtion
// John - Bubble


int main(int argc, char** argv){

    int n = 1000;
    int* array1 = malloc(sizeof(int) * n);
    int* array2 = malloc(sizeof(int) * (n*10));
    int* array3 = malloc(sizeof(int) * (n* 100));

    for(int i = 0; i < n; i++){
        array1[i] = (rand() % 500) + 1;
    }

    for(int i = 0; i < n; i++){
        array2[i] = (rand() % 5000)+ 1;
    }

    for(int i = 0; i < n; i++){
        array3[i] = (rand() % 50000)+ 1;
    }
    clock_t start, end;
    // Testing algorithm1
    start = clock();
    insertionSort(array1, n);
    end = clock();
    double time_taken_alg1 = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Insertion sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg1, n);

    start = clock();
    insertionSort(array2, n*10);
    end = clock();
    time_taken_alg1 = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Insertion sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg1, n*10);

    start = clock();
    insertionSort(array3, n*100);
    end = clock();
    time_taken_alg1 = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Insertion sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg1, n*100);

    for(int i = 0; i<n; i++){
        printf("%d\n", array1[i]);
    }

    for(int i = 0; i<(n*10); i++){
        printf("%d\n", array2[i]);
    }

    for(int i = 0; i<(n*100); i++){
        printf("%d\n", array3[i]);
    }




    for(int i = 0; i < n; i++){
        array1[i] = (rand() % 500)+ 1;
    }

    for(int i = 0; i < n; i++){
        array2[i] = (rand() % 5000)+ 1;
    }

    for(int i = 0; i < n; i++){
        array3[i] = (rand() % 50000)+ 1;
    }

    // Testing algorithm2
       start = clock();
    bubbleSort(array1, n);
    end = clock();
    double time_taken_alg2 = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Insertion sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg2, n);

    start = clock();
    bubbleSort(array2, n*10);
    end = clock();
    time_taken_alg2 = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Insertion sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg2, n*10);

    start = clock();
    bubbleSort(array3, n*100);
    end = clock();
    time_taken_alg2 = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Insertion sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg2, n*100);

    for(int i = 0; i<n; i++){
        printf("%d\n", array1[i]);
    }

    for(int i = 0; i<(n*10); i++){
        printf("%d\n", array2[i]);
    }

    for(int i = 0; i<(n*100); i++){
        printf("%d\n", array3[i]);
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
    printf("Insertion sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg1, n);
    printf("Insertion sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg1, n*10);
    printf("Insertion sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg1, n*100);
    printf("Insertion sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg2, n);
    printf("Insertion sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg2, n*10);
    printf("Insertion sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg2, n*100);
    //Clean up
    fclose(file);
    free(array1);
    free(array2);
    free(array3);
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
    for(int i = 0; i < m-1; i++){

        for (int j = 0; j< m-i-1; j++ ){
            index = size[j];

            if (size[j+1]<size[j]){
                size[j] = size[j+1];
                size[j+1] = index;
            }
        }

    }

}

