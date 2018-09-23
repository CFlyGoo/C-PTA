//
// 本题要求在一个数组中实现两个堆栈。
//
//函数接口定义：
//Stack CreateStack( int MaxSize );
//bool Push( Stack S, ElementType X, int Tag );
//ElementType Pop( Stack S, int Tag );
//其中Tag是堆栈编号，取1或2；MaxSize堆栈数组的规模；Stack结构定义如下：
//
//typedef int Position;
//struct SNode {
//    ElementType *Data;
//    Position Top1, Top2;
//    int MaxSize;
//};
//typedef struct SNode *Stack;
//注意：如果堆栈已满，Push函数必须输出“Stack Full”并且返回false；如果某堆栈是空的，
// 则Pop函数必须输出“Stack Tag Empty”（其中Tag是该堆栈的编号），并且返回ERROR。
//
#include "array-two-stack.h"

Stack CreateStack(int MaxSize) {
    Stack S = malloc(sizeof(struct SNode));
    S->Data = malloc(sizeof(ElementType) * MaxSize);
    S->MaxSize = MaxSize;
    S->Top1 = -1;
    S->Top2 = MaxSize;
    return S;
}

bool Push(Stack S, ElementType X, int Tag) {
    if (S->Top2 - S->Top1 == 1) {
        printf("Stack Full\n");
        return false;
    }
    if (Tag == 1)
        S->Data[++S->Top1] = X;
    else
        S->Data[--S->Top2] = X;
    return true;
}

ElementType Pop(Stack S, int Tag) {
    if ((Tag == 1 && S->Top1 == -1) || (Tag == 2 && S->Top2 == S->MaxSize)) {
        printf("Stack %d Empty\n", Tag);
        return ERROR;
    }
    return (Tag == 1) ?
           S->Data[S->Top1--] :
           S->Data[S->Top2++];
}