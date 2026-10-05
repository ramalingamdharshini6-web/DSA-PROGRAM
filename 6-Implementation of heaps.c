#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

// Insert an element
void insert(int element)
{
    if (size >= MAX)
    {
        printf("Heap overflow\n");
        return;
    }

    heap[size] = element;
    int current = size;

    // Heapify-up
    while (current > 0 && heap[current] > heap[(current - 1) / 2])
    {
        int temp = heap[current];
        heap[current] = heap[(current - 1) / 2];
        heap[(current - 1) / 2] = temp;

        current = (current - 1) / 2;
    }

    size++;
}

// Heapify-down
void heapify_down(int current)
{
    int largest = current;
    int left = 2 * current + 1;
    int right = 2 * current + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;

    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != current)
    {
        int temp = heap[current];
        heap[current] = heap[largest];
        heap[largest] = temp;

        heapify_down(largest);
    }
}

// Delete the root element
void deleteHeap()
{
    if (size <= 0)
    {
        printf("Heap underflow\n");
        return;
    }

    heap[0] = heap[size - 1];
    size--;

    if (size > 0)
        heapify_down(0);
}

// Display heap
void display()
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Main function
int main()
{
    int choice, element;

    while (1)
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insert(element);
                break;

            case 2:
                deleteHeap();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}


PS D:\DSA PROGRAM> cd "d:\DSA PROGRAM\" ; if ($?) { gcc main6.c -o main6 } ; if ($?) { .\main6 }
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 50
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert:
30
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 20
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter the element to insert: 15
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 3
50 30 20 15 
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 2
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 3
30 15 20 
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 4
