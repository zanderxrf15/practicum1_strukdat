#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int priority;
    char label[100];
} chores;

typedef struct {
    chores*array;
    int scope;
    int magnitude;
} PriorityQueue;

PriorityQueue *create_priority_queue(int magnitude) {
    PriorityQueue *pq = (PriorityQueue *) malloc(sizeof(PriorityQueue));
    pq->array = (chores*) malloc(magnitude * sizeof(chores));
    pq->scope = 0;
    pq->magnitude = magnitude;
    return pq;
}

void destroy_priority_queue(PriorityQueue *pq) {
    free(pq->array);
    free(pq);
}

void enqueue(PriorityQueue *pq, int priority, char *label) {
    if(pq->scope == pq->magnitude) {
        pq->magnitude *= 2;
        pq->array = (chores *) realloc(pq->array, pq->magnitude * sizeof(chores));
    }
    pq->array[pq->scope].priority = priority;
    strcpy(pq->array[pq->scope].label, label);
    pq->scope++;
}

chores dequeue(PriorityQueue *pq) {
    int min_index = 0;
    for(int i=1; i<pq->scope; i++) {
        if(pq->array[i].priority < pq->array[min_index].priority) {
            min_index = i;
        }
    }
    chores min_chore = pq->array[min_index];
    pq->scope--;
    pq->array[min_index] = pq->array[pq->scope];
    return min_chore;
}

int main() {
    int e, n;
    scanf("%d %d", &e, &n);
    PriorityQueue *pq = create_priority_queue(n);
    for(int i=0; i<n; i++) {
        int p;
        char s[100];
        scanf("%d %s", &p, s);
        enqueue(pq, p, s);
    }
    int done = 0;
    while(pq->scope > 0 && e > 0) {
        chores chores = dequeue(pq);
        if(e >= chores.priority) {
            printf("%s\n", chores.label);
            e -= chores.priority;
            done = 1;
        }
    }
    if(!done) {
        printf("Pak Aya will do the rest\n");
    }
    destroy_priority_queue(pq);
}
