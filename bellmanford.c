#include <stdio.h>
#include <stdlib.h>
#define infinity 99999

struct edge
{
    int u;
    int v;
    int w;
};

struct graph
{
    int V;
    int E;
    struct edge *edg;
};
void display(int arr[], int size);
void bellman(struct graph *g, int src)
{
    int i, j, u, v, w;

    int nvertex = g->V;
    int nedges = g->E;

    int d[nvertex];

    for (i = 0; i < nvertex; i++)
    {
        d[i] = infinity;
    }
    d[src] = 0;

    for (i = 1; i < nvertex; i++)
    {
        for (j = 0; j < nedges; j++)
        {
            u = g->edg[j].u;
            v = g->edg[j].v;
            w = g->edg[j].w;

            if (d[u] != infinity && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
            }
        }
    }

    for (i = 0; i < nedges; i++)
    {
        u = g->edg[i].u;
        v = g->edg[i].v;
        w = g->edg[i].w;

        if (d[u] != infinity && d[v] > d[u] + w)
        {
            printf("Negative weight cycle detected\n");
            return;
        }
    }

    printf("Distance array: ");
    display(d, nvertex);
}
void display(int arr[], int size)
{
    int i;
    printf("Vertex   Distance from source\n");

    for (i = 0; i < size; i++)
    {
        printf("%d \t %d\n", i, arr[i]);
    }
    printf("\n");
}

int main()
{
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));

    printf("Enter the number of vertices: ");
    scanf("%d", &(g->V));

    printf("Enter the number of edges: ");
    scanf("%d", &(g->E));

    g->edg = (struct edge *)malloc((g->E) * sizeof(struct edge));

    int i, j;

    for (i = 0; i < g->E; i++)
    {
        printf("Enter from vertex :");
        scanf("%d", &(g->edg[i].u));
        printf("Enter destination vertex :");
        scanf("%d", &(g->edg[i].v));
        printf("Enter weight of edge %d-->%d :", g->edg[i].u, g->edg[i].v);
        scanf("%d", &(g->edg[i].w));
    }

    bellman(g, 0);

    return 0;
}
