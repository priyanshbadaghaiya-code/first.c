#include<stdio.h>

int main() {
    int a[100], n, index;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the index number to delete element: ");
    scanf("%d", &index);

    if(index < 0 || index >= n) {
        printf("Please enter a valid index number\n");
    } else {
        // shift elements left
        for(int i = index; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--;  // reduce size
    }

    printf("Array after deletion:\n");
    for(int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
 