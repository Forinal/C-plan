#include <stdio.h>
#include <stdlib.h>
#include "./include/SinglyLinkedList.h"

Status CmpGreater(LElemType_L e,LElemType_L data);
void PrintElem(LElemType_L e);

int main(int argc,char **argv)
{
    LinkList L;
    int i;
    LElemType_L e;
    printf("1.函数 InitList_L 测试...\n");
    {
        printf("初始化单链表 L ...\n");
        InitList_L(&L);
        printf("\n");
    }
    PressEnter;
    printf("2.函数 ListEmpty_L 测试...\n");
    {
        ListEmpty_L(L)?printf("L为空！！\n"):printf("L不为空！！\n");
        printf("\n");
    }
    PressEnter;
    printf("3.函数 ListInsert_L 测试...\n");
    {
       for(i =1;i<=6;i++)
       {
           printf("在L第%d个位置插入\"%d\"...\n",i,2*i);
           ListInsert_L(&L,i,i*2);
       }
        printf("\n");
    }
    PressEnter;
    printf("4.函数 ListTraverse_L 测试...\n");
    {
        printf("L中的元素为：L = ");
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    PressEnter;
    printf("5.函数 ListLength_L 测试...\n");
    {
        printf("L的长度为%d\n",ListLength_L(L));
        printf("\n");
    }
    PressEnter;
    printf("6.函数 ListDelete_L 测试...\n");
    {
        ListDelete_L(&L,6,&e);
        printf("删除L中第6个元素\"%d\"...",e);
        printf("L中的元素为：L = ");
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    PressEnter;
    printf("7.函数 GetElem_L 测试...\n");
    {
        GetElem_L(L,4,&e);
        printf("L中第4个位置的元素为\"%d\"\n",e);
        printf("\n");
    }
    PressEnter;
    printf("8.函数 LocateElem_L 测试...\n");
    {
        i = LocateElem_L(L,7,CmpGreater);
        printf("L中第一个元素大于\"7\"的位置为%d\n",i);
        printf("\n");
    }
    PressEnter;
    printf("9.函数 PriorElem_L 测试...\n");
    {
        PriorElem_L(L,6,&e);
        printf("元素\"6\"的前驱为\"%d\"\n",e);
        printf("\n");
    }
    PressEnter;
     printf("10.函数 NextElem_L 测试...\n");
    {
        NextElem_L(L,6,&e);
        printf("元素\"6\"的后继为\"%d\"\n",e);
        printf("\n");
    }
    PressEnter;
     printf("11.函数 ClearList_L 测试...\n");
    {
        printf("清空L前：");
        ListEmpty_L(L)?printf("L为空！！\n"):printf("L不为空！！\n");
        ClearList_L(&L);
        printf("清空L后：");
        ListEmpty_L(L)?printf("L为空！！\n"):printf("L不为空！！\n");
        printf("\n");
    }
    PressEnter;
     printf("12.函数 DestroyList_L 测试...\n");
    {
        printf("销毁L前：");
        L?printf("L存在！！\n"):printf("L不存在！！\n");
        DestroyList_L(&L);
        printf("销毁L后：");
        L?printf("L存在！！\n"):printf("L不存在！！\n");
        printf("\n");
    }
    PressEnter;
    printf("13.函数 ClearList_HL 测试...\n");
    {
        FILE *fp;
        LinkList L;
        printf("头插法建立单链表L = ");
        fp = fopen("TestData_HL.txt","r");
        CreatList_HL(fp,&L,5);
        fclose(fp);
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    PressEnter;
     printf("14.函数 ClearList_TL 测试...\n");
    {
        FILE *fp;
        LinkList L;
        printf("尾插法建立单链表L = ");
        fp = fopen("TestData_TL.txt","r");
        CreatList_TL(fp,&L,5);
        fclose(fp);
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    PressEnter;
    return 0;
}

Status CmpGreater(LElemType_L e,LElemType_L data)
{
    return data>e?TRUE:FALSE;
}

void PrintElem(LElemType_L e)
{
    printf("%d\t",e);
}
