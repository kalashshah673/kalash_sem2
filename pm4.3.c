#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    printf("Enter size of first array: ");
    scanf("%d", &n);

    printf("Enter size of second array: ");
    scanf("%d", &m);

    int *arr1 = (int*)malloc(n * sizeof(int));
    int *arr2 = (int*)malloc(m * sizeof(int));
    int *merged = (int*)malloc((n + m) * sizeof(int));

    printf("Enter elements of first sorted array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter elements of second sorted array:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d", &arr2[i]);
    }

    int i = 0, j = 0, k = 0;

    while(i < n && j < m) {
        if(arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    while(i < n) {
        merged[k++] = arr1[i++];
    }

    while(j < m) {
        merged[k++] = arr2[j++];
    }

    printf("Merged sorted array:\n");
    for(int i = 0; i < n + m; i++) {
        printf("%d ", merged[i]);
    }


    free(arr1);
    free(arr2);
    free(merged);

    return 0;
}
