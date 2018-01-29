#include "SinglyLinkedList.h"


Status InitList_L(LinkList* L)
{
    *L = (LinkList)malloc(sizeof(LinkList));
    if (!L)
        return OVERFLOW;

        (*L)->data = -1;
        (*L)->next = NULL;
    return OK;
}

Status ClearList_L(LinkList L)
{
    if (!L)
    {
        return ERROR;
    }

    LNode *p = L;
    LNode *pre = L->next;
    while (pre)
    {
        p = pre->next;
        free(pre);
        pre = p;
    }

    L->next = NULL;
    return OK;
}

void DestroyList_L(LinkList* L)
{
    LinkList p = *L;
    while (p)
    {
        p = (*L)->next;
        free(*L);
        (*L) = p;
    }
}

Status ListEmpty_L(LinkList L)
{
    if (L->next != NULL)
    {
        return NO;
    }

    return YES;
}

int ListLength_L(LinkList L)
{
    LNode* p = L;
    int i = 0;
    while (p->next != NULL)
    {
        p = p->next;
        ++i;
    }

    return i;
}

Status GetElem_L(LinkList L, int i, LElemType_L* e)
{
    int j = 0;
    LNode *p = L;
    while (j != i)
    {
        p = p->next;
        ++j;
    }

    *e = p->data;
}

int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L))
{
    LNode *p = L;
    int i = 0;
    while (p)
    {
        if (Compare(e,p->data))
        {
            return i;
        }
        p = p->next;
        ++i;
    }
}

Status PriorElem_L(LinkList L, LElemType_L cur, LElemType_L* pre)
{
    if (cur == L->next->data)
    {
        return ERROR;
    }

    LNode* _pre = L;
    LNode* _cur = L->next;
    while (_cur)
    {
        if (_cur->data == cur)
        {
            *pre = _pre->data;
            return OK;
        }
        _pre = _cur;
        _cur = _cur->next;
    }

    return ERROR;
}

Status NextElem_L(LinkList L, LElemType_L cur, LElemType_L* next)
{
    LNode *p = L;
    while (p)
    {
        if (p->data == cur)
        {
            *next = p->next->data;
            return OK;
        }
        p = p->next;
    }

    return ERROR;
}

Status ListInsert_L(LinkList L, int i, LElemType_L e)
{
    if (L == NULL)
    {
        return ERROR;
    }

    LNode *cur = L;
    LNode *pre = NULL;
    int j = 1;
    while (cur && (j < i))
    {
        ++j;
        pre = cur;
        cur = cur -> next;
    }
    LNode *p = (LNode*)malloc(sizeof(LNode));
    p->data = e;
    p->next = cur->next;
    cur->next = p;
    return OK;
}

Status ListDelete_L(LinkList L, int i, LElemType_L* e)
{
    LNode *cur = L;
    LNode *pre = NULL;
    int j = 0;
    while (cur && (j < i))
    {
        ++j;
        pre = cur;
        cur = cur->next;
    }
    *e = cur->data;
    pre->next = cur->next;
    free(cur);
}

Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L))
{
    LNode *p = L;
    while (p)
    {
        Visit(p->data);
        p = p->next;
    }
}

Status CreateList_HL(FILE* fp, LinkList* L, int n)
{
    *L = (LinkList)malloc(sizeof(LNode));
    if (!(*L))
    {
        exit(OVERFLOW);
    }
    (*L)->data = -1;
    (*L)->next = NULL;

    LElemType_L tmp;
    for (int i = 0; i < n; i++)
    {
        LNode *p;
        if (Scanf(fp, "%d",&tmp) == 1)
        {
            p = (LNode*)malloc(sizeof(LNode));
            if (!p)
            {
                exit(OVERFLOW);
            }
            p->data = tmp;
            p->next = (*L)->next;
            (*L)->next = p;
        }
        else
        {
            return ERROR;
        }
    }

    return OK;
}

Status CreateList_TL(FILE* fp, LinkList* L, int n)
{
    *L = (LinkList)malloc(sizeof(LNode));
    if (!(*L))
    {
        exit(OVERFLOW);
    }
    (*L)->data = -1;
    (*L)->next = NULL;

    int i = 0;
    LinkList q = *L;
    LElemType_L tmp;
    for (;i < n; ++i)
    {
        if (Scanf(fp,"%d",&tmp) == 1)
        {
            LinkList p = (LinkList)malloc(sizeof(LinkList));
            if (!p)
            {
                exit(OVERFLOW);
            }
            p->data = tmp;
            q->next = p;
            q = q->next;
        }
        else
        {
            return ERROR;
        }
    }

    q->next = NULL;
    return OK;
}
