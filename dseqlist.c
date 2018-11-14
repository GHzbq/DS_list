#include "dseqlist.h"

void checkCapacity(pdseqlist ps)
{
    if(ps->_size != ps->_capacity)
    {
        return;
    }
    DataType * _new = (DataType *)malloc(sizeof(DataType) * (ps->_capacity) * 2);
    if(_new == NULL)
    {
        return;
    }
    // 数据拷贝
    memcpy(_new, ps->_array, sizeof(DataType) * ps->_capacity);
    free(ps->_array);
    ps->_array = _new;
    ps->_capacity *= 2;
}

// 顺序表初始化
void dseqlistInit(pdseqlist ps)
{
    if (ps == NULL)
    {
        return;
    }

    DataType *_new = (DataType *)malloc(sizeof(DataType) * 10); // 初始顺序表的容量为 10
    if(_new == NULL)
    {
        return;
    }
    ps->_array = _new;
    ps->_capacity = 10;
    ps->_size = 0;
}

// 尾插
void pushBack_DSL(pdseqlist ps, DataType data)
{
    if(ps == NULL)
    {
        return ;
    }
    
    // 检查容量
    checkCapacity(ps);
    // 插入元素
    ps->_array[ps->_size] = data;
    ++ps->_size;
}

// 尾删
void popBack_DSL(pdseqlist ps)
{
    if(ps == NULL)
    {
        return ;
    }
    if(ps->_size == 0)
    {
        return;
    }
    --ps->_size;
}

// 头插
void pushFront_DSL(pdseqlist ps, DataType data)
{
    if(ps == NULL)
    {
        return;
    }
    // 检查容量
    checkCapacity(ps);
    // 搬移元素
    for(int i = ps->_size; i != 0; --i)
    {
        ps->_array[i] = ps->_array[i - 1];
    }
    // 放置元素
    ps->_array[0] = data;
    ++ps->_size;
}

// 头删
void popFront_DSL(pdseqlist ps)
{
    if(ps == NULL)
    {
        return;
    }
    if(ps->_size == 0)
    {
        return;
    }

    // 搬移元素
    for(int i = 0; i < ps->_size; ++i)
    {
        ps->_array[i] = ps->_array[i+1];
    }
    
    --ps->_size;
}

// 指定位置插入
void insertPos_DSL(pdseqlist ps, int pos, DataType data)
{
    if(ps == NULL)
    {
        return ;
    }
    if(pos < 0 || pos > ps->_size)
    {
        return;
    }
    checkCapacity(ps);
    // 搬移元素
    for(int i = ps->_size; i > pos; --i)
    {
        ps->_array[i] = ps->_array[i - 1];
    }
    // 插入元素
    ps->_array[pos] = data;
    ++ps->_size;
}

// 指定位置删除
void deletePos_DSL(pdseqlist ps, int pos)
{
    if(ps == NULL)
    {
        return;
    }
    if(pos < 0 || ps->_size == 0 || pos >= ps->_size)
    {
        return;
    }
    // 搬移元素
    for(int i = pos; i < ps->_size; ++i)
    {
        ps->_array[i] = ps->_array[i + 1];
    }
    --ps->_size;
}

// 在顺序表找指定元素，找到返回下标，找不到返回 -1
int Find_DSL(pdseqlist ps, DataType data)
{
    if(NULL == ps)
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

// 删除第一个 data 
void Remove_DSL(pdseqlist ps, DataType data)
{
    if(NULL == ps)
    {
        return;
    }
    // 先找到第一个 data
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

// 删除所有 data 
void RemoveAll_DSL(pdseqlist ps, DataType data)
{
    if (ps == NULL)
    {
        return;
    }
    for(int i = 0; i < ps->_size; ++i)
    {
        if(ps->_array[i] == data)
        {
            for(int j = i; j < ps->_size; ++j)
            {
                ps->_array[j] = ps->_array[j + 1];
            }
            --i;
            --ps->_size;
        }
    }
}

// 遍历打印顺序表
void print_DSL(pdseqlist ps)
{
    if (ps == NULL)
    {
        return;
    }
    for(int i = 0; i < ps->_size; ++i)
    {
        printf("%d ", ps->_array[i]);
    }
    printf("\n");
}

// 获取当前顺序表元素大小
int size_DSL(pdseqlist ps)
{
    if (NULL == ps)
    {
        return 0;
    }

    return ps->_size;
}

// 获取容量
int capacity_DSL(pdseqlist ps)
{
    if(ps == NULL)
    {
        return 0;
    }

    return ps->_capacity;
}

// 判空 空---->0  非空---->1
int Empty_DSL(pdseqlist ps)
{
    if(NULL == ps)
    {
        return 0;
    }

    return ps->_size == 0;
}

// 清空顺序表元素，结构不变
void clear_DSL(pdseqlist ps)
{
    if(ps == NULL)
    {
        return;
    }
    memset(ps->_array, 0x00, sizeof(DataType) * ps->_size);
    ps->_size = 0;
}

// 冒泡排序，flag 为 0 升序， 为 1 降序
void bubbleSort_DSL(pdseqlist ps, int flag)
{
    (void)ps;
    (void)flag;
//     if(NULL == ps)
//     {
//         return;
//     }
// 
//     for(int i = 0; i < ps->_size; ++i)
//     {
//         for(int j = 0; j < )
//     }
}

// 选择排序 flag 为 0 升序
void selectSort_DSL(pdseqlist ps, int flag)
{
    (void)ps;
    (void)flag;
}

// 销毁顺序表
void dseqlistDestory(pdseqlist ps)
{
    if(NULL == ps)
    {
        return ;
    }
    free(ps->_array);
    ps->_array = NULL;
    ps->_capacity = 0;
    ps->_size = 0;
}

