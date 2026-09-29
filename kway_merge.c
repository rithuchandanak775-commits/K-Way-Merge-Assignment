#include <stdio.h>

#define K 3
#define SIZE 4

typedef struct
{
    int value;
    int list;
    int index;
} Item;

Item heap[K];
int heapSize = 0;
int comparisons = 0;

void swap(Item *a, Item *b)
{
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void insert(Item item)
{
    int i = heapSize++;
    heap[i] = item;

    while (i > 0)
    {
        int parent = (i - 1) / 2;
        comparisons++;

        if (heap[parent].value <= heap[i].value)
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

Item deleteMin()
{
    Item min = heap[0];
    heapSize--;

    if (heapSize > 0)
    {
        heap[0] = heap[heapSize];

        int i = 0;

        while (1)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int smallest = i;

            if (left < heapSize)
            {
                comparisons++;
                if (heap[left].value < heap[smallest].value)
                    smallest = left;
            }

            if (right < heapSize)
            {
                comparisons++;
                if (heap[right].value < heap[smallest].value)
                    smallest = right;
            }

            if (smallest == i)
                break;

            swap(&heap[i], &heap[smallest]);
            i = smallest;
        }
    }

    return min;
}

int main()
{
    int lists[K][SIZE] =
    {
        {10, 30, 50, 70},
        {20, 40, 60, 80},
        {15, 35, 55, 75}
    };

    int output[K * SIZE];
    int count = 0;

    for (int i = 0; i < K; i++)
    {
        Item item = {lists[i][0], i, 0};
        insert(item);
    }

    printf("Initial Heap: ");
    for (int i = 0; i < heapSize; i++)
        printf("%d ", heap[i].value);

    printf("\n\nMerged Output: ");

    while (heapSize > 0)
    {
        Item min = deleteMin();

        output[count++] = min.value;
        printf("%d ", min.value);

        if (min.index + 1 < SIZE)
        {
            Item next =
            {
                lists[min.list][min.index + 1],
                min.list,
                min.index + 1
            };

            insert(next);
        }
    }

    printf("\n\nNumber of elements: %d", count);
    printf("\nNumber of key comparisons: %d", comparisons);
    printf("\n");

    return 0;
}
