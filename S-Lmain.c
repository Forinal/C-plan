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
    printf("1.���� InitList_L ����...\n");
    {
        printf("��ʼ�������� L ...\n");
        InitList_L(&L);
        printf("\n");
    }
    PressEnter;
    printf("2.���� ListEmpty_L ����...\n");
    {
        ListEmpty_L(L)?printf("LΪ�գ���\n"):printf("L��Ϊ�գ���\n");
        printf("\n");
    }
    PressEnter;
    printf("3.���� ListInsert_L ����...\n");
    {
       for(i =1;i<=6;i++)
       {
           printf("��L��%d��λ�ò���\"%d\"...\n",i,2*i);
           ListInsert_L(&L,i,i*2);
       }
        printf("\n");
    }
    PressEnter;
    printf("4.���� ListTraverse_L ����...\n");
    {
        printf("L�е�Ԫ��Ϊ��L = ");
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    PressEnter;
    printf("5.���� ListLength_L ����...\n");
    {
        printf("L�ĳ���Ϊ%d\n",ListLength_L(L));
        printf("\n");
    }
    PressEnter;
    printf("6.���� ListDelete_L ����...\n");
    {
        ListDelete_L(&L,6,&e);
        printf("ɾ��L�е�6��Ԫ��\"%d\"...",e);
        printf("L�е�Ԫ��Ϊ��L = ");
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    PressEnter;
    printf("7.���� GetElem_L ����...\n");
    {
        GetElem_L(L,4,&e);
        printf("L�е�4��λ�õ�Ԫ��Ϊ\"%d\"\n",e);
        printf("\n");
    }
    PressEnter;
    printf("8.���� LocateElem_L ����...\n");
    {
        i = LocateElem_L(L,7,CmpGreater);
        printf("L�е�һ��Ԫ�ش���\"7\"��λ��Ϊ%d\n",i);
        printf("\n");
    }
    PressEnter;
    printf("9.���� PriorElem_L ����...\n");
    {
        PriorElem_L(L,6,&e);
        printf("Ԫ��\"6\"��ǰ��Ϊ\"%d\"\n",e);
        printf("\n");
    }
    PressEnter;
     printf("10.���� NextElem_L ����...\n");
    {
        NextElem_L(L,6,&e);
        printf("Ԫ��\"6\"�ĺ��Ϊ\"%d\"\n",e);
        printf("\n");
    }
    PressEnter;
     printf("11.���� ClearList_L ����...\n");
    {
        printf("���Lǰ��");
        ListEmpty_L(L)?printf("LΪ�գ���\n"):printf("L��Ϊ�գ���\n");
        ClearList_L(&L);
        printf("���L��");
        ListEmpty_L(L)?printf("LΪ�գ���\n"):printf("L��Ϊ�գ���\n");
        printf("\n");
    }
    PressEnter;
     printf("12.���� DestroyList_L ����...\n");
    {
        printf("����Lǰ��");
        L?printf("L���ڣ���\n"):printf("L�����ڣ���\n");
        DestroyList_L(&L);
        printf("����L��");
        L?printf("L���ڣ���\n"):printf("L�����ڣ���\n");
        printf("\n");
    }
    PressEnter;
    printf("13.���� ClearList_HL ����...\n");
    {
        FILE *fp;
        LinkList L;
        printf("ͷ�巨����������L = ");
        fp = fopen("TestData_HL.txt","r");
        CreatList_HL(fp,&L,5);
        fclose(fp);
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    PressEnter;
     printf("14.���� ClearList_TL ����...\n");
    {
        FILE *fp;
        LinkList L;
        printf("β�巨����������L = ");
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
