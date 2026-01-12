#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ================= GLOBAL STATE ================= */
int *arr = NULL;
int n = 0;

/* ================= UTILITY ================= */

void freeArray() {
    if (arr != NULL) {
        free(arr);
        arr = NULL;
        n = 0;
    }
}

int isArrayValid() {
    if (arr == NULL || n <= 0) {
        printf("Array not initialized!\n");
        return 0;
    }
    return 1;
}

void copyArray(int *src, int *dest, int size) {
    for (int i = 0; i < size; i++)
        dest[i] = src[i];
}

void displayArray() {
    if (!isArrayValid()) return;
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* ================= INPUT ================= */

void inputArrayManual() {
    freeArray();
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size!\n");
        return;
    }

    arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

void inputArrayRandom() {
    freeArray();
    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 1000;
}

void inputArrayWorstCase() {
    freeArray();
    printf("Enter number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = n - i;  // descending order
}

/* ================= SORTING ================= */

void bubbleSort(int *a, int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

void insertionSort(int *a, int size) {
    for (int i = 1; i < size; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void merge(int *a, int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int i = 0; i < n2; i++) R[i] = a[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    free(L); free(R);
}

void mergeSort(int *a, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int partition(int *a, int low, int high) {
    int pivot = a[high], i = low - 1;
    for (int j = low; j < high; j++)
        if (a[j] < pivot) {
            i++;
            int t = a[i]; a[i] = a[j]; a[j] = t;
        }
    int t = a[i + 1]; a[i + 1] = a[high]; a[high] = t;
    return i + 1;
}

void quickSort(int *a, int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

/* ================= SEARCH ================= */

void linearSearch() {
    if (!isArrayValid()) return;
    int key;
    printf("Enter key: ");
    scanf("%d", &key);

    for (int i = 0; i < n; i++)
        if (arr[i] == key) {
            printf("Found at index %d\n", i);
            return;
        }
    printf("Not found\n");
}

/* ================= ANALYSIS ================= */

void runComparison() {
    if (!isArrayValid()) return;

    int *temp = malloc(n * sizeof(int));
    clock_t s, e;

    printf("\nAlgorithm       Time(s)     Time Complexity      Space\n");
    printf("--------------------------------------------------------\n");

    copyArray(arr, temp, n);
    s = clock(); bubbleSort(temp, n); e = clock();
    printf("Bubble Sort     %.6f     O(n^2)               O(1)\n",
           (double)(e - s) / CLOCKS_PER_SEC);

    copyArray(arr, temp, n);
    s = clock(); insertionSort(temp, n); e = clock();
    printf("Insertion Sort  %.6f     O(n^2)               O(1)\n",
           (double)(e - s) / CLOCKS_PER_SEC);

    copyArray(arr, temp, n);
    s = clock(); mergeSort(temp, 0, n - 1); e = clock();
    printf("Merge Sort      %.6f     O(n log n)           O(n)\n",
           (double)(e - s) / CLOCKS_PER_SEC);

    copyArray(arr, temp, n);
    s = clock(); quickSort(temp, 0, n - 1); e = clock();
    printf("Quick Sort      %.6f     O(n log n)*          O(n) worst\n",
           (double)(e - s) / CLOCKS_PER_SEC);

    free(temp);
}

/* ================= MAIN ================= */

int main() {
    int ch;
    while (1) {
        printf("\n1.Manual Input\n2.Random Input\n3.Worst Case Input\n");
        printf("4.Display\n5.Compare Sorts\n6.Linear Search\n7.Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: inputArrayManual(); break;
            case 2: inputArrayRandom(); break;
            case 3: inputArrayWorstCase(); break;
            case 4: displayArray(); break;
            case 5: runComparison(); break;
            case 6: linearSearch(); break;
            case 7: freeArray(); exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
