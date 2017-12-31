#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

static int* p(int i) {
    int* p = malloc(sizeof(int));
    *p = i;
    return p;
}

int main() {
    stack* s = stack_new();
    assert(s_size(s) == 0);
    assert(s_pop(s) == NULL);

    int l = 4;
    int a[l];
    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 0;
    int* p;
    for (int i = 0; i < l; i++) {
        p = &a[i];
        assert(s_push(s, p));
    }
    assert(s_size(s) == l);

    int t;
    for (int i = l - 1; i >= 0; i--) {
        p = s_pop(s);
        assert(*p == a[i]);
        assert(s_size(s) == i);
    }
    assert(s_size(s) == 0);
    assert(s_pop(s) == NULL);
    free(s);

    return 0;
}
