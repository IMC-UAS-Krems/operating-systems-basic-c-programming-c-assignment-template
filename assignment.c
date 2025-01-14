#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function to check if a string is a positive integer
int is_positive_integer(const char *str) {
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    // Validate the number of arguments
    if (argc != 3) {
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n", argc - 1);
        return 1;
    }

    // Check if both are positive integers
    if (!is_positive_integer(argv[1]) || !is_positive_integer(argv[2])) {
        printf("Incorrect usage. The parameters you provided are not positive integers\n");
        return 1;
    }

    // Convert arguments to integers
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    if (rows <= 0 || cols <= 0) {
        printf("Incorrect usage. The parameters you provided are not positive integers\n");
        return 1;
    }

    // Dynamically allocate the matrix
    int **matrix = (int **)malloc(rows * sizeof(int *));
    if (matrix == NULL) {
        perror("Failed to allocate memory for rows");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            perror("Failed to allocate memory for columns");
            return 1;
        }
    }

    // Initialize the random number generator
    srand(time(NULL));

    // Populate the matrix with random integers between 1 and 100
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (rand() % 100) + 1;
        }
    }

    // Write the matrix to "matrix.txt"
    FILE *file = fopen("matrix.txt", "w");
    if (file == NULL) {
        perror("Failed to open file for writing");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fprintf(file, "%d", matrix[i][j]);
            if (j < cols - 1) {
                fprintf(file, " ");  // Add space between columns
            }
        }
        fprintf(file, "\n");  // Add a newline at the end of each row
    }

    fclose(file);

    // Free the allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    printf("Matrix generated and saved to matrix.txt\n");

    return 0;
}
