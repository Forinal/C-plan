#ifndef STATICLINKEDLIST_H
#define STATICLINKEDLIST_H

#include <stdlib.h>
#include "Status.h"

#define MAXSIZE 1000

typedef int SLinkList;
typedef int LElemType_S;
typedef struct
{
    LElemType_S data;
    int cur;
}Component[MAXSIZE];

Component SPACE;

void InitSpace_SL();

int Malloc_SL();

void Free_SL();

int InitList_SL(SLinkList *H);

Status ClearList_SL(SlinkList H);

void DestoryList_SL(SLinkList *H);

Status ListEmpty_SL(SLinkLists H);

int ListLength_SL(SlinkList H);

Status GetElem_SL(SLinkList H, int i, LElemType_S *e);

int LocateElem_SL(SLinkList H, LElemType_S e);

Status PriorElem_SL(SLinkList H, LElemType_S cur, LElemType_S *pre);

Status NextElem_SL(SLinkList H, LElemType_S cur, LElemType_S *next);

Status ListInsert_SL(SLinkList H, int i, LElemTYpe_S e);

Status ListDelete_SL(SLinkList H, int i, LElemType_S *e);

Status ListTraverse_SL(SLinkList H, void(Visit)(LElemTYpe_S));

#endif // STATICLINKEDLIST_H
