#pragma once
#include <cstdio>

#define MAX_INPUT_COUNT 100

struct Node {
    bool is_null;
    int key;
    Node* next;
};

/**
 * Detects and removes a loop in a linked list using Floyd's Cycle-Finding Algorithm
 * @param head Pointer to the head node of the linked list
 */
void detectAndRemoveLoop(Node* head);

/**
 * Prints the linked list in the format: key,next_index;key,next_index;...
 * @param head Pointer to the head node of the linked list
 */
void printList(Node* head);