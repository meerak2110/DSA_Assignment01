//user.c
#include"header.h"

// Function to generate a random username
void randomUsername(char* username, int length) {
    static const char charset[] = "abcdefghijklMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < length - 1; ++i) {
        username[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    username[length - 1] = '\0';
}

// function to generate a random user
struct Users* randomUser() {
    struct Users* newUser = (struct Users*)malloc(sizeof(struct Users));
    if (newUser == NULL) {
        printf("Memory allocation error\n");
        return;
    }
    randomUsername(newUser->username, MAX_USERNAME_LENGTH);
    newUser->level = rand() % 60 + 1;
    switch (rand() % 3) {
    case 0:
        newUser->faction = 'R';
        break;
    case 1:
        newUser->faction = 'B';
        break;
    case 2:
        newUser->faction = 'G';
        break;
    }
    return newUser;
}

// function to enqueue the queue with a number of randomly created users
int enqueueRandomUsers(struct Queue* queue, int numUsers) {
    if (numUsers <= 0) {
        printf("Invalid number of users\n");
        return -1;
    }
    for (int i = 0; i < numUsers; ++i) {
        struct Users* newUser = randomUser();
        if (newUser == NULL) {
            printf("Failed to create user\n");
            return -1;
        }
        enqueue(queue, newUser);
    }
    return 0;
}