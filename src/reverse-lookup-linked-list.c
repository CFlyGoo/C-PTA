//
// 7-19 求链式线性表的倒数第K项 （20 分）
//给定一系列正整数，请设计一个尽可能高效的算法，查找倒数第K个位置上的数字。
//
//输入格式:
//输入首先给出一个正整数K，随后是若干正整数，最后以一个负整数表示结尾（该负数不算在序列内，不要处理）。
//
//输出格式:
//输出倒数第K个位置上的数据。如果这个位置不存在，输出错误信息NULL。
//
//输入样例:
//4 1 2 3 4 5 6 7 8 9 0 -1
//输出样例:
//7
//
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct node *Node;
typedef struct list* LinkedList;

struct node {
    ElementType data;
    Node pre;
    Node next;
};

struct list {
    Node head;
    Node tail;
    int size;
};

Node createNewNode(ElementType data) {
    Node node = malloc(sizeof(struct node));
    node->data = data;
    node->pre = NULL;
    node->next = NULL;
    return node;
}

LinkedList create() {
    LinkedList list = malloc(sizeof(struct list));
    Node node = createNewNode(-1);
    list->head = node;
    list->tail = node;
    list->size = 0;
    return list;
}

void insert(LinkedList list, ElementType data) {
    if (!list) return;
    Node node = createNewNode(data);
    node->pre = list->tail;
    list->tail->next = node;
    list->tail = node;
    ++list->size;
}

void lookupAndPrint(LinkedList list, int position) {
    if (!list || position <= 0 || position > list->size) {
        printf("NULL\n");
        return;
    }
    Node node = NULL;
    int idx = 1;
    if (position <= list->size / 2) {
        node = list->tail;
        while (idx++ < position)
            node = node->pre;
    } else {
        position = list->size - position + 1;
        node = list->head->next;
        while (idx++ < position)
            node = node->next;
    }
    printf("%d\n", node->data);
}

int main(void) {
    LinkedList list = create();
    int position;
    scanf("%d", &position); // NOLINT(cert-err34-c)
    int input;
    while (scanf("%d", &input) && input >= 0) // NOLINT(cert-err34-c)
        insert(list, input);
    lookupAndPrint(list, position);
    return 0;
}