/* 设n个人围绕圆桌坐在一起，从第s个人开始报数，数到m的人出列，知道所有人出列。求出列的次序*/
#include<stdio.h>
#include<stdlib.h>

// #define MAXNUM 100


//定义顺序表
struct SeqList{
    int MAXNUM; /*最大元素的个数*/
    int n;  /*存放元素的数*/
    int *element;   /*element[0]、element[1]存放元素表中的元素*/
};
typedef struct SeqList *PSeqList;   /*定义一个SeqList类型的指针类型*/

//创建空的顺序表
PSeqList createNullList_Seq(int m){
    PSeqList palist = (PSeqList)malloc(sizeof(struct SeqList));
    
    if(palist != NULL){
        palist->element = (int *)malloc(sizeof(int) * m);
        if(palist->element){
            palist->n = 0;
            palist->MAXNUM = m;
            return palist;
        }
        else free(palist);
    }
    printf("Out of space!\n");
    return NULL;
}

//判断顺序表是否为空
int isNullList_seq(PSeqList palist){    //判断plist所指向的表是否为空，为空返回1，狗则返回0
    return (palist->n == 0);
}


//在顺序表中求某元素的下标
int locate_seq(PSeqList palist, int x){
    int q;
    for(q=0; q < palist->n; q++){
        if(palist->element[q] == x)
            return q;
    }
    return -1;
}

//顺序表的插入
/*在palist所指的顺序表中，下标为p的元素之前，插入一个值为x的元素，返回插入成功与否的标志*/
int insertPre_seq(PSeqList palist, int p, int x){
    int q;
    if(palist->n  >= palist->MAXNUM){
        printf("Overflow！\n");
        return 0;
    }
    if(p<0 || p>palist->n){
        printf("Not exist!\n");
        return 0;
    }
    for(q = palist->n - 1; q>=p; q--){
        palist->element[q+1] = palist->element[q];
    }
    palist->element[p] = x;
    palist->n = palist->n + 1;
    return 1;
}

//顺序表的插入
/*在palist所指的顺序表下，下标为p元素之后插入一个值为x的元素，返回插入成功与否的标志*/
int insertPost_seq(PSeqList palist, int p, int x){
    int q;
    if(palist-> >= palist->MAXNUM){

    }
}