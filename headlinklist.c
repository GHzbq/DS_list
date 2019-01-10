#include "headlinklist.h"

phlinklist BuyNewNode(DataType data)
{
    phlinklist _new = (phlinklist)malloc(sizeof(hlinklist));
    if(_new == NULL)
    {
        assert(0);
        return NULL;
    }
    _new->_data = data;
    _new->_next = NULL;
    return _new;
}

// 带头节点单链表初始化
void headLinkListInit(phlinklist * phl)
{
    if(NULL == phl)
    {
        return;
    }
    *phl = (phlinklist)malloc(sizeof(hlinklist));
    if(*phl == NULL)
    {
        assert(0);
        return;
    }
    (*phl)->_next = NULL;
}

// 尾插
void pushBack_HLL(phlinklist phl, DataType data)
{
    if(phl == NULL)
    {// 对一个已经初始化了的带头节点单链表，如果头节点为空，很明显不合法
        return;
    }
    phlinklist _new = BuyNewNode(data);
    phlinklist cur = phl;
    while(cur->_next)
    {
        cur = cur->_next;
    }
    cur->_next = _new;
}

// 尾删
void popBack_HLL(phlinklist phl)
{
    if(NULL == phl)
    {
        return;
    }
    phlinklist cur = phl->_next;
    phlinklist pre = phl;
    while(cur->_next)
    {
        pre = cur;
        cur = cur->_next;
    }

    pre->_next = NULL;
    if(cur != NULL)
    {
        free(cur);
        cur = NULL;
    }
}

// 头插
void pushFront_HLL(phlinklist phl, DataType data)
{
    if(phl == NULL)
    {
        return;
    }

    phlinklist _new = BuyNewNode(data);
    _new->_next = phl->_next;
    phl->_next = _new;
}

// 头删
void popFront_HLL(phlinklist phl)
{
    if(phl == NULL)
    {
        return;
    }

    phlinklist del = phl->_next;
    if(del != NULL)
   {
        phl->_next = del->_next;
        free(del);
        del = NULL;
    }
}

// 查找元素
// 找到了返回这个节点
// 没找到返回 NULL
phlinklist findData_HLL(phlinklist phl, DataType data)
{
    if(phl == NULL)
    {
        return NULL;
    }
    
    phlinklist cur = phl->_next;
    while(cur)
    {
        if(cur->_data == data)
        {
            return cur;
        }
        cur = cur->_next;
    }

    return NULL;
}

// 在 pos 位置之前插入元素
void insertPosFront_HLL(phlinklist pos, DataType data)
{
    phlinklist _new = BuyNewNode(pos->_data);
    _new->_next = pos->_next;
    pos->_next = _new;
    pos->_data = data;
}

// 在 pos 位置之后插入元素
void insertDataAfter_HLL(phlinklist pos, DataType data)
{
    phlinklist _new = BuyNewNode(data);
    _new->_next = pos->_next;
    pos->_next = _new;
}

// 删除 pos 位置的元素（非尾节点）
void erase_HLL(phlinklist pos)
{
    if(pos->_next == NULL)
    {// 尾节点，删不了
        return;
    }

    phlinklist del = pos->_next;
    pos->_data = del->_data;
    pos->_next = del->_next;
    free(del);
    del = NULL;
}

// 删除指定元素
void remove_HLL(phlinklist phl, DataType data)
{
    if(phl == NULL)
    {
        return;
    }

    phlinklist cur = phl->_next;
    phlinklist pre = phl;
    while(cur)
    {
        if(cur->_data == data)
        {
            pre->_next = cur->_next;
            free(cur);
            cur = pre->_next;
            return;
        }
        pre = cur;
        cur = cur->_next;
    }
}

void removeALL_HLL(phlinklist phl, DataType data)
{
    if(phl == NULL)
    {
        return;
    }

    phlinklist cur = phl->_next;
    phlinklist pre = phl;
    while(cur)
    {
        if(cur->_data == data)
        {
            pre->_next = cur->_next;
            free(cur);
            cur = pre->_next;
            continue;
        }
        pre = cur;
        cur = cur->_next;
    }
}


// 遍历打印带头节点元素
void print_HLL(phlinklist phl)
{
    if(phl == NULL)
    {
        return;
    }

    phlinklist cur = phl->_next;
    while(cur)
    {
        printf(" %d ->", cur->_data);
        cur = cur->_next;
    }
    printf(" NULL\n");
}

// 带头节点单链表销毁
void headLinkListDestory(phlinklist * phl)
{
    if(NULL == phl)
    {
        return;
    }
    if(*phl == NULL)
    {
        return;
    }
    while((*phl)->_next)
    {
        popFront_HLL(*phl);
    }
    // 最后释放头节点
    free(*phl);
    *phl = NULL;
}



// 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个
// 中间结点。
//void 这个目前解决不了 这是不带头节点的单链表
phlinklist MiddleNode(phlinklist phl)
{
    if(phl == NULL)
    {
        return NULL;
    }
    phlinklist fast = phl->_next;
    phlinklist slow = phl->_next;

    while(fast)
    {
        if(fast->_next == NULL )
        {
            return slow;
        }

        fast = fast->_next->_next;
        slow = slow->_next;
    }

    return slow;
}
