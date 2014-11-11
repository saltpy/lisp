#include <stdio.h>
#include "lisp.c"


int tests_run = 0;

#define FAIL() printf("\nfailure in %s() line %d\n", __func__, __LINE__)
#define _assert(test) do { if (!test) { FAIL(); return 1; } } while(0)
#define _verify(test) do { int r=test(); tests_run++; if(r) return r; } while(0)


int parens_should_parse_to_nil() {
    char sexp[] = "()";
    FILE * f = tmpfile();
    fwrite(sexp, 1, sizeof(sexp), f);

    _assert(is_nil(read(f)) == 0);

    fclose(f);
                    
    return 0;
}


int suite() {
    _verify(parens_should_parse_to_nil);
    return 0;
}

int main(int argc, char **argv) {
    int result = suite();
    if (result == 0) printf("PASSED\n");
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
