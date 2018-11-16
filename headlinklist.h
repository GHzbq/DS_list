#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

// 无头单链表的结构
typedef struct linklist
{
    struct linklist * _next;
    DataType _data;
}linklist, *plinklist;


