//Assignment 1
//Meera Kurup
//Queue linked list implementation

//reate a struct to represent users in a game.What is required of each person is their unique username, their level(levels can range from 1 – 60), and their faction(red, blue or green).
//
//Implement a set of functions in a queue.c file which defines the required operations of an abstract data type queue.The queue should be created as a struct containing two node pointers : for the head and tail of the queue.The queue should be created from a set of linked nodes, and you may use any code from the Week 04 lecture to assist in this implementation.The queue will require at minimum :
//
//A function to initialize a blank queue
//A function to check if the queue is empty
//A function to enqueue a node
//A function to dequeue a node
//Create a struct to represent a queue node.This structure contains a node pointer and a user struct as its data.
//
//Write a function to enqueue the queue with a number of randomly created users.You will need to pass this function a pointer to an initialized queue, and the number of users to add to the queue.The number of users to add to the queue is to be passed to the program as a command line argument.Each user should be randomly generated(for the username you can randomly select a set number of letters and numbers.I.e., you can hardcode in all usernames are 10 characters in length, for example7ert567hjt.).This function returns 0 if it succeeds, and non - zero if something goes wrong.
//
//Write a testing main() function which initializes the queue, calls the function to add users to the queue(and reports if an error occurred), and then dequeues from the function one at a time until the queue is empty.After each dequeue, print on the screen the username, level and faction of the user that was dequeued.

#include"header.h"

int main(int argc, char* argv[]) {//command line argument
  
    int numUsers = atoi(argv[1]);
    if (numUsers <= 0) {
        printf("Invalid number of users\n");
        return 1;
    }

    srand(time(NULL));
    struct Queue queue;
    initialize(&queue);

    if (enqueueRandomUsers(&queue, numUsers) != 0) {
        printf("Error: Failed to enqueue users\n");
        return 1;
    }

    printQueue(&queue);

    return 0;
}
