#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;
    // WRITE YOUR CODE HERE
    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc-1);
        return 0;
    }
    for (int i = 1; i < argc; i++){
        if (atoi(argv[i]) < 0) {
            printf("Incorrect usage. The parameters you provided are not positive integers");
            return 0;
        }
    }
    int nrows = atoi(argv[1]);
    int ncols = atoi(argv[2]);

    // int matrix[nrows][ncols];

    int **matrix = malloc(nrows * sizeof(int *));
    for (int i = 0; i < nrows; i++) {
        matrix[i] = malloc(ncols * sizeof(int));
    }

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            matrix[i][j] = rand() % (maxrand - minrand + 1) +
            minrand;
        }
    }
    FILE *pFile;
    pFile = fopen("matrix.txt", "w");
    if (pFile == NULL) {
        printf("Failed to open file");
        return -1;
    }
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            fprintf(pFile, "%3d", matrix[i][j]);
            if (j < ncols - 1) {
                fprintf(pFile, " ");
            }
        }
        if (i < nrows - 1) {
            fprintf(pFile, "\n"); 
        };
    }
    fprintf(pFile, ("\r"));
    fclose(pFile);
    return 0;
}
