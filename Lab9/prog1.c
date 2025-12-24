#include <stdio.h>

int n;
int graph[20][20];
int visited[20];

void bfs(int start)
{
    int queue[20], front = 0, rear = 0;
    int i;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < n; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
