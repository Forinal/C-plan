#ifndef MERGESQLIST_H
#define MERGESQLIST_H

#include <stdlib.h>
#include "SequenceList.h"

//C = A + B ָ��
void MergeSqList_1(SqList la, SqList lb, SqList *lc);

//C = A + B �����±�
void MergeSqList_2(SqList la, SqList lb, SqList *lc);
#endif // MERGESQLIST_H
