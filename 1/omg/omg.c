#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct stackNode_t {
    int data;
    struct stackNode_t *next;
} StackNode;

typedef struct stack_t {
    StackNode *_top;
    unsigned _size;
} Stack;

void stack_init(Stack *stack);
bool stack_isEmpty(Stack *stack);
void stack_push(Stack *stack, int value);
void stack_pop(Stack *stack);
int stack_top(Stack *stack);
unsigned stack_size(Stack *stack);

void stack_init(Stack *stack)
{
    stack->_size = 0;
    stack->_top = NULL;
}

bool stack_isEmpty(Stack *stack) {
    return (stack->_top == NULL);
}

void stack_push(Stack *stack, int value)
{
    StackNode *newNode = (StackNode*) malloc(sizeof(StackNode));
    if (newNode) {
        stack->_size++;
        newNode->data = value;

        if (stack_isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->_top;

        stack->_top = newNode;
    }
}

void stack_pop(Stack *stack)
{
    if (!stack_isEmpty(stack)) {
        StackNode *temp = stack->_top;
        stack->_top = stack->_top->next;
        free(temp);
        stack->_size--;
    }
}

int stack_top(Stack *stack)
{
    if (!stack_isEmpty(stack))
        return stack->_top->data;
    return 0;
}

unsigned stack_size(Stack *stack) {
    return stack->_size;
}

int main(){
    Stack query;
    stack_init(&query);

    int n;
    int papers = 0;
    scanf("%d", &n);
    getchar();
    char tempstr[100];
    for(int i = 0; i < n; i++){
        char prompt[100];
        scanf(" %s", prompt);
        if (strcmp(prompt, "Clue") == 0){
            stack_push(&query, 1);
            papers++;
        }
        else if (strcmp(prompt, "No") == 0){
            scanf(" %s", tempstr);
            stack_push(&query, 0);

        }
    }
    int input;
    scanf("%d", &input);
    getchar();
    for (int i = 0; i < input; i++)
      {
        char cmd[100];
        scanf(" %s", cmd);
        if (strcmp(cmd, "Out") == 0)
        {
            if(stack_top(&query) == 1)
            {
                printf("I'm going crazy, right?\n");
                papers--;
            }
            stack_pop(&query);
        }
        else if (strcmp(cmd, "Count") == 0)
            {
            scanf(" %s", tempstr);
            if(papers >= 5)
            {
                printf("He's the one that's living in my system\n");
            }
            else
            {
                printf("They keep on asking me, \"Who is he?\"\n");
            }
        }
    }
}
