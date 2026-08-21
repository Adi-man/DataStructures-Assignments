#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

typedef struct {
    int row;
    int col;
    int value;
} Term;


void createSparse(Term sparse[]);
void displaySparse(Term sparse[]);
void simpleTranspose(Term a[], Term b[]);
void fastTranspose(Term a[], Term b[]);

int main() {
    Term original[MAX_TERMS], result[MAX_TERMS];
    int choice;
    int matrixCreated = 0; // Guard flag to prevent processing empty matrices

    while (1) {
        printf("\n=================================");
        printf("\n   SPARSE MATRIX OPERATIONS");
        printf("\n=================================");
        printf("\n1. Create Sparse Matrix");
        printf("\n2. Display Sparse Matrix");
        printf("\n3. Perform Simple Transpose");
        printf("\n4. Perform Fast Transpose");
        printf("\n5. Exit");
        printf("\n=================================");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createSparse(original);
                matrixCreated = 1;
                break;

            case 2:
                if (!matrixCreated) {
                    printf("\nPlease create a matrix first using option 1.\n");
                } else {
                    printf("\n--- Current Sparse Matrix ---");
                    displaySparse(original);
                }
                break;

            case 3:
                if (!matrixCreated) {
                    printf("\nNo matrix available to transpose. Use option 1.\n");
                } else {
                    simpleTranspose(original, result);
                    printf("\n--- Transposed Matrix (Simple Transpose) ---");
                    displaySparse(result);
                }
                break;

            case 4:
                if (!matrixCreated) {
                    printf("\nNo matrix available to transpose. Use option 1.\n");
                } else {
                    fastTranspose(original, result);
                    printf("\n--- Transposed Matrix (Fast Transpose) ---");
                    displaySparse(result);
                }
                break;

            case 5:
                printf("\nExiting program. Goodbye!\n");
                exit(0);

            default:
                printf("\nInvalid choice! Please select an option between 1 and 5.\n");
        }
    }
    return 0;
}

// Reads standard dense matrix and converts to 3-tuple format
void createSparse(Term sparse[]) {
    int r, c, val, k = 1;

    printf("\nEnter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    sparse[0].row = r;
    sparse[0].col = c;

    printf("Enter elements of the matrix row by row:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &val);
            if (val != 0) {
                if (k >= MAX_TERMS) {
                    printf("\nOverflow! Reached max element capacity (%d).\n", MAX_TERMS - 1);
                    sparse[0].value = k - 1;
                    return;
                }
                sparse[k].row = i;
                sparse[k].col = j;
                sparse[k].value = val;
                k++;
            }
        }
    }
    sparse[0].value = k - 1; 
    printf("\nSparse Matrix created successfully with %d non-zero elements.\n", sparse[0].value);
}


void displaySparse(Term sparse[]) {
    int total_elements = sparse[0].value;
    printf("\nRow\tColumn\tValue\n");
    printf("------------------------\n");
    printf("%d\t%d\t%d\n", sparse[0].row, sparse[0].col, sparse[0].value);
    printf("------------------------\n");
    for (int i = 1; i <= total_elements; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

// Simple Transpose 
void simpleTranspose(Term a[], Term b[]) {
    int n = a[0].value; 
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = n;

    if (n > 0) {
        int current_b = 1;
        for (int i = 0; i < a[0].col; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[j].col == i) {
                    b[current_b].row = a[j].col;
                    b[current_b].col = a[j].row;
                    b[current_b].value = a[j].value;
                    current_b++;
                }
            }
        }
    }
}

// Fast Transpose 
void fastTranspose(Term a[], Term b[]) {
    int numCols = a[0].col;
    int numTerms = a[0].value;
    
    b[0].row = numCols;
    b[0].col = a[0].row;
    b[0].value = numTerms;

    if (numTerms > 0) {
        int rowTerms[MAX_TERMS] = {0};
        int startingPos[MAX_TERMS];

        for (int i = 1; i <= numTerms; i++) {
            rowTerms[a[i].col]++;
        }

        startingPos[0] = 1;
        for (int i = 1; i < numCols; i++) {
            startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
        }


        for (int i = 1; i <= numTerms; i++) {
            int j = startingPos[a[i].col]++;
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
        }
    }
}

