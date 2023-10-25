#include "prob2.h"
// Collin - Insertion
// Johnathan - Bubble


int main(int argc, char** argv){
/* MAIN CLASS DOCUMENTATION
1.) There are two algorithims being used and they are insertionSort and bubbleSort.
2.) The people who worked on algorithims are Collin and Johnathan.
3.) We finished this program by 10-23.
4.) You run the program by typing in ./prob2 in the command line or in terminal
*/

/* INPUT CASES DOCUMENTATION
1.) The input type is integers (int)
2.)The Authors of these input cases is Collin and Johnathan.  (Most of it was Collin as Johnathan had help from him when making
these test cases.)
3.)Insertion Sort:
    for(i from 1 to n){
        key = A[i]
        j = i-1;
        while (j>=0 &&A[j] > key){
            swap(A[j],A[j+1]);
            j= j-1 ;
        }
        A[j+1] = key;
} 


Bubble Sort:
for( i from 0 to m - 1){
	for(j from 0 to m - i - 1){
		Index = A[j]
		if(A[j+1] < A[j]){
		    swap(A[j],A[j+1]);
        }   
    }
}

4.) You run these input cases by typing ./prob2 as we have implmented the input cases
*/


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
    printf("Bubble sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg2, n);

    start = clock();
    bubbleSort(array2, n*10);
    end = clock();
    time_taken_alg2 = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Bubble sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg2, n*10);

    start = clock();
    bubbleSort(array3, n*100);
    end = clock();
    time_taken_alg2 = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Bubble sort runs in: %.8lf seconds for n = %d\n",
    time_taken_alg2, n*100);

    for(int i = 0; i<n; i++){
        printf("%d\n", array1[i]);
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
   /* printf("Insertion sort runs in: %.8lf seconds for n = %d\n",
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
    time_taken_alg2, n*100);*/
    //Clean up
    fclose(file);
    free(array1);
    free(array2);
    free(array3);
    return 0;

}


void insertionSort(int array[], int n){
/*
1.) Collin worked on this part of the program. 
2.) The cost of this method is O(n^2).
3.) How this function works is that you compare the numbers starting from the index and check to see if the values in the array 
are smaller or greater than the current index.  If it is bigger we keep the number where it is, but if it is smaller
we move the current number after the number we just compared with.  
*/
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
    /*
    1.) Johnathan worked on this function
    2.) The cost of this method is O(n^2).
    3.) How this function works is use for loops to compare elements in an array so we can find the largest number first.  
    It starts at the beginning of the array and then compares the first two numbers to see which one is biggee.  
    The bigger number will be compared with the next number in the array and it repeats this until we get our largest number 
    to the end.  
    */
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

