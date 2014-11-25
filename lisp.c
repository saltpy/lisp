#include <stdio.h>
#include <stdlib.h>

enum type { PAIR, ATOM, NIL };

typedef struct {
    enum type type;
    union {
        char * name;
        struct {
            struct object * car;
            struct object * cdr;
        };
    };
} object;

object * atom(char * v) {
    object * o = malloc(sizeof(object));
    o->type = ATOM;
    o->name = v;
    return o;
}

object * cons(object * h, object * t) {
    object * o = malloc(sizeof(object));
    o->type = NIL;
    return o; 
}

object * read(FILE * in) {
    return cons(NULL, NULL);
}

object * eval(object * sexp, object * local, object * global) {
    return sexp;
}

char * repr(object * sexp) {
    if (sexp->type == ATOM) {
        return sexp->name;
    }
    return "()";
}
