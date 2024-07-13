#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int mid, int low, int high);
void mergeSort(int A[], int low, int high);

int main() {
    int n;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the Elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted Elements:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
}

void merge(int a[], int mid, int low, int high) {
    int i, j, k, b[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high) {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++) {
        a[i] = b[i];
    }
}

void mergeSort(int A[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}
