#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int DataType;

typedef struct dseqlist
{
    DataType * _array; // 数据块指针
    int _capacity; // 顺序表的容量
    int _size; // 顺序表中实际元素个数
}dseqlist, * pdseqlist;

// 顺序表初始化
void dseqlistInit(pdseqlist ps);

// 尾插
void pushBack_DSL(pdseqlist ps, DataType data);

// 尾删
void popBack_DSL(pdseqlist ps);

// 头插
void pushFront_DSL(pdseqlist ps, DataType data);

// 头删
void popFront_DSL(pdseqlist ps);

// 指定位置插入
void insertPos_DSL(pdseqlist ps, int pos, DataType data);

// 指定位置删除
void deletePos_DSL(pdseqlist ps, int pos);

// 在顺序表找指定元素，找到返回下标，找不到返回 -1
int Find_DSL(pdseqlist ps, DataType data);

// 删除第一个 data 
void Remove_DSL(pdseqlist ps, DataType data);

// 删除所有 data 
void RemoveAll_DSL(pdseqlist ps, DataType data);

// 遍历打印顺序表
void print_DSL(pdseqlist ps);

// 获取当前顺序表元素大小
int size_DSL(pdseqlist ps);

// 获取容量
int capacity_DSL(pdseqlist ps);

// 判空 空---->0  非空---->1
int Empty_DSL(pdseqlist ps);

// 清空顺序表元素，结构不变
void clear_DSL(pdseqlist ps);

// 冒泡排序，flag 为 0 升序， 为 1 降序
void bubbleSort_DSL(pdseqlist ps, int flag);

// 选择排序 flag 为 0 升序
void selectSort_DSL(pdseqlist ps, int flag);

// 销毁顺序表
void dseqlistDestory(pdseqlist ps);

