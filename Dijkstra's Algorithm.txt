#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[20][20];
    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int src;
    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    int dist[20], visited[20];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    // Dijkstra’s Algorithm
    for (int count = 0; count < n - 1; count++) {
        int u = -1, min = INT_MAX;
        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }

        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("\nShortest distances from vertex %d:\n", src);
    for (int i = 0; i < n; i++)
        printf("%d → %d = %d\n", src, i, dist[i]);

    return 0;
}




output:


Enter number of vertices: 5
Enter the adjacency matrix (0 for no edge):
0 10 0 5 0
0 0 1 2 0
0 0 0 0 4
0 3 9 0 2
7 0 6 0 0
Enter source vertex (0 to 4): 0

Shortest distances from vertex 0:
0 → 0 = 0
0 → 1 = 8
0 → 2 = 9
0 → 3 = 5
0 → 4 = 7




