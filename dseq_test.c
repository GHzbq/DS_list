#include "dseqlist.h"

int main(void)
{
    dseqlist dsl;

    
    dseqlistInit(&dsl);

    pushBack_DSL(&dsl, 1);
    pushBack_DSL(&dsl, 2);
    pushBack_DSL(&dsl, 3);
    pushBack_DSL(&dsl, 4);
    pushBack_DSL(&dsl, 5);
    pushBack_DSL(&dsl, 6);
    printf("size = %d\n", size_DSL(&dsl));
    printf("capacity = %d\n", capacity_DSL(&dsl));
    if(Empty_DSL(&dsl) != 0)
    {
        printf("empty\n");
    }
    else
    {
        printf("not empty\n");
    }
    clear_DSL(&dsl);
    printf("size = %d\n", size_DSL(&dsl));
    printf("capacity = %d\n", capacity_DSL(&dsl));
    if(Empty_DSL(&dsl) != 0)
    {
        printf("empty\n");
    }
    else
    {
        printf("not empty\n");
    }
    dseqlistDestory(&dsl);
//     pushBack_DSL(&dsl, 1);
//     pushBack_DSL(&dsl, 2);
//     pushBack_DSL(&dsl, 3);
//     pushBack_DSL(&dsl, 4);
//     pushBack_DSL(&dsl, 5);
//     pushBack_DSL(&dsl, 6);
//     pushBack_DSL(&dsl, 7);
//     pushBack_DSL(&dsl, 8);
//     print_DSL(&dsl);
//     insertPos_DSL(&dsl, 2, 18);
//     print_DSL(&dsl);
//     deletePos_DSL(&dsl, 2);
//     print_DSL(&dsl);
    // pushFront_DSL(&dsl, 6);
    // pushFront_DSL(&dsl, 5);
    // pushFront_DSL(&dsl, 4);
    // pushFront_DSL(&dsl, 3);
    // pushFront_DSL(&dsl, 2);
    // pushFront_DSL(&dsl, 1);
    // print_DSL(&dsl);
    // popFront_DSL(&dsl);
    // popFront_DSL(&dsl);
    // popFront_DSL(&dsl);
    // print_DSL(&dsl);

//     pushBack_DSL(&dsl, 1);
//     pushBack_DSL(&dsl, 2);
//     pushBack_DSL(&dsl, 3);
//     pushBack_DSL(&dsl, 4);
//     pushBack_DSL(&dsl, 5);
//     pushBack_DSL(&dsl, 6);
//     print_DSL(&dsl);
//     popBack_DSL(&dsl);
//     popBack_DSL(&dsl);
//     popBack_DSL(&dsl);
//     popBack_DSL(&dsl);
//     print_DSL(&dsl);

    return 0;
}
