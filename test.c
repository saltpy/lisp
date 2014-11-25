#include <stdio.h>
#include "lisp.c"


int tests_run = 0;

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!test) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)


int _assert_char_arrays_equal(char expected[], char actual[]) {
    _assert(sizeof(expected) == sizeof(actual));
    int i;

    for (i = 0; i <= sizeof(expected); i++) _assert(expected[i] == actual[i]);

    return 0;
}


int parens_should_read_to_nil() {
    char sexp[] = "()";
    FILE * f = tmpfile();
    fwrite(sexp, 1, sizeof(sexp), f);
    object * actual = read(f);

    _assert(actual->type == NIL);

    fclose(f);
                    
    return 0;
}


int cons_of_null_and_null_should_equal_nil() {
    object * actual = cons(NULL, NULL);
    _assert(actual->type == NIL);

    return 0;
}


int repr_of_nil_should_be_empty_parens() {
    char expected[2] = "()";
    _assert_char_arrays_equal(expected, repr(cons(NULL, NULL)));

    return 0;
}


int suite() {
    _verify(parens_should_read_to_nil);
    _verify(cons_of_null_and_null_should_equal_nil);
    _verify(repr_of_nil_should_be_empty_parens);
    return 0;
}


int main(int argc, char **argv) {
    int result = suite();
    if (result == 0) printf("PASSED\n");
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
