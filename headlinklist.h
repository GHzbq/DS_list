#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

// 带头节点单链表的结构
typedef struct hlinklist
{
    struct hlinklist * _next;
    DataType _data;
}hlinklist, *phlinklist;

// 带头节点单链表初始化
void headLinkListInit(phlinklist * phl);

// 尾插
void pushBack_HLL(phlinklist phl, DataType data);

// 尾删
void popBack_HLL(phlinklist phl);

// 头插
void pushFront_HLL(phlinklist phl, DataType data);

// 头删
void popFront_HLL(phlinklist phl);

// 查找元素
// 找到了返回这个节点
// 没找到返回 NULL
phlinklist findData_HLL(phlinklist phl, DataType data);

// 在 pos 位置之前插入元素
void insertPosFront_HLL(phlinklist pos, DataType data);

// 在 pos 位置之后插入元素
void insertDataAfter_HLL(phlinklist pos, DataType data);

// 删除 pos 位置的元素（非尾节点）
void erase_HLL(phlinklist pos);

// 删除指定元素
void remove_HLL(phlinklist phl, DataType data);

// 删除带头节点单链表中所有值为 data 的节点
void removeALL_HLL(phlinklist phl, DataType data);
// 遍历打印带头节点元素
void print_HLL(phlinklist phl);

// 带头节点单链表销毁
void headLinkListDestory(phlinklist * phl);


// 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个
// 中间结点。
//void 这个目前解决不了 这是不带头节点的单链表
phlinklist MiddleNode(phlinklist phl);
