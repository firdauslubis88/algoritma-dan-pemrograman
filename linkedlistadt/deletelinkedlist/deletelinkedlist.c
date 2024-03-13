//
//  main.c
//  173-LetsCodeDeleteOnLinkedList
//
//  Created by Tenzing Rabgyal on 8/17/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> // for 'malloc'

struct Node {
    int data;
    struct Node *next;
}*first = NULL; // this is a global pointer

void create(int A[], int n) {
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for (int i = 1; i < n; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// we can also pass the parameter by value since we are not modifying it
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(1)
void display(struct Node *p) {
    
    // Iterate over the linked list
    while (p != NULL) { // same as 'while (p)'
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// recursive version of 'display function'
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(n)
void recDisplay(struct Node *p) {
    if (p != NULL) { // same as 'if (p)'
        printf("%d ", p->data);
        recDisplay(p->next);
    }
}

// displays the linked list data in reverse order
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(n)
void revRecDisplay(struct Node *p) {
    if (p != NULL) { // same as 'if (p)'
        revRecDisplay(p->next);
        printf("%d ", p->data);
    }
}

// counts the number of nodes in the linked list.
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(1)
int count(struct Node *p) {
    int l = 0; // length is initially zero
    while (p) { // same as 'while (p != NULL)'
        l++;
        p = p->next;
    }
    return l; // return the length
}

// recursive version of 'count function'
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(n)
int recCount(struct Node *p) {
    if (p) // same as 'if (p != NULL)'
        return recCount(p->next) + 1;
    else
        return 0;
}

// sums up all of the elements in the linked list
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(1)
int sum(struct Node *p) {
    int s = 0;
    while (p) { // same as 'while (p != NULL)'
        s += p->data;
        p = p->next;
    }
    return s;
}

// recursive version of 'sum function'
// 'p' is a copy of 'first' pointer.
// Time Complexity: O(n)
// Space Complexity: O(n)
int recSum(struct Node *p) {
    if (!p) // same as 'if (p == NULL)'
        return 0;
    else
        return recSum(p->next) + p->data;
}


// finds the maximum element in the linked list
// Time Complexity: O(n)
// Space Complexity: O(1)
int _max(struct Node *p) {
    int max = INT_MIN; // smallest integer value
    while(p) {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

// recursive version of 'max function'
// Time Complexity: O(n)
// Space Complexity: O(n)
int recMax(struct Node *p) {
    if (!p)
        return INT_MIN;
    int x = recMax(p->next);
    return (x > p->data) ? x : p->data;
}

// Linear Search on a linked list
struct Node* linearSearch(struct Node *p, int key) {
    while (p) {
        if (key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

// recursive version of Linear Search on a linked list
struct Node* recLinearSearch(struct Node *p, int key) {
    if (!p)
        return NULL;
    if (key == p->data)
        return p;
    return recLinearSearch(p->next, key);
}

// Linear Search on a linked list w/ 'Move to head'
struct Node* improvedLinearSearch(struct Node *p, int key) {
    struct Node *q = NULL; // a tail pointer which will follow 'p'
    while(p) {
        if (key == p->data) {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

// Time Complexity: O(n)
void insert(struct Node *p, int index, int x) {
    
    // check if the index is valid
    if (index < 0 || index > count(p))
        return;
    
    struct Node *t = (struct Node *)malloc(sizeof(struct Node)); //temp
    t->data = x;
    
    //Now we need to link the new node 't' in the linked list
    if (index == 0) { // if '0', insert before 'first' node
        t->next = first;
        first = t;
    }
    else {
        // move pointer 'p' to correct position
        for (int i = 0; i < index-1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

// Time Complexity: O(n)
void sortedInsert(struct Node *p, int x) {
    
    struct Node *q = NULL; // tail pointer which will follow 'p'
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    
    if (first == NULL) // if linked list is empty
        first = t;
    else {
        while (p && p->data < x) {
            q = p;
            p = p->next;
        }
        if (p == first) {
            t->next = first;
            first = t;
        }
        else {
            t->next = q->next;
            q->next = t;
        }
    }
}

// Time Complexity: O(n)
// returns the data of the deleted Node
// index start at 1
int delete(struct Node *p, int index) {
    struct Node *q = NULL; // tail pointer
    int x = -1;
    
    // check if the index is valid
    if (index < 1 || index > count(p))
        return -1;
    
    // if we want to delete the first node in LL
    if (index == 1) {
        first = first->next;
        x = p->data;
        free(p); // deleting the first Node
        return x;
    }
    else {
        for (int i = 0; i < index-1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p); // deleting the first Node
        return x;
    }
}

int main() {
    int A[] = {10,20,30,40,50};
    create(A, 5);
    display(first);
    
    printf("Deleted Node's data: %d\n", delete(first, 1));
    printf("Deleted Node's data: %d\n", delete(first, 1));
    
    display(first);
    
    return 0;
}
