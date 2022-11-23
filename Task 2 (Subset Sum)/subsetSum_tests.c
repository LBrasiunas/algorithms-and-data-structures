// Lukas Brasiūnas, 2110539, lukas.brasiunas@mif.stud.vu.lt

/* Iš duotų N natūrinių skaičių išrinkti M skaičių taip, kad jų suma būtų lygi S.
Vartotojas nurodo failą, iš kurio programa įveda pradinius N skaičių, bei skaičius M ir S. */

#include "subsetSum_functions.c"

int main()
{
    int n, m, s;
    char filename[] = "", extension[] = ".txt";

    printf("Enter the name of the file from which the program should gather data:\n");
    getFilename(filename, extension);
    printf("Extracting the data from the given file.\n");
    getDataFromFile(filename, &n, &m, &s);
    printf("Finding subsets which match the requirements: SUM = %d, Required amount of numbers in subset = %d\n", s, m);
	generateSubsets(arrayOfData, n, m, s);
	free(arrayOfData);
	return 0;
}
