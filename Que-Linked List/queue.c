//queue.c

#include"header.h"

// function to initialize a blank queue
void initialize(struct Queue* queue) {
    queue->head = NULL;
    queue->tail = NULL;
}

//function to check if the queue is empty or not
int isEmpty(struct Queue* queue) {
    return
        queue->head == NULL;
}

// function to enqueue
void enqueue(struct Queue* queue, struct Users* user) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        printf("Error Allocating memory\n"); 
        return;
    }
    newNode->data = user;
    newNode->pNext = NULL;

    if (isEmpty(queue)) {
        queue->head = newNode;
    }
    else {
        queue->tail->pNext = newNode;
    }
    queue->tail = newNode;
}

// function to dequeue a node
struct Users* dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    struct QueueNode* temp = queue->head;
    struct Users* user = temp->data;
    queue->head = queue->head->pNext;
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    free(temp);
    return user;
}

//print details of the users
void printQueue(struct Queue queue) {
    while (!isEmpty(&queue)) {
        struct Users* user = dequeue(&queue);
        printf("____________________________________________________________________________\n");
        printf("Username: %s, Level: %d, Faction: %c\n", user->username, user->level, user->faction);//printing setails
        free(user); //freeing memory
    }
}