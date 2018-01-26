#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

class LinkedList
{
    public:
        LinkedList();
        virtual ~LinkedList();

        InitList(LinkedList &L);
        DestoryList(LinkedList &L);
        ClearList(LinkedList &L);
        ListEmpty(LinkedList L);
        ListLength(LinkedList L);
        //return element by e
        GetElem(LinkedList L,int i , LinkedList &e);
        LocateElem(LinkedList L,e,compare());
        PriorElem(LinkedList L,cur, &pre);
        NextElem(LinkedList L,cur,&next);
        ListInsert(LinkedList &L,int i,e);
        ListDelete(LinkedList &L,int i,&e);
        ListTraverse(L,visit());
    protected:

    private:
};

#endif // LINKEDLIST_H
