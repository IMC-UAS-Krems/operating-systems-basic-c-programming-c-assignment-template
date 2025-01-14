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

    int random_number = (rand() % (maxrand - minrand + 1)) + minrand;

    // WRITE YOUR CODE HERE
    
    // 1. Check if Number of arguments is == 2
    if (argc != 3) {
      printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2\n",argc-1);
      return 1;
    }

  // 2. Check if the Arguments are > 0

    for (int i = 1; i < argc; i++) {
      int num = atoi(argv[i]);
      if (num <= 0) {
          printf("Incorrect usage. The parameters you provided are not positive integers\n");
          return 1;
      }
      
    }

  // 3. Create Matrix

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    
    int **matrix = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if (matrix[i] == NULL) {
            for (int j = 0; j < i; j++) {
            }
            return 1;
        }
    }

    // Fill the matrix with random numbers between 1 and 100
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (rand() % (maxrand - minrand + 1)) + minrand;
        }
    }
    
  // 4. Create Matrix.txt

    FILE *pFile = NULL;
    pFile = fopen("matrix.txt", "w");

    for (int i = 0; i < rows; i++) {
          for (int j = 0; j < cols; j++) {
              fprintf(pFile,"%d", matrix[i][j]);
              if (j < cols - 1) {
                  fprintf(pFile," ");
              }
          }
          fprintf(pFile,"\n");
      }

    fclose(pFile);

  return 0;
}
