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
    //check to see if number of arguments is correct
    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2", argc-1);
        return 1;
    }

    //checks to see if aruments are integers
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);
    //checks to see if argments are of correct value if not error
    if (num1 == 0  || num1 <= 0 || num2 == 0 || num2 <= 0){ 
        printf("Incorrect usage. The parameters you provided are not positive integers");
        return 1;
    }

    //initialize matrix
    int **matrix = (int **)malloc(num1 * sizeof(int *));
    
    //allocate place for matrix
    for (int i = 0; i < num1; i++) {
        matrix[i] = (int *)malloc(num2 * sizeof(int));
        for (int j = 0; j < num2; j++){
            matrix[i][j] = rand() % maxrand + minrand;
        }
    }

    //open file to write 
    FILE *fp = fopen("matrix.txt", "w");
    if (fp ==NULL) {
        printf ("Error opening file");
        return 1;
    }

    //write matrix in file
    for (int i = 0; i < num1; i++) {
        for (int j = 0; j < num2; j++) {
            //space after each collumn except the last
            if (j != num2 -1){
                fprintf(fp, "%d ", matrix[i][j]);
            }
            else {
                fprintf(fp, "%d", matrix[i][j]); 
            }
            
        }
        // new row for every row except the last
        if (i != num1 -1) {
            fprintf(fp, "\n");
        }
    }

    //free allocated space for matrix
    for (int i = 0 ; i < num1; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
