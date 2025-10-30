#include <stdio.h>
int parent[20];
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}
int main() {
    int cost[20][20];
    int n, i, j, edges = 1;
    int min, u = -1, v = -1, mincost = 0;
    printf("Enter number of hosts (nodes): ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix (use 99 for no connection):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 99;
        }
    }
    for (i = 1; i <= n; i++)
        parent[i] = i;

    printf("\nEdges in the Broadcast Tree:\n");
    while (edges < n) {
        min = 99;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        union_set(u, v);
        printf("%d -> %d   cost = %d\n", u, v, min);
        mincost += min;
        cost[u][v] = cost[v][u] = 99;
        edges++;
    }

    printf("\nTotal Minimum Cost (Broadcast Tree) = %d\n", mincost);
    return 0;
}


output:


Enter number of hosts (nodes): 5
Enter the cost adjacency matrix (use 99 for no connection):
0 2 99 6 99
2 0 3 8 5
99 3 0 99 7
6 8 99 0 9
99 5 7 9 0

Edges in the Broadcast Tree:
1 -> 2    cost = 2
2 -> 3    cost = 3
2 -> 5    cost = 5
1 -> 4    cost = 6

Total Minimum Cost (Broadcast Tree) = 16
