#include "linklist.h"

int main(void)
{
   //  plinklist ll = NULL;
   //  plinklist ll2 = NULL;
   //  pushFront_LL(&ll, 1);
   //  pushFront_LL(&ll, 2);
   //  pushFront_LL(&ll, 3);
   //  pushFront_LL(&ll, 4);
   //  pushFront_LL(&ll, 5);
   //  pushFront_LL(&ll, 6);

   //  print_LL(ll);
   //  plinklist ret_find = findData_LL(ll, 5);
   //  ll2 = ret_find;
   //  pushFront_LL(&ll2, 6);
   //  pushFront_LL(&ll2, 7);
   //  pushFront_LL(&ll2, 8);
   //  print_LL(ll2);



    plinklist ll = NULL;
    pushFront_LL(&ll, 6);
    pushFront_LL(&ll, 5);
    pushFront_LL(&ll, 4);
    pushFront_LL(&ll, 3);
    pushFront_LL(&ll, 2);
    pushFront_LL(&ll, 1);
    print_LL(ll);

    plinklist n1 = findData_LL(ll, 6);
    printf("%d\n", n1->_data);
    plinklist n2 = findData_LL(ll, 5);
    printf("%d\n", n2->_data);
    n1->_next = n2;

    plinklist ll2 = NULL;
    ll2 = findData_LL(ll, 3);
    pushFront_LL(&ll2, 0);
    plinklist point = NULL;
    int ret = IsCross_CrossLocal(ll, ll2, &point);
    if(ret)
    {
        printf("相交, 交点是：%d\n", point->_data);
    }
    else
    {
        printf("不相交\n");
    }
    // if(IsCircleInList(ll)) 
    // {
    //     printf("有环!!!\n");
    // }
    // else
    // {
    //     printf("没环！！\n");
    // }

    // plinklist entrance = entranceOfCircle(ll);
    // if(entrance == NULL)
    // {
    //     printf("程序错了！\n");
    // }
    // else
    // {
    //     printf("环的入口是：%d\n", entrance->_data);
    // }
    // int len = LenthOfCircle(ll);
    // if(len != 0)
    // {
    //     printf("环的长度是：%d\n", len);
    // }

    // // 解环
    // print_LL(ListWithCircle_to_List_LL(ll)) ;
    // 
//     printf("%d\n", chkPalindrome(ll));

//     print_KthLastNode_LL(ll, 1);
//     reverse_LL(&ll);
//     print_LL(ll);
//     print_KthLastNode_LL(ll, 1);
    // pushBack_LL(&ll, 1);
    // pushBack_LL(&ll, 2);
    // pushBack_LL(&ll, 3);
    // pushBack_LL(&ll, 2);
    // pushBack_LL(&ll, 2);
    // pushBack_LL(&ll, 2);
    // pushBack_LL(&ll, 1);
    // print_LL(ll);
    // deleteValAll_LL(&ll, 2);
    // print_LL(ll);
    // deleteValAll_LL(&ll, 1);
    // print_LL(ll);

//     pushBack_LL(&ll, 1);
//     pushBack_LL(&ll, 2);
//     print_LL(ll);
//     popBack_LL(&ll);
//     popBack_LL(&ll);
//     print_LL(ll);
//     pushFront_LL(&ll, 4);
//     pushFront_LL(&ll, 3);
//     pushFront_LL(&ll, 2);
//     pushFront_LL(&ll, 1);
//     print_LL(ll);
//     popFront_LL(&ll);
//     popFront_LL(&ll);
//     popFront_LL(&ll);
//     popFront_LL(&ll);
//     print_LL(ll);


    return 0;
}
