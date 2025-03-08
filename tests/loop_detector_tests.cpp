#include <cassert>
#include <sstream>
#include <iostream>
#include "../src/linked_list/loop_detector.h"

// Test function declarations
void testLoopDetection();
void testNoLoop();
void testSingleNodeLoop();
void testEmptyList();
void testComplexLoop();

// Redirect cout for testing
class CoutRedirect {
    std::streambuf* old;
    std::stringstream ss;
public:
    CoutRedirect() : old(std::cout.rdbuf(ss.rdbuf())) {}
    ~CoutRedirect() { std::cout.rdbuf(old); }
    std::string str() { return ss.str(); }
};

void runLoopTests() {
    testLoopDetection();
    testNoLoop();
    testSingleNodeLoop();
    testEmptyList();
    testComplexLoop();
    std::cout << "All loop detector tests passed!" << std::endl;
}

void testLoopDetection() {
    // Create a linked list: 1->2->3->4->5->3 (loop)
    Node* nodes = new Node[5];
    for(int i = 0; i < 5; i++) {
        nodes[i].key = i + 1;
        nodes[i].is_null = false;
        nodes[i].next = &nodes[i + 1];
    }
    nodes[4].next = &nodes[2]; // Create loop to node 3

    CoutRedirect redirect;
    detectAndRemoveLoop(nodes);
    assert(nodes[4].next == nullptr); // Loop should be removed

    delete[] nodes;
}

void testNoLoop() {
    // Create a linked list: 1->2->3->nullptr
    Node* nodes = new Node[3];
    for(int i = 0; i < 3; i++) {
        nodes[i].key = i + 1;
        nodes[i].is_null = false;
        nodes[i].next = (i < 2) ? &nodes[i + 1] : nullptr;
    }

    CoutRedirect redirect;
    detectAndRemoveLoop(nodes);
    assert(nodes[2].next == nullptr); // Should remain unchanged

    delete[] nodes;
}

void testSingleNodeLoop() {
    // Create a single node pointing to itself
    Node* node = new Node();
    node->key = 1;
    node->is_null = false;
    node->next = node;

    CoutRedirect redirect;
    detectAndRemoveLoop(node);
    assert(node->next == nullptr); // Loop should be removed

    delete node;
}

void testEmptyList() {
    Node* node = nullptr;
    CoutRedirect redirect;
    detectAndRemoveLoop(node);
    assert(node == nullptr); // Should handle nullptr gracefully
}

void testComplexLoop() {
    // Create a linked list: 1->2->3->4->5->6->4 (loop)
    Node* nodes = new Node[6];
    for(int i = 0; i < 6; i++) {
        nodes[i].key = i + 1;
        nodes[i].is_null = false;
        nodes[i].next = &nodes[i + 1];
    }
    nodes[5].next = &nodes[3]; // Create loop to node 4

    CoutRedirect redirect;
    detectAndRemoveLoop(nodes);
    assert(nodes[5].next == nullptr); // Loop should be removed

    delete[] nodes;
}
