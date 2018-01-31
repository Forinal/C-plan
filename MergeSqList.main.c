#include <stdio.h>
#include "MergeSqList.h"

void PrintElem(LElemType_Sq e);

int main(int argc, char **argv)
{
    SqList la, lb, lc1, lc2;
    LElemType_Sq a[4] = {3,5,8,11};
    LElemType_Sq b[7] = {2,6,8,9,11,15,20};
    int i;

    InitList_Sq(&la);
    for (i = 1; i <= 4; i++)
    {
        ListInsert_Sq(&la, i, a[i-1]);
    }

    InitList_Sq(&lb);
    for (i = 1; i <= 4; i++)
    {
        ListInsert_Sq(&lb, i, a[i-1]);
    }

    printf("la = ");
    ListTraverse_Sq(la, PrintElem);
    printf("\n");

    printf("lb = ");
    ListTraverse_Sq(lb, PrintElem);
    printf("\n");

    MergeSqList_1(la, lb, &lc1);
    printf("Merge la and lb to lc1 = ");
    ListTraverse_Sq(lc1, PrintElem);
    printf("\n\n");

    MergeSqList_2(la, lb, &lc2);
    printf("Merge la and lb to lc2 = ");
    ListTraverse_Sq(lc2, PrintElem);
    printf("\n\n");

    return 0;
}

void PrintElem(LElemType_Sq e)
{
    printf("%d", e);
}
