#include <stdlib.h>
#define false 0
#define true 1
typedef int bool; // or #define bool int
typedef int BOOL;
//我TMD蠢了，干嘛要设置返回值位const dyList*，直接参数返回不就行了吗


typedef struct dyList{
    const void *last_p;
    int size;
    void *data;
    const void *next_p;
}dyList;

//初始化一个链表
const dyList * dyListInit(int size,void *data){
    const dyList new = {
        
        .last_p=NULL,
        .next_p=NULL,
        .size = size,
        .data=data,
    };
    const dyList* new_p = &new;//不这样会报
    return new_p;
}
//在指定位置插入一个
const dyList * dyListAppend(dyList * dyList_P,int i,int size,void *data){

}
//压入一个
const dyList */*bool*/ dyListPush( dyList *dyList_P,int size,void *data){
    if(dyList_P->next_p != NULL )return dyList_P;// 并不是最后一个节点
    const dyList new = {
        .last_p=dyList_P,
        .next_p=NULL,
        .size = size,
        .data=data,
    };
    dyList_P->next_p = &new;
    const dyList * new_p = &new;
    //dyList_P = &new;
     return new_p;
    //return true;
}
//弹出最后一个
const dyList * dyListPop(dyList *dyList_P){
    if (dyList_P->next_p != NULL)return dyList_P;
    if (dyList_P->last_p == NULL){
        free(dyList_P);
        return NULL;
    }else{
        const dyList* last = dyList_P->last_p;
        free(dyList_P);
        return last;
    };    
}
//获取链表长度
int dyListLength(dyList * dyList_P){
    int i,i1=0;
    if (dyList_P->next_p != NULL && dyList_P->last_p != NULL){//如果是从中间开始
        const dyList * next = dyList_P->next_p;
        const dyList * last = dyList_P->last_p;
        while (next){
            i+=1;
            next = next->next_p;
        }
        while (last){
            i1+=1;
            last = last->last_p;
        }
        return i+i1;
    }else if (dyList_P->next_p != NULL){//从头部开始
        const dyList * next = dyList_P->next_p;
        while (next){
            i+=1;
            next = next->next_p;
        }
        return i;
    }else if (dyList_P->last_p != NULL){//从尾部开始
        const dyList * last = dyList_P->last_p;
        while (last){
            i1+=1;
            last = last->last_p;
        }
        return i1;
    }
    
}
//取链表头
const dyList * dyListHead(dyList * dyList_P){
    const dyList * last = dyList_P->last_p;
    while (last){
        last = last->last_p;
    }
    return last;
}
//取链表尾
const dyList * dyListTail(dyList *dyList_P){
    const dyList * next = dyList_P->next_p;
    while (next){
        next = next->next_p;
    }
    return next;
}
//获取链表中的参数
const dyList * dyListGet(dyList *dyList_P,int i){
    
}
const dyList * dyListDelete(dyList *dyList_P,int i){
    if(i> dyListLength(dyList_P))return dyList_P;
    if(i ==0){
        const dyList result;
    }

}

