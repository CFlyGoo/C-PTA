#include "traversing-tree.h"

BinTree CreatBinTree(); /* 实现细节忽略 */

BinTree newNode(ElementType);

int main() {
    BinTree BT = CreatBinTree();
    printf("Inorder:");
    InorderTraversal(BT);
    printf("\n");
    printf("Preorder:");
    PreorderTraversal(BT);
    printf("\n");
    printf("Postorder:");
    PostorderTraversal(BT);
    printf("\n");
    printf("Levelorder:");
    LevelorderTraversal(BT);
    printf("\n");
    return 0;
}

BinTree CreatBinTree() {
    BinTree A = newNode('A');
    BinTree B = newNode('B');
    BinTree C = newNode('C');
    BinTree D = newNode('D');
    BinTree E = newNode('E');
    BinTree F = newNode('F');
    BinTree G = newNode('G');
    BinTree H = newNode('H');
    BinTree I = newNode('I');

    A->Left = B;
    A->Right = C;

    B->Left = D;
    B->Right = F;
    F->Left = E;

    C->Left = G;
    C->Right = I;
    G->Right = H;
    return A;
}

BinTree newNode(ElementType elem) {
    BinTree tree = malloc(sizeof(struct TNode));
    tree->Data = elem;
    tree->Left = NULL;
    tree->Right = NULL;
    return tree;
}