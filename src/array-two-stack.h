#ifndef C_PTA_ARRAY_TWO_STACK_H
#define C_PTA_ARRAY_TWO_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
#define ERROR 1e8

struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

Operation GetOp();  /* details omitted */
void PrintStack( Stack S, int Tag ); /* details omitted */

Stack CreateStack(int);

bool Push(Stack, ElementType, int);

ElementType Pop(Stack, int);

#endif //C_PTA_ARRAY_TWO_STACK_H
