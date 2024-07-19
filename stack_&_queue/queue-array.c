#include <stdio.h>
#define SIZE 6 //So it holds 5 Elements

void enqueue(int queue[], int data,int head, int* tail){
    if ((*tail+1)%SIZE != head){
        queue[*tail] = data;
        *tail = (*tail + 1) % SIZE;
    } else {
        printf("Queue OverFlow\n");
    }
}

void dequeue(int queue[], int* head, int tail){ 
    if ((*head) != tail){
        printf("Dequeued value : %i\n", queue[*head]);
        *head = (*head+1) % SIZE;
    } else {
        printf("Queue UnderFlow\n");
    }
}
int main(){
    int queue[SIZE];
    int queue_head = 0;
    int queue_tail = 0;

        printf("\
MAIN MENU\n \
1. ENQUEUE   \n \
2. DEQUEUE    \n \
3. EXIT   \n");


    while (1){
        int choice;
        printf("Enter your choice : ");
        scanf("%i", &choice);

        switch (choice)
        {
            case 1:
                int value;
                printf("Enter the value to enqueue : ");
                scanf("%i", &value);
                enqueue(queue, value, queue_head, &queue_tail);
                break;
            case 2:
                dequeue(queue, &queue_head, queue_tail);
                break;
            case 3:
                return 0;
            default:
                printf("Wrong input\n");
            }
    }
}   