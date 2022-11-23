// Lukas Brasiūnas, 2110539, lukas.brasiunas@mif.stud.vu.lt

#ifndef SUBSETSUM_DESC_H_INCLUDED
#define SUBSETSUM_DESC_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dynamic array for storing the data from the file
int* arrayOfData;

// Functions:
// Function responsible for getting a filename that exists in the directory
void getFilename(char filename[], char fileExtention[]);
// Function responsible for extracting all information from a given file
void getDataFromFile(char filename[], int* n, int* m, int* s);
// Function responsible for printing out the data in the given array on screen
void printSubset(int array[], int sizeOfArray);
// Function which uses Backtracking to find the data which matches the given requirements
void subsetSum(int dataArray[], int tupleArray[], int dataSize, int tupleSize, int sumSoFar,
            int nodeCount, int targetSum, int reqNumbersInSubset);
// An additional function to the main subsetSum function
void generateSubsets(int array[], int arraySize, int maxNumbers, int targetSum);

#endif // SUBSETSUM_DESC_H_INCLUDED
