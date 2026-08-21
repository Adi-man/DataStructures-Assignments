#include <stdio.h>
#include <string.h>


struct Student {
    int roll_no;
    char name[50];
    float marks;
};


void displayDatabase(struct Student db[], int n);
void linearSearch(struct Student db[], int n, int key);
void binarySearch(struct Student db[], int n, int key);
void insertionSort(struct Student db[], int n);
void selectionSort(struct Student db[], int n);
void shellSort(struct Student db[], int n);
void swap(struct Student *a, struct Student *b);

int main() {
    int n, choice, key;
    
    printf("Enter the number of students: ");
    scanf("%d", &n);
    
    struct Student db[n];
    
      for (int i = 0; i < n; i++) {
        printf("\nEnter details for Student %d\n", i + 1);
        printf("Roll No: ");
        scanf("%d", &db[i].roll_no);
        printf("Name: ");
        scanf(" %[^\n]s", db[i].name); // Reads string with spaces
        printf("Marks: ");
        scanf("%f", &db[i].marks);
    }
    
    do {
        printf("\n--- Student Database Menu ---\n");
        printf("1. Display Database\n");
        printf("2. Linear Search (by Roll No)\n");
        printf("3. Binary Search (by Roll No - Ensure data is sorted first)\n");
        printf("4. Insertion Sort (by Roll No)\n");
        printf("5. Selection Sort (by Roll No)\n");
        printf("6. Shell Sort (by Roll No)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayDatabase(db, n);
                break;
            case 2:
                printf("Enter Roll No to search: ");
                scanf("%d", &key);
                linearSearch(db, n, key);
                break;
            case 3:
                printf("Enter Roll No to search: ");
                scanf("%d", &key);
                binarySearch(db, n, key);
                break;
            case 4:
                insertionSort(db, n);
                printf("Database sorted using Insertion Sort.\n");
                displayDatabase(db, n);
                break;
            case 5:
                selectionSort(db, n);
                printf("Database sorted using Selection Sort.\n");
                displayDatabase(db, n);
                break;
            case 6:
                shellSort(db, n);
                printf("Database sorted using Shell Sort.\n");
                displayDatabase(db, n);
                break;
            case 7:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);
    
    return 0;
}

void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}
void displayDatabase(struct Student db[], int n) {
    printf("\nRoll No\t|\tName\t\t|\tMarks\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t|\t%-15s\t|\t%.2f\n", db[i].roll_no, db[i].name, db[i].marks);
    }
}


void linearSearch(struct Student db[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (db[i].roll_no == key) {
            printf("\nStudent Found!\n");
            printf("Name: %s, Marks: %.2f\n", db[i].name, db[i].marks);
            return;
        }
    }
    printf("\nStudent with Roll No %d not found.\n", key);
}

void binarySearch(struct Student db[], int n, int key) {
    int low = 0, high = n - 1, mid;
    
    while (low <= high) {
        mid = low + (high - low) / 2;
        
        if (db[mid].roll_no == key) {
            printf("\nStudent Found!\n");
            printf("Name: %s, Marks: %.2f\n", db[mid].name, db[mid].marks);
            return;
        }
        
        if (db[mid].roll_no < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("\nStudent with Roll No %d not found. (Make sure the database is sorted!)\n", key);
}


void insertionSort(struct Student db[], int n) {
    for (int i = 1; i < n; i++) {
        struct Student key = db[i];
        int j = i - 1;
        
        while (j >= 0 && db[j].roll_no > key.roll_no) {
            db[j + 1] = db[j];
            j = j - 1;
        }
        db[j + 1] = key;
    }
}

void selectionSort(struct Student db[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (db[j].roll_no < db[min_idx].roll_no) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&db[min_idx], &db[i]);
        }
    }
}

void shellSort(struct Student db[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            struct Student temp = db[i];
            int j;            
            for (j = i; j >= gap && db[j - gap].roll_no > temp.roll_no; j -= gap) {
                db[j] = db[j - gap];
            }
            db[j] = temp;
        }
    }
}
