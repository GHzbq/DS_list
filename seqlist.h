#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define  MAX_SIZE 10

typedef int DataType;

typedef struct seqlist
{
    DataType _array[MAX_SIZE]; // 数据块指针
    int _size; // 实际顺序表元素个数
}seqlist, *pseqlist;

// 静态顺序表初始化
void seqlistInit(pseqlist ps);
// 尾插
void pushBack(pseqlist ps, DataType data);
// 尾删
void popBack(pseqlist ps);
// 头插
void pushFront(pseqlist ps, DataType data);
// 头删
void popFront(pseqlist ps);
// 遍历
void print(pseqlist ps);
// pos 位置插入 data
void insertPos(pseqlist ps, int pos, DataType data);
// 删除 pos 位置元素
void deletePos(pseqlist ps, int pos);
// 查找 data 在顺序表的第一次出现 找到返回下标，没找到返回 -1
int findPos(pseqlist ps, DataType data);
// 删除顺序表中第一个 data 元素
void Remove(pseqlist ps, DataType data);
// 删除顺序表中所有 data 元素
void RemoveAll(pseqlist ps, DataType data);


