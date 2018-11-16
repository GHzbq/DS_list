#include "linklist.h"

plinklist BuyNewListNode(DataType data)
{
    plinklist _new = (plinklist)malloc(sizeof(linklist));
    if(_new == NULL)
    {
        assert(0);
        return NULL;
    }
    _new->_next = NULL;
    _new->_data = data;
    return _new;
}

// 尾插
void pushBack_LL(plinklist * pl, DataType data)
{
    if(pl == NULL)
    {
        return;
    }
    plinklist _new = BuyNewListNode(data);
    if(*pl == NULL)
    {
        *pl = _new;
        return;
    }
    plinklist cur = *pl;
    while(cur->_next)
    {
        cur = cur->_next;
    }
    cur->_next = _new;
}

// 尾删
void popBack_LL(plinklist * pl)
{
    if(pl == NULL)
    {
        return;
    }
    if(*pl == NULL)
    {
        return;
    }

    if((*pl)->_next == NULL)
    {
        free(*pl);
        *pl = NULL;
        return;
    }
    plinklist cur = *pl;
    plinklist pre = NULL;
    while(cur->_next)
    {
        pre = cur;
        cur = cur->_next;
    }

    pre->_next = NULL;
    free(cur);
    cur = NULL;
}

// 头插
void pushFront_LL(plinklist * pl, DataType data)
{
    if(NULL == pl)
    {
        return;
    }
    plinklist _new = BuyNewListNode(data);
    if((*pl) == NULL)
    {
        *pl = _new;
        return;
    }
    
    _new->_next = *pl;
    *pl = _new;
}

// 头删
void popFront_LL(plinklist * pl)
{
    if(NULL == pl)
    {
        return;
    }
    if(*pl == NULL)
    {
        return;
    }
    plinklist del = *pl;
    *pl = (*pl)->_next;
    free(del);
    del = NULL;
}

// 销毁链表
void linklistDestory(plinklist * pl)
{
    if(NULL == pl)
    {
        return;
    }

    // 一直头删就完了
    plinklist del = (*pl)->_next;
    while(del)
    {
        (*pl)->_next = ((*pl)->_next)->_next;
        free(del);
        del = (*pl)->_next;
    }

    // 释放第一个节点
    free(*pl);
    *pl = NULL;
}

// 查找链表中第一个值等于data 的元素
// 找到了返回该节点地址
// 找不到返回 NULL
plinklist findData_LL(plinklist pl, DataType data)
{
    while(pl)
    {
        if(pl->_data == data)
        {
            return pl;
        }

        pl = pl->_next;
    }

    return NULL;
}

// 遍历打印单链表
void print_LL(plinklist pl)
{
    while(pl)
    {
        printf("%d -> ", pl->_data);
        pl = pl->_next;
    }
    printf("NULL\n");
}

// 删除链表中等于给定值 val 的所有节点
plinklist deleteValAll_LL(plinklist * pl, DataType data)
{
    if(NULL == pl)
    {
        return NULL;
    }
    if(*pl == NULL)
    {
        return *pl;
    }

    plinklist cur = *pl;
    plinklist pre = NULL;
    while(cur)
    {
        if(cur->_data == data)
        {
            if(pre == NULL)
            {
                (*pl) = cur->_next;
                free(cur);
                cur = (*pl);
                continue;
            }
            else
            {
                pre->_next = cur->_next;
                free(cur);
                cur = pre->_next;
                continue;
            }
        }
        pre = cur;
        cur = cur->_next;
    }
    return *pl;
}

// 反转一个单链表
void reverse_LL(plinklist * pl)
{
    if(NULL == pl)
    {
        return;
    }
    plinklist cur = *pl;
    plinklist pre = NULL;
    while(cur)
    {
        plinklist next = cur->_next;
        cur->_next = pre;
        pre = cur; // 改变头指针指向
        *pl = pre;
        cur = next;
    }
}

// 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个
// 中间结点。
//void 这个目前解决不了 这是不带头节点的单链表

// 输入一个链表，输出该链表中倒数第k个结点。
void print_KthLastNode_LL(plinklist pl, int K)
{
    plinklist fast = pl;
    plinklist slow = pl;
    for(int i = 0; i < K; ++i)
    {
        if(fast == NULL)
        {
            return;
        }
        fast = fast->_next;
    }
    while(fast)
    {
        fast = fast->_next;
        slow = slow->_next;
    }

    printf("%d\n", slow->_data);
}

//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成
//的。
plinklist mergeTwoOrderedList(plinklist * pl1, plinklist * pl2)
{
    // 参数检验
    if(pl1 == NULL || pl2 == NULL)
    {// 参数检验不合格，不用操作，直接返回，也操作不了
        return NULL;
    }

    // 记录头结点
    plinklist head = NULL;
    plinklist cur = NULL;
    
    if(*pl1 && *pl2)
    {
        if((*pl1)->_data < (*pl2)->_data)
        {
            head = *pl1;
            *pl1 = (*pl1)->_next;
            cur = head;
        }
        else
        {
            head = *pl2;
            *pl2 = (*pl2)->_next;
            cur = head;
        }
    }
    while(*pl1 && *pl2)
    {
        if((*pl1)->_data < (*pl2)->_data)
        {
            cur->_next = *pl1;
            *pl1 = (*pl1)->_next;
            cur = cur->_next;
        }
        else
        {
            cur->_next = *pl2;
            *pl2 = (*pl2)->_next;
            cur = cur->_next;
        }
    }

    // 合并剩余没有合并的数据
    if(*pl1 != NULL)
    {
        cur->_next = *pl1;
    }
    if(*pl2 != NULL)
    {
        cur->_next = *pl2;
    }

    return head;
}

// 编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
plinklist divListByX_LL(plinklist pl, DataType x)
{
    plinklist left = NULL;
    plinklist right = NULL;
    plinklist leftcur = pl;
    plinklist rightcur = pl;
    while(pl)
    {
        if(pl->_data < x)
        {
            if(left == NULL)
            {
                left = pl;
            }
            else
            {
                leftcur->_next = pl;
            }
            leftcur = pl;
        }
        else
        {
            if(right == NULL)
            {
                right = pl;
            }
            else
            {
                rightcur->_next = pl;
            }
        }
        pl = pl->_next;
    }
    if(leftcur == NULL)
    {
        return rightcur;
    }
    else
    {
        rightcur->_next = right;
        return left;
    }
}

// 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，
// 返回链表头指针。
plinklist deleteAllRepetNode_LL(plinklist pl)
{
    plinklist head = pl;
    plinklist pre = NULL;
    plinklist cur = pl;

    while(cur)
    {
        if(pre == NULL)
        {
            pre = cur;
        }
        else
        {
            if(pre->_data == cur->_data)
            {
                pre->_next = cur->_next;
                free(cur);
                cur = pre;
            }
            else
            {
                pre = cur;
            }
        }
        cur = cur->_next;
    }

    return head;
}

// 链表的回文结构。
int chkPalindrome(plinklist pl)
{
    // 其实这道题最方便的解法是用栈了
    // 但是这是 C 语言，没有标准库，但是我们可以用链表模拟一个栈
    // 这样空间复杂度就是 O(n) 了
    // 本人惭愧。目前还没有找到其他思路
    plinklist s = NULL; // 我们创建 链表s 对pl遍历，然后头插到 链表s 中
    plinklist plcur = pl;
    while(plcur)
    {
        pushFront_LL(&s, plcur->_data);
        plcur = plcur->_next;
    }
    // 到此我们就把链表 pl 的所有元素逆置到 链表s 中了
    // 然后我们比对
    plinklist scur = s;
    plcur = pl;
    while(plcur)
    {
        if(plcur->_data != scur->_data)
        {
            return 0;
        }
        plcur = plcur->_next;
        scur = scur->_next;
    }

    // 能走到这说明 链表pl 是回文结构
    // 我们在返回之前，把 链表s 销毁掉
    linklistDestory(&s);
    // 然后返回真
    return 1;
}

// 输入两个链表，找出它们的第一个公共结点
plinklist commonNodeOfTwoList_LL(plinklist pl1, plinklist pl2)
{
    // 拿到这个题，想到的第一种解决方法是暴力解决
    // 遍历第一个链表的每一个节点，每遍历一个节点，在第二个链表上顺序遍历每个节点
    // 首先这种方法可以解决问题，但是时间复杂度肯定是 O(n^2);
    // 
    // 我们考虑另一种方式
    // 先把两个链表遍历一遍，得到两个链表的长度
    // 然后让长的链表先走若干步
    // 然后两个链表一起走
    // 这样找到的第一个相同节点就是他们的公共节点，这样的时间复杂度是 O(n)
    int len1 = 0;
    int len2 = 0;
    plinklist p1 = pl1;
    plinklist p2 = pl2;
    while(p1)
    {
        ++len1;
        p1 = p1->_next;
    }
    while(p2)
    {
        ++len2;
        p2 = p2->_next;
    }
    p1 = pl1;
    p2 = pl2;
    int diff = len1 - len2;
    if(diff > 0)
    {
        while(diff--)
        {
            p1 = p1->_next;
        }
    }
    else if(diff < 0)
    {
        while(diff++)
        {
            p2 = p2->_next;
        }
    }

    // 然后两个链表一起走
    while(p1)
    {
        if(p1 == p2)
        {
            return p1;
        }
        p1 = p1->_next;
        p2 = p2->_next;
    }

    return NULL;
}

//  给定一个链表，判断链表中是否有环
int IsCircleInList(plinklist pl)
{
    plinklist fast = pl;
    plinklist slow = pl;

    while(fast)
    {
        if(fast == NULL || fast->_next == NULL || fast->_next->_next == NULL)
        {
            return 0;
        }
        slow = slow->_next;
        fast = fast->_next->_next;
        if(fast == slow)
        {
            return 1;
        }
    }
    return 0;
}

//  给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 NULL
plinklist entranceOfCircle(plinklist pl)
{
    plinklist fast = pl;
    plinklist slow = pl;

    plinklist meet = NULL;
    while(fast)
    {
        if(fast->_next == NULL || fast->_next->_next == NULL)
        {
            return NULL;
        }
        slow = slow->_next;
        fast = fast->_next->_next;
        if(fast == slow)
        {
            meet = fast;
            break;
        }
    }

    // 链表为空或者不带环 直接返回
    if(fast == NULL)
    {
        return NULL;
    }

    // 到此已经可以确定链表带环了
    fast = pl;
    slow = meet;
    while(fast != slow)
    {
        fast = fast->_next;
        slow = slow->_next;
    }

    return fast;
}

// 如何将有环的链表变成单链表
plinklist ListWithCircle_to_List_LL(plinklist pl)
{
    plinklist fast = pl;
    plinklist slow = pl;

    plinklist meet = NULL;
    while(fast)
    {
        if(fast->_next == NULL || fast->_next->_next == NULL)
        {
            return NULL;
        }
        slow = slow->_next;
        fast = fast->_next->_next;
        if(fast == slow)
        {
            meet = fast;
            break;
        }
    }

    // 链表为空或者不带环 直接返回
    if(fast == NULL)
    {
        return NULL;
    }

    // 到此已经可以确定链表带环了
    fast = pl;
    slow = meet;
    while(fast != slow)
    {
        fast = fast->_next;
        slow = slow->_next;
    }
    // 到此 fast 里保存的就是 环的入口
    slow = fast;
    while(slow->_next != fast)
    {
        slow = slow->_next;
    }

    // 这里 slow 保存的就是环内入口的前一个节点
    // 只要把它解开就相当于解环了
    slow->_next = NULL;

    return pl;
}   

// 环的长度
int LenthOfCircle(plinklist pl)
{
    plinklist fast = pl;
    plinklist slow = pl;

    plinklist meet = NULL;
    while(fast)
    {
        if(fast->_next == NULL || fast->_next->_next == NULL)
        {
            return 0;
        }
        slow = slow->_next;
        fast = fast->_next->_next;
        if(fast == slow)
        {
            meet = fast;
            break;
        }
    }

    // 链表为空或者不带环 直接返回
    if(fast == NULL)
    {
        return 0;
    }

    // 到此已经可以确定链表带环了
    // 让 slow 走一圈，再次走到 meet 就是环的长度
    int len = 1;
    slow = slow->_next;
    while(slow != meet)
    {
        ++len;
        slow = slow->_next;
    }
 
    return len;
}



// 判断两个链表是否有交点，如果相交，如何找到第一个相交节点？
int IsCross_CrossLocal(plinklist pl1, plinklist pl2,  plinklist * point)
{
    // 1. 判断链表是否带环
    // 2. 如果两个链表都不带环，直接看最后一个节点是否相等，相等就相交，不相等肯定不相交
    // 3. 如果一个带环，一个不带环 ---- 肯定不相交
    // 4. 如果两个都相交，判断第一个链表 fast 和 slow 相遇的相遇点 meet1 是否在第二个链表中，
    //    在的话，就相交，不在就不相交
    plinklist fast1 = pl1;
    plinklist slow1 = pl1;
    plinklist fast2 = pl2;
    plinklist slow2 = pl2;
    plinklist meet1 = NULL;
    plinklist meet2 = NULL;

    // 先判断第一个链表是否带环
    while(fast1)
    {
        if(fast1->_next == NULL || fast1->_next->_next == NULL)
        {
            // 肯定不是环
            break;
        }
        fast1 = fast1->_next->_next;
        slow1 = slow1->_next;
        if(fast1 == slow1)
        {
            meet1 = fast1;
            break;
        }
    }

    // 判断第二个链表是否带环
    while(fast2)
    {
        if(fast2->_next == NULL || fast2->_next->_next == NULL)
        {
            // 肯定不是环
            break;
        }
        fast2 = fast2->_next->_next;
        slow2 = slow2->_next;
        if(fast2 == slow2)
        {
            meet2 = fast2;
            break;
        }
    }

    if(meet1 == NULL && meet1 == NULL)
    {
        // 这种情况是，两个链表都不带环
        // 也可能是两链表是空链表
        // 我们判断最后一个节点是否相等
        int len1 = 0;
        int len2 = 0;
        plinklist pre1 = NULL;
        plinklist pre2 = NULL;
        fast1 = pl1;
        fast2 = pl2;
        while(fast1)
        {
            ++len1;
            pre1 = fast1;
            fast1 = fast1->_next;
        }
        while(fast2)
        {
            ++len2;
            pre2 = fast2;
            fast2 = fast2->_next;
        }
        if(len1 != 0 && pre1 == pre2)
        {
            // 相交 返回1
            // 我们先把交点求出来再返回
            int diff = len1 - len2;
            fast1 = pl1;
            fast2 = pl2;
            if(diff > 0)
            {
                while(diff--)
                {
                    fast1 = fast1->_next;
                }
            }
            else if(diff < 0)
            {
                while(diff++)
                {
                    fast2 = fast2->_next;
                }
            }

            // 然后两个链表一起走，相遇就是第一个交点
            while(fast1)
            {
                if(fast1 == fast2)
                {
                    *point = fast1;
                    return 1;
                }
                fast1 = fast1->_next;
                fast2 = fast2->_next;
            }
        }// end of if 结束两个相交的非带环链表，并返回
        
        // 这种情况是两个链表都不带环，并且不相交
        *point = NULL; // 相交点为空
        return 0; 
    }// end of if 结束两个链表不带环
    else if(meet1 != NULL && meet2 != NULL)
    {
        // 对于两个链表都带环的情况
        // 让 fast1 从 meet1 开始走，走一圈，如果遇到 meet2 那两个链表就相交
        int flag = 0;
        fast1 = meet1;
        do 
        {
            if(fast1 == meet2)
            {
                flag = 1;
                break;
            }
            fast1 = fast1->_next;
        }while(fast1 != meet1);
        if(flag)
        {
            // 这种情况我们要求两个链表第一个交点
            // 他们环的特征肯定是相同的
            // 所以第一个交点肯定在入环之前，至少也在环的入口点
            // 所以也是一个 Y 字
            // 我们不妨把个链表的终点放在 meet1 处，这样就转化为两个不带环链表相交求交点了
            int len1 = 0;
            int len2 = 0;
            plinklist pre1 = NULL;
            plinklist pre2 = NULL;
            fast1 = pl1;
            fast2 = pl2;
            while(fast1 != meet1)
            {
                ++len1;
                pre1 = fast1;
                fast1 = fast1->_next;
            }
            while(fast2 != meet1)
            {
                ++len2;
                pre2 = fast2;
                fast2 = fast2->_next;
            }
            if(len1 != 0 && pre1 == pre2)
            {
                // 相交 返回1
                // 我们先把交点求出来再返回
                int diff = len1 - len2;
                fast1 = pl1;
                fast2 = pl2;
                if(diff > 0)
                {
                    while(diff--)
                    {
                        fast1 = fast1->_next;
                    }
                }
                else if(diff < 0)
                {
                    while(diff++)
                    {
                        fast2 = fast2->_next;
                    }
                }

                // 然后两个链表一起走，相遇就是第一个交点
                while(fast1)
                {
                    if(fast1 == fast2)
                    {
                        *point = fast1;
                        return 1;
                    }
                    fast1 = fast1->_next;
                    fast2 = fast2->_next;
                }
            }// end of if 结束两个相交的带环链表，并返回


        }

    }// end of if 两个链表都带环
    else
    {
        // 两个链表一个带环一个不带环
        // 这种情况，肯定不相交
        *point = NULL;
        return 0;
    }

    *point = NULL;
    return 0;
}


// 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
// 要求返回这个链表的深度拷贝

