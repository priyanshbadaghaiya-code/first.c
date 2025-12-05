//Left rotation of 
#include <stdio.h>
void Left_rotation(int a[], int n, int k)
{
    int temp;
    while (k > 0)
    {
        temp = a[0];  // store first element
        for (int i = 0; i < n - 1; i++)
        {
            a[i] = a[i + 1];  // shift elements left
        }
        a[n - 1] = temp;  // move first element to last
        k--;
    }
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 2;  // number of rotations

    Left_rotation(a, n, k);
    print(a, n);

    return 0;
}
