#include <stdio.h>
#include <stdlib.h>

typedef struct deque {
    int data[1000];
    int front, backend;
} deque;

void push_back(deque* q, int x) {
    q->data[q->backend++] = x;
}

void push_front(deque* q, int x) {
    q->data[--q->front] = x;
}

void pop_back(deque* q) {
    --q->backend;
}

void pop_front(deque* q) {
    ++q->front;
}

int front(deque* q) {
    return q->data[q->front];
}

int main() {
    deque runabout = {500};
    deque exit = {500};

    for (int i = 0; i < 6; ++i) {
        int car;
        scanf("%d", &car);
        push_back(&runabout, car);
    }

    while (1) {
        int prompt;
        scanf("%d", &prompt);

        if (prompt == 0) {
            push_back(&runabout, front(&runabout));
            pop_front(&runabout);
        }
        else if (prompt == -1) {
            break;
        }
        else if (prompt == 1) {
            int cars;
            scanf("%d", &cars);
            for (int i = 0; i < 2; ++i) {
                push_back(&runabout, front(&runabout));
                pop_front(&runabout);
            }
            push_back(&exit, front(&runabout));
            pop_front(&runabout);
            for (int i = 0; i < 2; ++i) {
                push_front(&runabout, runabout.data[runabout.backend - 1]);
                pop_back(&runabout);
            }
            push_back(&runabout, cars);
        }
    }

    if (exit.backend - exit.front > 0) {
        printf("Cars left the Roundabout: ");
        int scope = exit.backend - exit.front;
        for (int i = 0; i < scope; ++i) {
            printf("%d ", exit.data[exit.front++]);
        }
    }
    else {
        printf("No Cars left the Roundabout\n");
    }
}
