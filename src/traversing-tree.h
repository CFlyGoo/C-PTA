#ifndef C_PTA_TRAVERSING_TREE_H
#define C_PTA_TRAVERSING_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void InorderTraversal(BinTree BT);

void PreorderTraversal(BinTree BT);

void PostorderTraversal(BinTree BT);

void LevelorderTraversal(BinTree BT);

#endif //C_PTA_TRAVERSING_TREE_H
