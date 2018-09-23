#include "array-two-stack.h"

int main() {
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while (!done) {
        switch (GetOp()) {
            case push:
                scanf("%d %d", &Tag, &X);
                if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
                break;
            case pop:
                scanf("%d", &Tag);
                X = Pop(S, Tag);
                if (X == ERROR) printf("Stack %d is Empty!\n", Tag);
                break;
            case end:
                PrintStack(S, 1);
                PrintStack(S, 2);
                done = 1;
                break;
        }
    }
    return 0;
}

static int idx = 0;

Operation GetOp() {
    if (idx == 1 || idx == 5 || idx == 9) {
        ++idx;
        return pop;
    } else if (idx == 10) {
        ++idx;
        return end;
    } else {
        ++idx;
        return push;
    }
};

void PrintStack(Stack S, int Tag) {
    printf("Pop from Stack %d: ", Tag);
    if (Tag == 1) printf("%d\n", Pop(S, 1));
    else
        for (int i = 0; i < 3; ++i)
            printf("%d ", Pop(S, 2));
    printf("\n");
}