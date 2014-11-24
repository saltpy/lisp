#include <stdio.h>
#include <stdlib.h>


typedef struct {
    void * head;
    void * tail;
} pair;


pair * NIL;


pair * cons(pair * h, pair * t) {
    return NIL; 
}


pair * head(pair * p) {
    if (nil(p) == 0) return p;
    return p->head;
}


pair * tail(pair * p) {
    if (nil(p) == 0) return p;
    return p->tail;
}


int nil(pair * p) {
    return (p == NIL) ? 0 : 1;
}


pair * read(FILE * in) {
    return cons(NULL, NULL);
}
