#include "seqlist.h"

int main()
{
    seqlist sl;

    pushBack(&sl, 1);
    pushBack(&sl, 2);
    pushBack(&sl, 3);
    pushBack(&sl, 4);
    pushBack(&sl, 5);
    pushBack(&sl, 6);
    pushBack(&sl, 2);
    pushBack(&sl, 2);
    pushBack(&sl, 2);
    print(&sl);

    Remove(&sl, 2);
    print(&sl);
    RemoveAll(&sl, 2);
    print(&sl);

//     insertPos(&sl, 2, 18);
//     print(&sl);
//     deletePos(&sl, 2);
//     print(&sl);
   //  seqlistInit(&sl);

   //  pushFront(&sl, 6);
   //  pushFront(&sl, 5);
   //  pushFront(&sl, 4);
   //  pushFront(&sl, 3);
   //  pushFront(&sl, 2);
   //  pushFront(&sl, 1);
   //  print(&sl);

   //  popFront(&sl);
   //  popFront(&sl);
   //  popFront(&sl);
   //  print(&sl);

//     pushBack(&sl, 1);
//     pushBack(&sl, 2);
//     pushBack(&sl, 3);
//     pushBack(&sl, 4);
//     pushBack(&sl, 5);
//     pushBack(&sl, 6);
//     print(&sl);
// 
//     popBack(&sl);
//     popBack(&sl);
//     popBack(&sl);
//     print(&sl);



    return 0;
}

