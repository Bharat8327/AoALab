#include<stdio.h>
#include<conio.h>

int g[20][20], d[20], visited[20], p[20];
int v, e;
int i, j;

void prim() {
    int current = 1, totalVisited = 1, min, minCost = 0;
    visited[current] = 1;
    d[current] = 0;

    while (totalVisited != v) {
        for (i = 1; i <= v; i++) {
            if (g[current][i] != 0 && visited[i] == 0) { 
                if (d[i] > g[current][i]) {
                    d[i] = g[current][i];
                    p[i] = current;
                }
            }
        }

        min = 32767;
        for (i = 1; i <= v; i++) {
            if (visited[i] == 0 && d[i] < min) {
                min = d[i];
                current = i;
            }
        }

        visited[current] = 1;
        totalVisited++;
    }

    for (i = 2; i <= v; i++) {
        minCost += d[i];
    }

    printf("Minimum cost of the spanning tree is %d\n", minCost);
    printf("Edges in the Minimum Spanning Tree:\n");
    for (i = 2; i <= v; i++) {
        printf("%d - %d : %d\n", p[i], i, d[i]);
    }
}

int main() {
    int a, b, w;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (i = 1; i <= v; i++) {
        for (j = 1; j <= v; j++) {
            g[i][j] = 0;
        }
        p[i] = 0;
        visited[i] = 0;
        d[i] = 32767;
    }

    for (i = 1; i <= e; i++) {
        printf("Enter edge (a, b) and weight (w): ");
        scanf("%d%d%d", &a, &b, &w);
        g[a][b] = w;
        g[b][a] = w; 
    }

    prim();

    return 0;
}
 