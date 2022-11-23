// Lukas Brasiunas, 2110539

#include "queue_functions.c"

// Program to test queue functions
int main()
{
    int error = 1;
    struct Queue* queue = createQueue();
    printf("Empty queue created.\n");

    if(!isEmpty(queue))
        printf("The queue is empty.\n");
    else
        printf("The queue is not empty.\n");

    if(!isFull())
        printf("The queue is full.\n");
    else
        printf("The queue is not full.\n");

    enQueue(queue, 10, &error);
    printf("Added 10 to queue.\n");
    enQueue(queue, 20, &error);
    printf("Added 20 to queue.\n");

    if(!isEmpty(queue))
        printf("The queue is empty.\n");
    else
        printf("The queue is not empty.\n");

    printf("First element in queue: %d\n", peek(queue));
    printList(queue);
    deQueue(queue);
    printf("Deleted last element from queue.\n");
    deQueue(queue);
    printf("Deleted last element from queue.\n");
    printList(queue);

    if(!isFull())
        printf("The queue is full.\n");
    else
        printf("The queue is not full.\n");

    enQueue(queue, 30, &error);
    printf("Added 30 to queue.\n");
    printf("First element in queue: %d\n", peek(queue));
    enQueue(queue, 40, &error);
    printf("Added 40 to queue.\n");
    enQueue(queue, 50, &error);
    printf("Added 50 to queue.\n");
    printList(queue);
    deQueue(queue);
    printf("Deleted last element from queue.\n");
    destroyList(queue);
    printf("Entire queue deleted.\n");

    if(!isEmpty(queue))
        printf("The queue is empty.\n");
    else
        printf("The queue is not empty.\n");

    printList(queue);
    return 0;
}
