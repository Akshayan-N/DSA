#include <stdio.h>
#define STACK_SIZE 20
void push(int stack[], int element,int* pointer){
    if (*pointer < STACK_SIZE - 1) {
        stack[++*pointer] = element;
    } else {
        printf("Stack OverFlow\n");
    }
}

void pop(int stack[], int* pointer){
    if (*pointer >= 0){
        printf("Popped the value : %i\n", stack[(*pointer)--]);
    } else {
        printf("Stack UnderFlow\n");
    }
}

int main(){
    int stack[STACK_SIZE];
    int stack_pointer = -1;

    printf("\
MAIN MENU\n \
1. PUSH   \n \
2. POP    \n \
3. EXIT   \n");


    while (1){
        int choice;
        printf("Enter your choice : ");
        scanf("%i", &choice);

        switch (choice)
        {
            case 1:
                int value;
                printf("Enter the value to push : ");
                scanf("%i", &value);
                push(stack, value, &stack_pointer);
                break;
            case 2:
                pop(stack, &stack_pointer);
                break;
            case 3:
                return 0;
            default:
                printf("Wrong input\n");
            }
    }
}