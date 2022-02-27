#include <stdio.h>
#include <stdlib.h>

struct stack_users
{
    int elements[20];
    int last_filled;
} stack_users;


struct stack_users Create_stack(void)
{
    struct stack_users stack1;
    stack1.last_filled=-1;
    return stack1;
}

void Push_stack(struct stack_users *stack1, int element)
{
    stack1->elements[stack1->last_filled+1] = element;
    stack1->last_filled++;
}

int Top_stack(struct stack_users *stack1)
{
   return stack1->elements[stack1->last_filled];
}

int Pop_stack(struct stack_users *stack1)
{
   if (stack1->last_filled>=0)
   {int popped;
   popped = stack1->elements[stack1->last_filled];
   stack1->elements[stack1->last_filled] = 0;
   stack1->last_filled--;
   return popped;}
   else
   {
        printf("Nothing to return\n");
        return 0;
   }

}

int IsEmpty(struct stack_users stack1)
{
    if (stack1.last_filled>=0)
        return 0;
    else
        return 1;
}

int main()
{

    struct stack_users stack1 = Create_stack();

    printf("last filled ... %d\n", stack1.last_filled);

    printf("if stack is empty now? %d\n", IsEmpty(stack1));

    Push_stack(&stack1,10);
    printf("if stack is empty now? %d\n", IsEmpty(stack1));
    Push_stack(&stack1,20);
    Push_stack(&stack1,30);


    printf("add to stack1 element %d\n", stack1.elements[0]);
    printf("add to stack1 element %d\n", stack1.elements[1]);
    printf("add to stack1 element %d\n", stack1.elements[2]);
    printf("Top demonstration: %d", Top_stack(&stack1));

    printf("Pop stack demonstration: %d\n", Pop_stack(&stack1));
    printf("Pop stack demonstration: %d\n", Pop_stack(&stack1));
    printf("if stack is empty now? %d\n", IsEmpty(stack1));
    printf("Pop stack demonstration: %d\n", Pop_stack(&stack1));
    printf("Pop stack demonstration: %d\n", Pop_stack(&stack1));
    printf("if stack is empty now? %d\n", IsEmpty(stack1));

    // еще добавить можно - проверка размера стека, проверка его наполненности

    printf("Hello world!\n");
    return 0;
}
