#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../log/log.h"

#include "stack.h"

static void _exist(stack* s) {
    Assert(s != NULL, __func__, "stack missing");
}

static bool _empty(stack* s) {
    _exist(s);
    if (s->t == NULL) return true;
    else return false;
}

static bool _full(stack* s) {
    _exist(s);
    if (s->s == UINT_MAX) return true;
    return false;
}

stack* stack_new() {
    stack* s = malloc(sizeof(stack));
    Assert(s != NULL, __func__, "malloc error");
    s->t = NULL;
    s->s = 0;
    return s;
}

bool s_push(stack* s, void* ptr) {
    if (_full(s)) return false;
    stack_element* se = malloc(sizeof(stack_element));
    Assert(se != NULL, __func__, "malloc error");
    se->ptr = ptr;
    se->u = s->t;
    s->t = se;
    s->s += 1;
    return true;
}

void* s_pop(stack* s) {
    if (_empty(s)) return NULL;
    stack_element* se = s->t;
    s->t = se->u;
    void* ptr = se->ptr;
    free(se);
    s->s -= 1;
    return ptr;
}

unsigned int s_size(stack* s) {
    _exist(s);
    return s->s;
}
