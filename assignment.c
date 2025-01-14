#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h> 
#include <time.h>
#include <stdlib.h>

// Main function that starts the program
int main(int argc, char *argv[]) {
    // run random number generator and generate seed with time()
    srand(time(NULL));

    // Check if number of arguments is 3 (program name + 2 arguments)
    if (argc != 3) {
        // print error message with num of arguments
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2", argc - 1);
        return 1; // Exit the program with error (return 1)
    }

    // Convert the arguments to integers (number of rows and columns)
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    // Check if rows or cols are not positive integers
    if (rows <= 0 || cols <= 0) {
        // Print an error message if they are not valid
        printf("Incorrect usage. The parameters you provided are not positive integers");
        return 1; // Exit program
    }

    // Create matrix for rows and columns that were given
    int **matrix = (int **)malloc(rows * sizeof(int *));
    // start int =0, while i<rows, increment i by 1
    for (int i = 0; i < rows; i++) {
        // memory allocation for each row
        matrix[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            // Fill with numbers between 1 and 100 (as said in readme)
            matrix[i][j] = (rand() % 100) + 1;
        }
    }

    // create matrix.txt as write-only
    FILE *file = fopen("matrix.txt", "w");
    if (!file) {
        // Print error msg if the file can not be opened
        perror("Failed to open matrix.txt");
        return 1; // Exit the program with an error
    }

    // Write the matrix to the file, row by row
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) {
            // Write the number to the position in the matrix (row + col)
            fprintf(file, "%d", matrix[i][j]);
            if (j < cols - 1) {
                // add space to separate numbers
                fprintf(file, " ");
            }
        }
        // use newline character at the end of the row to go to next row
        fprintf(file, "\n");
    }

    // close the file
    fclose(file);

    // free memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]); // free each row of the matrix
    }
    free(matrix); // Free all pointers

    return 0;
}
