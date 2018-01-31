#include <stdio.h>
#include <stdlib.h>

#include "SequenceList.h"

Status CmpGreater(LElemType_Sq e, LElemType_Sq data);
void PrintElem(LElemType_Sq e);

int main(int argc, char **argv)
{
    SqList L;
    int i;
    LElemType_Sq e;

    printf("1. InitList_Sq Test...\n");
    {
        printf("Initializing sqlist\n");
        InitList_Sq(&L);
        ListTraverse_Sq(L,PrintElem);
        printf("\n");
    }
    PressEnter;

    printf("2. ListEmpty_Sq Test...\n");
    {
        ListEmpty_Sq(L) ? printf("L is empty\n") : printf("L is not empty\n");
        printf("\n");
    }
    PressEnter;

    printf("3. ListInsert_Sq Test...\n");
    {
        for (i = 1; i <= 6; i++)
        {
            printf("%d insert \"%d\" \n" ,i, 2*i);
            ListInsert_Sq(&L,i,2*i);
        }
        printf("\n");
    }
    PressEnter;

    printf("4. ListTraverse_Sq Test...\n");
    {
        ListTraverse_Sq(L, PrintElem);
        printf("\n");
    }
    PressEnter;

    printf("5. ListLength_Sq Test...\n");
    {
        i = ListLength_Sq(L);
        printf("length : %d \n\n",i);
    }
    PressEnter;

    printf("6. ListDelete_Sq Test...\n");
    {
        ListDelete_Sq(&L,6,&e);
        printf("Delete sixth elem \"%d\"\n", e);
        ListTraverse_Sq(L,PrintElem);
        printf("\n");
    }
    PressEnter;

    printf("7. GetElem_Sq Test...\n");
    {
        GetElem_Sq(L,4,&e);
        printf("The 4th elem is \"%d\"\n", e);
        printf("\n");
    }
    PressEnter;

    printf("8. LocateElem_Sq Test...\n");
    {
        i = LocateElem_Sq(L,7,CmpGreater);
        printf("The position of first elem bigger than \"7\" is %d\n", i);
        printf("\n");
    }
    PressEnter;

    printf("9. PriorElem_Sq Test...\n");
    {
        PriorElem_Sq(L,6,&e);
        printf("The prior of \"6\" is %d\n", e);
        printf("\n");
    }
    PressEnter;

    printf("10. NextElem_Sq Test...\n");
    {
        NextElem_Sq(L,6,&e);
        printf("The next of \"6\" is %d\n", e);
        printf("\n");
    }
    PressEnter;

    printf("11. ClearList_Sq Test...\n");
    {
        printf("Before clear\n");
        ListEmpty_Sq(L) ? printf("L is empty\n") : printf("L is not empty\n");
        ClearList_Sq(&L);
        printf("After clear\n");
        ListEmpty_Sq(L) ? printf("L is empty\n") : printf("L is not empty\n");
        printf("\n");
    }
    PressEnter;

    printf("12. DestroyList_Sq Test...\n");
    {
        printf("Before destroy\n");
        L.elem ? printf("L exist\n") : printf("L not exist\n");
        DestoryList_Sq(&L);
        printf("After destroy\n");
        L.elem ? printf("L exist\n") : printf("L not exist\n");
        printf("\n");
    }
    PressEnter;

    return 0;
}

Status CmpGreater(LElemType_Sq e,LElemType_Sq data)
{
    return data > e ? TRUE : FALSE;
}

void PrintElem(LElemType_Sq e)
{
    printf("%d\n", e);
}
