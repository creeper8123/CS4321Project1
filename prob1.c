// Anthony - Uniquenes

//Group #16
//m values from 1600 to 16000
//run 1000 times

#include "prob1.h"

/*
Author: Anthony Martin

Cost: O(n^4)

Param (int argc): The number of arguments (including the program itself). Any additional arguemnts will run test cases instead.
Param (char** argv): The arguments passed to the program (the first argument is the name of the binary)

Return (int): Returns 0 if the program exited with no errors

Description: 
    If argc > 1, it will run test cases and skip most of the functon.

    Otherwise, it will take an array of n size (from 0.1m to m, inc. 0.1m), based on the lower m value.

    This array will be randomized and passed to uniqueElementAlg(), where the number of comparisons
    will be stored in the file prob1outLower.csv where it can be used in excel directly.

    The above process is repeated 1000 times, and added to the same file.

    The entire above process is repeated for the upper m value, and the results are stored in prob1outUpper.csv.
*/
int main(int argc, char** argv){
    /* DOCUMETING MAIN CLASS    
    1.) The name of the algorithim is called Brute Force
    2.)Anthony worked on this part, his teammates are Collin, Rohith, and Johnathan
    3.)We finished this by 10-23
    4.) You run this program by inputing ./prob1 in the command terminal.     
    */

    /* DOCUMENTING INPUT CASES
    1.)The input type is int 
    2.)The Author of these input cases is Anthony
    3.)Pseudo Code
        Brute Force:
            for(i from 0 to n-2){ //if n-1, would compare with itself
		        for(j from i+1 to n-1){
			        if(A[i] == A[j]){
				        return false;
			}
		}
	}
	return true;
    4.)You run this program by inputing .prob1 in the command terminal as we have test cases implemented in the code.
    */



    //Check if the program is running tests or actual data
    if(argc > 1){
        runTestCases();
        exit(0);
    }

    int* array = malloc(sizeof(int) * upper); //Declare a single array for use, the range to be used is specified



    //-----------LOWER M (1600)----------------
    //Create a file to store all the data in a ready to use formal
    FILE* file = fopen("prob1outLower.csv", "w");

    //If the file does not exist, exit the program
    if(file == NULL){
        printf("Error opening lower file!\n");
        exit(1);
    }

    //Add header to file for the size of the array
    fprintf(file, "Iteration Number,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,\n",
    (lower/10) * 1, (lower/10) * 2, (lower/10) * 3, (lower/10) * 4, (lower/10) * 5, (lower/10) * 6, (lower/10) * 7, (lower/10) * 8, (lower/10) * 9, (lower/10) * 10);

    //Repeat multiple times for an average
    for (int i = 1; i <= NUM_OF_ITERATIONS; i++){
        fprintf(file, "%d,", i); //add iteration number

        //Repeat the iterations for different n sizes from [lower/10...lower] in incriments of lower/10
        for (int j = lower/10; j <= lower; j+=lower/10){

            //Fill array with new random values [1...m]
            for (int k = 0; k < j; k++){
                array[k] = rand() % lower;
            }

            //Call the unique element algorithm and add the number of comparisons found to the file
            int matchFound = 0; //Used in text cases, not needed in the final results
            fprintf(file, "%d,", uniqueElementAlg(array, j, &matchFound));
        }

        //Add newline to the end of the row
        fprintf(file, "\n");
    }

    //Close the file after all the data has been added
    fclose(file);

    //Print that the file is closed and ready to use elsewhere
    printf("Data written to prob1outLower.csv\n");
    //-------------END OF LOWER-----------


    //------------------UPPER M (16000)-----------
    //Create a file to store all the data in a ready to use formal
    FILE* file = fopen("prob1outLower.csv", "w");

    //If the file does not exist, exit the program
    if(file == NULL){
        printf("Error opening lower file!\n");
        exit(1);
    }

    //Add header to file for the size of the array
    fprintf(file, "Iteration Number,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,n=%d,\n",
    (upper/10) * 1, (upper/10) * 2, (upper/10) * 3, (upper/10) * 4, (upper/10) * 5, (upper/10) * 6, (upper/10) * 7, (upper/10) * 8, (upper/10) * 9, (upper/10) * 10);

    //Repeat multiple times for an average
    for (int i = 1; i <= NUM_OF_ITERATIONS; i++){
        fprintf(file, "%d,", i); //add iteration number

        //Repeat the iterations for different n sizes from [lower/10...lower] in incriments of lower/10
        for (int j = upper/10; j <= upper; j+=upper/10){

            //Fill array with new random values [1...m]
            for (int k = 0; k < j; k++){
                array[k] = rand() % upper;
            }

            //Call the unique element algorithm and add the number of comparisons found to the file
            int matchFound = 0; //Used in text cases, not needed in the final results
            fprintf(file, "%d,", uniqueElementAlg(array, j, &matchFound));
        }

        //Add newline to the end of the row
        fprintf(file, "\n");
    }

    //Close the file after all the data has been added
    fclose(file);

    //Print that the file is closed and ready to use elsewhere
    printf("Data written to prob1outUpper.csv\n");
    //-------------END OF UPPER-----------

    //Free the array
    free(array);

    return 0;
}



/*
Author: Anthony Martin

Cost: O(n^2)

Param (int* array): The pointer to the array containing the data being checked
Param (int arraySize): The size of the array being checked
Param(int* matchFound): A pointer containing 1 if a match was found, 0 otherwise.

Return (int): Returns the number of times the if condition was run

Description: 
    Checks if an array of a given size contains the same value more than once.
    Counts how many elements were checked against eachother, and returns that number.
    Sets matchFound to 1 if a match was found. This is not the return as that's not the value that's being cared about.
*/
int uniqueElementAlg(int* array, int arraySize, int* matchFound){
    int numOfComparisons = 0;

    for (int i = 0; i < arraySize-1; i++){ //Iterate through e
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

/*
Author: Anthony Martin

Cost: O(n^3)

Description: 
    Checks if an array of a given size contains the same value more than once.
    Counts how many elements were checked against eachother, and returns that number.
    Sets matchFound to 1 if a match was found. This is not the return as that's not the value that's being cared about.
*/
void runTestCases(){
    /*
    EXAMPLE TEST:

    //TEST ## //====Test number
    //Breif description of the data being tested.

    expectedResult = 0; //=====Set the value expected (0 is no match found)

    
    for (int i = 0; i < 10; i++){//=====Reset the initial value of the array to 
        testData[i] = i;
    }
    testData[#] = #; //=====Set a unique element to a unique value
    uniqueElementAlg(testData, 10, &actualResult); //=====Run the unique element algorithm, storing if there was a match in actualValue
    printf("Test 1 result: %d\n", expectedResult == actualResult); //Print the results of the test to the console
    */

    //Print that tests are being run
    printf("argc > 1, running problem 1 test results: (0 = test failed)\n");

    //Setup array and comparison values
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


    //Tests are finished, free the test array
    free(testData);

    //Print that the tests are finished running
    printf("Tests finished running.\n");
}