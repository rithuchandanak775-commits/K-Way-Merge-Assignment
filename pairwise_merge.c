#include <stdio.h>

int comparisons = 0;

void merge(int a[], int n, int b[], int m, int result[])
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n && j < m)
    {
        comparisons++;

        if (a[i] < b[j])
            result[k++] = a[i++];
        else
            result[k++] = b[j++];
    }

    while (i < n)
        result[k++] = a[i++];

    while (j < m)
        result[k++] = b[j++];
}

int main()
{
    int L1[] = {10, 30, 50, 70};
    int L2[] = {20, 40, 60, 80};
    int L3[] = {15, 35, 55, 75};

    int temp[8];
    int result[12];

    merge(L1, 4, L2, 4, temp);
    merge(temp, 8, L3, 4, result);

    printf("After merging L1 and L2: ");

    for (int i = 0; i < 8; i++)
        printf("%d ", temp[i]);

    printf("\n\nFinal Merged Output: ");

    for (int i = 0; i < 12; i++)
        printf("%d ", result[i]);

    printf("\n\nNumber of key comparisons: %d\n", comparisons);

    return 0;
}
