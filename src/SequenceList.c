#include "SequenceList.h"

int InitList_Sq(SqList *L)
{
    L->elem = (LElemType_Sq*)malloc(LIST_INIT_SIZE*sizeof(LElemType_Sq));
    if (!L->elem)
    {
        return ERROR;
    }

    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
}

void ClearList_Sq(SqList* L)
{
    L->length = 0;
}

void DestoryList_Sq(SqList* L)
{
    (*L).elem = NULL;
    (*L).length = 0;
    (*L).listsize = 0;
}

int ListEmpty_Sq(SqList L)
{
    if (L.length == 0)
    {
        return OK;
    }

    return NO;
}

int ListLength_Sq(SqList L)
{
    return L.length;
}

int GetElem_Sq(SqList L, int i, LElemType_Sq* e)
{
    if (i < 0 || i > L.length)
    {
        return ERROR;
    }

    *e = L.elem[i-1];

    return OK;
}

int LocateElem_Sq(SqList L, LElemType_Sq e, int(Compare)(LElemType_Sq, LElemType_Sq))
{
    for (int i = 0; i < L.length; i++)
    {
        if (Compare(e,L.elem[i]) == YES)
        {
            return i+1;
        }
    }

    return ERROR;
}

int PriorElem_Sq(SqList L, LElemType_Sq cur, LElemType_Sq* pre)
{
    if (cur == L.elem[0])
    {
        return ERROR;
    }

    for (int i = 0; i < L.length; i++)
    {
        if (cur == L.elem[i])
        {
            *pre = L.elem[i-1];
            return OK;
        }
    }

    return ERROR;
}

int NextElem_Sq(SqList L, LElemType_Sq cur, LElemType_Sq* next)
{
    if (cur == L.elem[L.length])
    {
        return ERROR;
    }

    for (int i = 0; i < L.length; i++)
    {
        if (cur == L.elem[i])
        {
            *next = L.elem[i+1];
            return OK;
        }
    }

    return ERROR;
}

int ListInsert_Sq(SqList *L, int i, LElemType_Sq e)
{
    if (i < 0 || i > L->length + 1)
    {
        return ERROR;
    }

    if (L->length + 1 > L->listsize)
    {
        LElemType_Sq newbase = (LElemType_Sq*)realloc((*L).elem, (L->listsize + LISTINCREMENT)*sizeof(LElemType_Sq));
        if (!newbase)
        {
            exit(OVERFLOW);
        }

        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }

    for (int j = L->length; j >= i; j--)
    {
        L->elem[j+1] = L->elem[j];
    }

    (*L).elem[i-1] = e;
    (*L).length++;

    return OK;
}

int ListDelete_Sq(SqList* L, int i, LElemType_Sq* e)
{
    if (i < 0 || i>L->length)
    {
        return ERROR;
    }

    *e = (*L).elem[i-1];

    if (i == L->length)
    {
        L->elem[i-1] = NULL;
    }

    for (int j = i; j < L->length; j++)
    {
        L->elem[j-1] = L->elem[j];
    }

    L->length--;
}

int ListTraverse_Sq(SqList L, void(Visit)(LElemType_Sq))
{
    for (int i = 0; i < L.length; i++)
    {
        Visit(L.elem[i]);
    }

    return OK;
}
