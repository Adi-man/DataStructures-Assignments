#include <stdio.h>

void bucketSort(float arr[], int n) {
    float buckets[10][n];
    int bucketSizes[10] = {0};

    for (int i = 0; i < n; i++) {
        int index = arr[i] / 10;
        if (index >= 10) {
            index = 9;
        }
        buckets[index][bucketSizes[index]] = arr[i];
        bucketSizes[index]++;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < bucketSizes[i]; j++) {
            float key = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > key) {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = key;
        }
    }

    int idx = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[idx] = buckets[i][j];
            idx++;
        }
    }
}

void displayTopFive(float arr[], int n) {
    printf("\nTop 5 Scores:\n");
    int count = 0;
    for (int i = n - 1; i >= 0 && count < 5; i--) {
        printf("%d. %.2f%%\n", count + 1, arr[i]);
        count++;
    }
}

int main() {
    int n;

    printf("Enter number of students: ");
    scanf("%d", &n);

    float arr[n];
    printf("Enter percentages:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        scanf("%f", &arr[i]);
    }

    bucketSort(arr, n);
    displayTopFive(arr, n);

    return 0;
}