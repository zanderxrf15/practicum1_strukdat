#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    int *data;
    int front;
    int backend;
    int size;
} deque;

void init(deque *q, int n)
{
    q->data = (int *)malloc(sizeof(int) * n);
    q->front = -1;
    q->backend= -1;
    q->size = n;
}

bool is_empty(deque *q)
{
    return q->front == -1;
}

bool is_full(deque *q)
{
    return (q->front == 0 && q->backend == q->size - 1) || (q->front == q->backend + 1);
}

void push_front(deque *q, int x)
{
    if (is_full(q)) {
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
        q->backend = 0;
    }
    else if (q->front == 0) {
        q->front = q->size - 1;
    }
    else
    {
        q->front--;
    }
    q->data[q->front] = x;
}

void push_back(deque *q, int x)
{
    if (is_full(q))
    {
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
        q->backend = 0;
    }
    else if (q->backend == q->size - 1)
    {
        q->backend = 0;
    }
    else
    {
        q->backend++;
    }
    q->data[q->backend] = x;
}

void pop_front(deque *q)
   {
    if (is_empty(q))
    {
        return;
    }
    if (q->front == q->backend)
    {
        q->front = -1;
        q->backend = -1;
    }
    else if (q->front == q->size - 1)
    {
        q->front = 0;
    }
    else
    {
        q->front++;
    }
}

void pop_back(deque *q) {
    if (is_empty(q)) {
        return;
    }
    if (q->front == q->backend)
    {
        q->front = -1;
        q->backend = -1;
    }
    else if (q->backend == 0)
    {
        q->backend = q->size - 1;
    }
    else
    {
        q->backend--;
    }
}

int front(deque *q) {
    if (is_empty(q)) {
        return -1;
    }
    return q->data[q->front];
}

int back(deque *q) {
    if (is_empty(q)) {
        return -1;
    }
    return q->data[q->backend];
}

void destroy(deque *q)
{
    free(q->data);
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    deque numbers;
    init(&numbers, n);
    int outputs1[100];
    int outputs2[100];

    for (int i = 0; i < n; i++)
   {
        int number;
        scanf("%d", &number);
        push_back(&numbers, number);
    }

    if (q == 0)
    {
        printf("Input Not Valid\n");
        return 0;
    }

    for (int i = 0; i < q; i++)
      {
        int m;
        scanf("%d", &m);
        deque numbers_copy = numbers;
        for (int j = 1; j <= m; j++) {
            int a = front(&numbers_copy);
            pop_front(&numbers_copy);
            int b = front(&numbers_copy);
            pop_front(&numbers_copy);

            if (j == m)
            {
                outputs1[i] = a;
                outputs2[i] = b;
            }
            if (a > b)
            {
                push_front(&numbers_copy, a);
                push_back(&numbers_copy, b);
            }
            else if (a < b)
            {
                push_front(&numbers_copy, b);
                push_back(&numbers_copy, a);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        printf("%d %d\n", outputs1[i], outputs2[i]);
    }
    destroy(&numbers);
}
