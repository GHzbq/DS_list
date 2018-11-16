#include "seqlist.h"

// 静态顺序表初始化
void seqlistInit(pseqlist ps)
{
    if (ps == NULL)
    {
        return;
    }
    
    memset(ps->_array, 0x00, MAX_SIZE); 
    ps->_size = 0;
}
// 尾插
void pushBack(pseqlist ps, DataType data)
{
    if(ps == NULL)
    {
        return;
    }
    if(ps->_size == MAX_SIZE)
    {
        return;
    }
    
    // 参数检验合格 插入元素
    ps->_array[ps->_size++] = data;
}
// 尾删
void popBack(pseqlist ps)
{
    if(ps == NULL)
    {
        return;
    }

    // 删除元素
    --ps->_size;
}
// 头插
void pushFront(pseqlist ps, DataType data)
{
    if(ps == NULL)
    {
        return;
    }
    if(ps->_size == MAX_SIZE)
    {
        return;
    }

    // 搬移元素
    int size = ps->_size;
    for(; size != 0; --size)
    {
        ps->_array[size] = ps->_array[size - 1];
    }
    // 放置元素
    ps->_array[size] = data;
    ++ps->_size;
}
// 头删
void popFront(pseqlist ps)
{
    if (ps == NULL)
    {
        return;
    }
    if(ps->_size == 0)
    {
        return;
    }
    // 1. 搬移元素
    int i = 0;
    int size = ps->_size;
    for(; i < size; ++i)
    {
        ps->_array[i] = ps->_array[i+1];
    }
    --ps->_size;
}
// 遍历
void print(pseqlist ps)
{
    if(ps == NULL)
    {
        return ;
    }
    for(int i = 0; i < ps->_size; ++i)
    {
        printf("%d ", ps->_array[i]);
    }
    printf("\n");
}
// pos 位置插入 data
void insertPos(pseqlist ps, int pos, DataType data)
{
    // 1. 参数检验
    if(ps == NULL)
    {
        return;
    }
    if(ps->_size == MAX_SIZE)
    {
        return;
    }
    if(pos < 0 || pos > ps->_size)
    {
        return;
    }
    // 搬移元素
    for(int i = ps->_size - 1; i >= pos; --i)
    {
        ps->_array[i+1] = ps->_array[i];
    }
    // 在 pos 位置插入元素
    ps->_array[pos] = data;
    ++ps->_size;
}
// 删除 pos 位置元素
void deletePos(pseqlist ps, int pos)
{
    if(ps == NULL)
    {
        return ;
    }
    if(ps->_size == 0 || pos < 0 || pos >= ps->_size)
    {
        return;
    }
    // 搬移元素
    for(int i = pos; i < ps->_size; ++i)
    {
        ps->_array[i] = ps->_array[i + 1];
    }
    //
    --ps->_size;
}
// 查找 data 在顺序表的第一次出现 找到返回下标，没找到返回 -1
int findPos(pseqlist ps, DataType data)
{
    if(ps == NULL)
    {
        return -1;
    }
    for(int i = 0; i < ps->_size; ++i)
    {
        if(ps->_array[i] == data)
        {
            return i;
        }
    }

    return -1;
}
// 删除顺序表中第一个 data 元素
void Remove(pseqlist ps, DataType data)
{
    if(ps == NULL)
    {
        return;
    }
    for(int i = 0; i < ps->_size; ++i)
    {
        if(ps->_array[i] == data)
        {
            for(int j = i; j < ps->_size; ++j)
            {
                ps->_array[j] = ps->_array[j+1];
            }
            --ps->_size;
            return;
        }
    }
}
// 删除顺序表中所有 data 元素
void RemoveAll(pseqlist ps, DataType data)
{
    if(ps == NULL)
    {
        return;
    }
    for(int i = 0; i < ps->_size; ++i)
    {
        if(ps->_array[i] == data)
        {
            for(int j = i; j < ps->_size; ++j)
            {
                ps->_array[j] = ps->_array[j+1];
            }
            --ps->_size;
            --i;
        }
    }
}

