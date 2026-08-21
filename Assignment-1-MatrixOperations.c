#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printMat(int n, int arr[n][n]);
void add(int n, int arr[n][n], int arr2[n][n]);
void subtract(int n, int arr[n][n], int arr2[n][n]);
void multiplyMatrix(int n, int arr[n][n], int arr2[n][n]);
void displayTranspose(int n, int arr[n][n],int arr2[n][n]);

int main() {
    printf("Enter Rows and Columns for Matrices A and B: ");
    int n = 2;
    scanf("%d", &n);
    
    printf("Enter %d Elements for Matrix A: \n", (n * n));
    int num1 = 0;
    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &num1);
            a[i][j] = num1;
        }
    }
    
    printf("Enter %d Elements for Matrix B: \n", (n * n));
    int num2 = 0;
    int b[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &num2);
            b[i][j] = num2;
        }
    }

    bool flag = true;
    while(flag){
        printf("\nOperations:\n1.Addition\n2.Subtraction\n3.Print Matrices\n4.Multiplication\n5.Transpose\n6.Exit\nChoice: ");
        int choice;
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("\n\n======================================\nThe Sum of the Matrices is : \n");
                add(n, a, b);
                break;
            
            case 2:
                printf("\n\n======================================\nThe Difference of the Matrices is : \n");
                subtract(n, a, b);
                break;
                
            case 3:
                printf("\nMatrix A : \n");
                printMat(n, a); 
                printf("\nMatrix B : \n");
                printMat(n, b);
                break;
                
            case 4:
                printf("\n\n======================================\nThe Product of the Matrices is : \n");
                multiplyMatrix(n,a,b);
                break;
                
            case 5:
            	displayTranspose(n,a,b);
            	break;
                
            case 6:
                exit(0);
                break;
        }
    }
    
    return 0;
}

void add(int n, int arr[n][n], int arr2[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", (arr[i][j] + arr2[i][j]));
        }
        printf("\n");
    }
}

void subtract(int n, int arr[n][n], int arr2[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", (arr[i][j] - arr2[i][j]));
        }
        printf("\n");
    }
}

void printMat(int n, int arr[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrix(int n, int arr[n][n], int arr2[n][n]) {
    int result[n][n];
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0; 
            for (int k = 0; k < n; k++) {
                result[i][j] += arr[i][k] * arr2[k][j];
            }
        }
    }
    
    printMat(n, result);
}

void displayTranspose(int n, int arr[n][n], int arr2[n][n]){
	printf("\nTranspose of Matrix A:\n");
	for(int i = 0;i < n; i++){
		for(int j = 0; j < n; j++){
		printf("%d ", arr[j][i]);
		}
		printf("\n");
		
	}
	
	printf("\nTranspose of Matrix B:\n");
	for(int i = 0;i < n; i++){
		for(int j = 0; j < n; j++){
		printf("%d ", arr2[j][i]);
		}
		printf("\n");
		
	}
	
}

