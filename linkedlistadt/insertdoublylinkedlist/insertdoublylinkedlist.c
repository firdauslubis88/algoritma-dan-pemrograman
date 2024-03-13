//
//  main.c
//  198-LetsCodeInsertForDoublyLinkedList
//
//  Created by Tenzing Rabgyal on 8/21/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h> // for 'malloc'

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n) {
    struct Node *t, *last;
    
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    
    for (int i = 1; i < n; i++) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(struct Node* p) {
    while(p) {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int length(struct Node *p) {
    int len = 0;
    
    while(p) {
        len++;
        p = p->next;
    }
    return len;
}

// Time Complexity: O(n)
void insert(struct Node *p, int index, int x) {
    struct Node *t;
    
    // check if the index is valid
    if (index < 0 || index > length(p))
        return;

    if(index == 0) { // special case
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else {
        // move pointer 'p' to correct position
        for (int i = 0; i < index-1; i++)
            p = p->next;
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if(p->next) // if 'p' was NOT the last Node
            p->next->prev = t;
        p->next = t;
    }
}

int main() {
    int A[] = {10,20,30,40,50};
    create(A,5);
    
    display(first);
    insert(first,2,2000);
    display(first);
    insert(first,0,1000);
    display(first);
    
    return 0;
}
