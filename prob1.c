// Anthony - Uniquenes

//Group #16
//array size 10 to 100, inc 10
//values from 1600 to 16000
//run 1000 times

#include "prob1.h"

int main(int argc, char** argv){

    //Check if the program is running tests or actual data
    if(argc > 1){
        runTestCases();
        exit(0);
    }

    //Declare important values
    int upper = 16000; //16 * 10000
    int lower = 1600; //16 * 1000
    int* array = malloc(sizeof(int) * upper); //Declare a single array for use, the range to be used is specified




    //-----------LOWER M (1600)----------------
    FILE* file = fopen("prob1outLower.csv", "w");

    //Confirm file exists
    if(file == NULL){
        printf("Error opening lower file!\n");
        exit(1);
    }

    //Add header to file
    fprintf(file, "Iteration Number,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,\n",
    (lower/10) * 1, (lower/10) * 2, (lower/10) * 3, (lower/10) * 4, (lower/10) * 5, (lower/10) * 6, (lower/10) * 7, (lower/10) * 8, (lower/10) * 9, (lower/10) * 10);

    //Repeat for many tests
    for (int i = 1; i <= NUM_OF_ITERATIONS; i++){
        fprintf(file, "%d,", i); //add iteration number

        //Repeat for different array sizes
        for (int j = lower/10; j <= lower; j+=lower/10){

            //Fill array with new values
            for (int k = 0; k < j; k++){
                array[k] = rand() % lower;
            }

            //Add data to file
            int matchFound = 0;
            fprintf(file, "%d,", uniqueElementAlg(array, j, &matchFound));
        }

        //Add newline to the end of the row
        fprintf(file, "\n");
    }

    //Close file
    fclose(file);

    printf("Data written to prob1outLower.csv\n");
    //-------------END OF LOWER-----------


    //------------------UPPER M (16000)-----------
    file = fopen("prob1outUpper.csv", "w");

    //Confirm file exists
    if(file == NULL){
        printf("Error opening upper file!\n");
        exit(1);
    }

    //Add header to file
    fprintf(file, "Iteration Number,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,\n",
    (upper/10) * 1, (upper/10) * 2, (upper/10) * 3, (upper/10) * 4, (upper/10) * 5, (upper/10) * 6, (upper/10) * 7, (upper/10) * 8, (upper/10) * 9, (upper/10) * 10);

    //Repeat for many tests
    for (int i = 1; i <= NUM_OF_ITERATIONS; i++){
        fprintf(file, "%d,", i); //add iteration number

        //Repeat for different array sizes
        for (int j = upper/10; j <= upper; j+=upper/10){

            //Fill array with new values
            for (int k = 0; k < j; k++){
                array[k] = rand() % upper;
            }

            //Add data to file
            int matchFound = 0;
            fprintf(file, "%d,", uniqueElementAlg(array, j, &matchFound));
        }

        //Add newline to the row
        fprintf(file, "\n");
    }
    
    //close file
    fclose(file);

    //Clean up
    free(array);

    printf("Data written to prob1outUpper.csv\n");

    return 0;
}

int uniqueElementAlg(int* array, int arraySize, int* matchFound){
    int numOfComparisons = 0;

    for (int i = 0; i < arraySize-1; i++){
        for (int j = i+1; j < arraySize; j++){
            numOfComparisons++;
            if(array[i] == array[j]){
                *matchFound = 1;
                return numOfComparisons;
            }
        }
    }

    *matchFound = 0;
    return numOfComparisons;
}

void runTestCases(){
    printf("argc > 1, running problem 1 test results: (0 = failure)\n");

    //Setup arrays
    int* testData = (int*) malloc(10 * sizeof(int));
    int expectedResult = 0;
    int actualResult = 0;

    //TEST 1
    //All elements unique
    expectedResult = 0;
    for (int i = 0; i < 10; i++){
        testData[i] = i;
    }
    uniqueElementAlg(testData, 10, &actualResult);
    printf("Test 1 result: %d\n", expectedResult == actualResult);

    //TEST 2
    //[0] == [1]
    expectedResult = 1;
    for (int i = 0; i < 10; i++){
        testData[i] = i;
    }
    testData[1] = 0;
    uniqueElementAlg(testData, 10, &actualResult);
    printf("Test 2 result: %d\n", expectedResult == actualResult);

    //TEST 3
    //[0] == [9]
    expectedResult = 1;
    for (int i = 0; i < 10; i++){
        testData[i] = i;
    }
    testData[9] = 0;
    uniqueElementAlg(testData, 10, &actualResult);
    printf("Test 3 result: %d\n", expectedResult == actualResult);

    //TEST 4
    //[8] == [9]
    expectedResult = 1;
    for (int i = 0; i < 10; i++){
        testData[i] = i;
    }
    testData[9] = 8;
    uniqueElementAlg(testData, 10, &actualResult);
    printf("Test 4 result: %d\n", expectedResult == actualResult);

    //TEST 5
    //All values are the same
    expectedResult = 1;
    for (int i = 0; i < 10; i++){
        testData[i] = 3;
    }
    uniqueElementAlg(testData, 10, &actualResult);
    printf("Test 5 result: %d\n", expectedResult == actualResult);

    free(testData);
}