#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n;

// Enqueue
void enqueue(int v)
{
    if (rear == MAX - 1)
        printf("\nQueue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = v;
    }
}

// Dequeue
int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nQueue Underflow\n");
        exit(1);
    }
    return queue[front++];
}

// Check if queue is empty
int isQueueEmpty()
{
    return (front == -1 || front > rear);
}

// Breadth First Search
void BFS(int startVertex)
{
    int v;
    enqueue(startVertex);
    visited[startVertex] = 1;

    while (!isQueueEmpty())
    {
        v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

// Depth First Search
void DFS(int v)
{
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

// Initialize graph
void initialize()
{
    for (int i = 0; i < MAX; i++)
    {
        visited[i] = 0;
        for (int j = 0; j < MAX; j++)
        {
            adj[i][j] = 0;
        }
    }
}

// Main function
int main()
{
    int edges, origin, destination;
    int startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of vertices\n");
        return 1;
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    if (edges < 0)
    {
        printf("Invalid number of edges\n");
        return 1;
    }

    initialize();

    for (int i = 0; i < edges; i++)
    {
        printf("Enter edge (origin destination): ");
        scanf("%d %d", &origin, &destination);

        if (origin < 0 || origin >= n ||
            destination < 0 || destination >= n)
        {
            printf("Invalid vertex\n");
            return 1;
        }

        adj[origin][destination] = 1;
        adj[destination][origin] = 1;
    }

    printf("Enter the start vertex for BFS: ");
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= n)
    {
        printf("Invalid start vertex\n");
        return 1;
    }

    printf("BFS Traversal: ");
    BFS(startVertex);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    front = rear = -1;

    printf("Enter the start vertex for DFS: ");
    scanf("%d", &startVertex);

    if (startVertex < 0 || startVertex >= n)
    {
        printf("Invalid start vertex\n");
        return 1;
    }

    printf("DFS Traversal: ");
    DFS(startVertex);
    printf("\n");

    return 0;
}





PS D:\DSA PROGRAM> cd "d:\DSA PROGRAM\" ; if ($?) { gcc main5.c -o main5 } ; if ($?) { .\main5 }
Enter the number of vertices: 5
Enter the number of edges: 5
Enter edge (origin destination): 0 1
Enter edge (origin destination): 0 2
Enter edge (origin destination): 1 3
Enter edge (origin destination): 1 4
Enter edge (origin destination): 3 4
Enter the start vertex for BFS: 0
BFS Traversal: 0 1 2 3 4 
Enter the start vertex for DFS: 0
DFS Traversal: 0 1 3 4 2 
