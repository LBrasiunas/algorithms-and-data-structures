// Lukas Brasiūnas, 2110539, lukas.brasiunas@mif.stud.vu.lt

#include "subsetSum_desc.h"

// Function responsible for getting a filename that exists in the directory
void getFilename(char filename[], char fileExtention[])
{
    while(1)
    {
        scanf("%19s", filename);
        // Checking if the required file extension exists in the input
        if(strstr(filename, fileExtention))
            return;
        else
            printf("Wrong file name. Try again.\n");
    }
}

// Function responsible for extracting all information from a given file
void getDataFromFile(char filename[], int* n, int* m, int* s)
{
    FILE* fp;
    fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error! Cannot open the specified file.\n");
        return;
    }
    fscanf(fp, "%d%d%d", n, m, s);

    // Allocating memory for the array which contains all of the numbers used for creating the subsets
    arrayOfData = (int*)malloc((int)n * sizeof(int));

    for(int i = 0; i < *n; ++i)
    {
        fscanf(fp, "%d", &arrayOfData[i]);
    }
    fclose(fp);
}

// Function responsible for printing out the data in the given array on screen
void printSubset(int array[], int sizeOfArray)
{
    for(int i = 0; i < sizeOfArray; ++i)
    {
        printf("%*d", 4, array[i]);
    }
    printf("\n");
}

// Function which uses Backtracking to find the data which matches the given requirements
void subsetSum(int dataArray[], int tupleArray[], int dataSize, int tupleSize, int sumSoFar,
            int nodeCount, int targetSum, int reqNumbersInSubset)
{
    // Check if the current subset sum and the amount of numbers in the subset are equal
    // to the requirements (target sum and numbers in subset)
    if(targetSum == sumSoFar && tupleSize == reqNumbersInSubset)
    {
        // Calling the printSubset function
        printSubset(tupleArray, tupleSize);
        // Remove the previously added number and continue the program
        subsetSum(dataArray, tupleArray, dataSize, tupleSize - 1, sumSoFar - dataArray[nodeCount],
                  nodeCount + 1, targetSum, reqNumbersInSubset);
        return;
    }
    else
    {
        // A cycle responsible for filling the tuple array with numbers from the data array
        for(int i = nodeCount; i < dataSize; ++i)
        {
            tupleArray[tupleSize] = dataArray[i];
            // Calling the function to get the next number in the data array as well as increasing the current sum
            subsetSum(dataArray, tupleArray, dataSize, tupleSize + 1, sumSoFar + dataArray[i],
                       i + 1, targetSum, reqNumbersInSubset);
        }
    }
}

// An additional function to the main subsetSum function
void generateSubsets(int array[], int arraySize, int maxNumbers, int targetSum)
{
    // Checking if it is really possible to find the data with the already given requirements
    if(arraySize < maxNumbers)
    {
        printf("M is bigger than N! Exiting the program...\n");
        return;
    }
    // Creating a dynamic tuple array
    int* tuple = (int*)malloc(arraySize * sizeof(int));

    // Calling the main function responsible for finding the subsets
    subsetSum(array, tuple, arraySize, 0, 0, 0, targetSum, maxNumbers);

    // Freeing the tuple array used memory
    free(tuple);
}
