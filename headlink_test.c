#include "headlinklist.h"

int main(void)
{
    phlinklist head;

    headLinkListInit(&head);
    pushFront_HLL(head, 6);
    pushFront_HLL(head, 5);
    pushFront_HLL(head, 4);
    pushFront_HLL(head, 3);
    pushFront_HLL(head, 2);
    pushFront_HLL(head, 1);
    print_HLL(head);
    phlinklist ret_mid = MiddleNode(head);
    if(ret_mid != NULL)
    {
        printf("%d\n", ret_mid->_data);
    }
    // pushFront_HLL(head, 6);
    // pushFront_HLL(head, 5);
    // pushFront_HLL(head, 4);
    // pushFront_HLL(head, 3);
    // pushFront_HLL(head, 2);
    // pushFront_HLL(head, 1);
    // print_HLL(head);
    // popFront_HLL(head);
    // popFront_HLL(head);
    // popFront_HLL(head);
    // popFront_HLL(head);
    // print_HLL(head);
    // popFront_HLL(head);
    // popFront_HLL(head);
    // print_HLL(head);
// 
//     pushBack_HLL(head, 1);
//     pushBack_HLL(head, 2);
//     pushBack_HLL(head, 3);
//     pushBack_HLL(head, 4);
//     pushBack_HLL(head, 5);
//     pushBack_HLL(head, 6);
//     print_HLL(head);
//     popBack_HLL(head);
//     popBack_HLL(head);
//     popBack_HLL(head);
//     popBack_HLL(head);
//     print_HLL(head);
//     popBack_HLL(head);
//     popBack_HLL(head);
//     print_HLL(head);

    return 0;
}
