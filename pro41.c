#include <stdio.h>

int graph[10][10], visited[10], total;

// Stack implementation
int stack[10], top = -1;

void push(int v)
{
    top++;
    stack[top] = v;
}
int pop()
{
    int data = stack[top];
    top--;
    return data;
}

int isEmpty()
{
    return top == -1;
} 
// dfs using stack
void dfs_stack(int start)
{
    push(start);
    while (!isEmpty())
    {
        int vertex = pop();
        if (!visited[vertex])
        {
            printf("%d ", vertex);
            visited[vertex] = 1;

            // push adjecent vertices in revesre order to match recursion behavior
            for (int j = total - 1; j >= 0; j--)
            {
                if (graph[vertex][j] == 1 && !visited[j])
                {

                    push(j);
                }
            }
        }
    }
}

int main()
{
    int i, j, v;
    printf("Enter the total number of vertices :");
    scanf("%d", &total);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < total; i++)
    {
        for (int j = 0; j < total; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    for (int i = 0; i < total; i++)
    {
        visited[i] = 0;
    }

    printf("Enter the starting vertex(0 to %d):", total - 1);
    scanf("%d", &v);

    if (v >= 0 && v < total)
    {
        printf("DFS traversal using stack:");
        dfs_stack(v);
    }
    else
    {
        printf("Invlaid starting vertex.\n");
    }
    return 0;
}