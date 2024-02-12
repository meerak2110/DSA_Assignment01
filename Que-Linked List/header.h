#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USERNAME_LENGTH 11 

struct Users {
    char username[MAX_USERNAME_LENGTH];
    int level;
    char faction;
    };

struct QueueNode {
    struct Users* data;
    struct QueueNode* pNext;
};

struct Queue {
    struct QueueNode* head;
    struct QueueNode* tail;
};


void initialize(struct Queue* queue);
int isEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, struct Users* user);
struct Users* dequeue(struct Queue* queue);
void printQueue(struct Queue* queue);
void randomUsername(char* username, int length);
struct Users* randomUser();
int enqueueRandomUsers(struct Queue* queue, int numUsers);