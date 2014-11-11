#include <stdio.h>
#include <stdlib.h>


typedef struct {
    void * head;
    void * tail;
} pair;


int is_nil(pair * p) {
    if (p->head || p->tail) return 1;

    return 0;
}


pair * nil() {
    pair * p = malloc(sizeof(pair));

    p->head = NULL;
    p->tail = NULL;

    return p;
}


pair * read(FILE * in) {
    return nil();
}
