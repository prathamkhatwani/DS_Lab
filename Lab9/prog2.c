#include <stdio.h>

int n;
int graph[20][20];
int visited[20];

void dfs(int v)
{
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int i, j, start = 0;
    int connected = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    dfs(start);

    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("The graph is CONNECTED.\n");
    else
        printf("The graph is NOT CONNECTED.\n");

    return 0;
}
