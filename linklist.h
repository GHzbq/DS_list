#pragma once 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

// 无头单链表的结构
typedef struct linklist
{
    struct linklist * _next;
    DataType _data;
}linklist, *plinklist;

// 尾插
void pushBack_LL(plinklist * pl, DataType data);

// 尾删
void popBack_LL(plinklist * pl);

// 头插
void pushFront_LL(plinklist * pl, DataType data);

// 头删
void popFront_LL(plinklist * pl);

// 遍历打印单链表
void print_LL(plinklist pl);

// 查找链表中第一个值等于data 的元素
// 找到了返回该节点地址
// 找不到返回 NULL
plinklist findData_LL(plinklist pl, DataType data);

// 销毁链表
void linklistDestory(plinklist * pl);

// 删除链表中等于给定值 val 的所有节点
plinklist deleteValAll_LL(plinklist * pl, DataType data);

// 反转一个单链表
void reverse_LL(plinklist * pl);

// 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个
// 中间结点。
//void 这个目前解决不了 这是不带头节点的单链表

// 输入一个链表，输出该链表中倒数第k个结点。
void print_KthLastNode_LL(plinklist pl, int K);

//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成
//的。
plinklist mergeTwoOrderedList(plinklist * pl1, plinklist * pl2);

// 编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
plinklist divListByX_LL(plinklist pl, DataType x);

// 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头
// 指针。
plinklist deleteAllRepetNode_LL(plinklist pl);

// 链表的回文结构。
int chkPalindrome(plinklist pl);

// 输入两个链表，找出它们的第一个公共结点
// 如果两个链表没有交点，返回 null.
// 在返回结果后，两个链表仍须保持原有的结构。
// 可假定整个链表结构中没有循环。
// 程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
plinklist commonNodeOfTwoList_LL(plinklist pl1, plinklist pl2);

//  给定一个链表，判断链表中是否有环
int IsCircleInList(plinklist pl);

//  给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//
//  说明：不允许修改给定的链表。
//
//  进阶：
//  你是否可以不用额外空间解决此题？
plinklist entranceOfCircle(plinklist pl);

// 环的长度
int LenthOfCircle(plinklist pl);

// 如何将有环的链表变成单链表
plinklist ListWithCircle_to_List_LL(plinklist pl);

// 判断两个链表是否有交点，如果相交，如何找到第一个相交节点？
int IsCross_CrossLocal(plinklist pl1, plinklist pl2,  plinklist * point);



// 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
// 要求返回这个链表的深度拷贝
//
