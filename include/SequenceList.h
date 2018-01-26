#ifndef SEQUENCELIST_H
#define SEQUENCELIST_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int LElemType_Sq;
#endif // LELEMTYPE_SQ

typedef struct
{
    LElemType_Sq *elem;
    int length;
    int listsize;
}SqList;


int InitList_Sq(SqList *L);

void ClearList_Sq(SqList *L);

void DestoryList_Sq(SqList *L);

int ListEmpty_Sq(SqList L);

int ListLength_Sq(SqList L);

int GetElem_Sq(SqList L, int i, LElemType_Sq *e);

int LocateElem_Sq(SqList L, LElemType_Sq e,int(Compare)(LElemType_Sq,LElemType_Sq));

int PriorElem_Sq(SqList L,LElemType_Sq cur,LElemType_Sq *pre);

int NextElem_Sq(SqList L,LElemType_Sq cur,LElemType_Sq *next);

int ListInsert_Sq(SqList *L, int i, LElemType_Sq e);

int ListDelete_Sq(SqList *L, int i, LElemType_Sq *e);

int ListTraverse_Sq(SqList L, void(Visit)(LelemType_Sq));

#endif // SEQUENCELIST_H
