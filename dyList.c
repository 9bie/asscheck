#include "dyList.h"

//初始化一个链表
 dyList * dyListInit(int size,void *data){
    dyList *new = malloc(sizeof(dyList));
    new->last_p=NULL;
    new->next_p=NULL;
    new->size=size;
    new->data=data;
    
    return new;
}
//在指定位置插入一个
bool dyListAppend(dyList * dyList_P,int i,int size,void *data){

}
//压入一个
bool dyListPush( dyList *dyList_P,int size,void *data){
    if(dyList_P->next_p != NULL )return false;// 并不是最后一个节点
    
    dyList *new = malloc(sizeof(dyList));
    new->last_p=dyList_P;
    new->next_p=NULL;
    new->size=size;
    new->data=data;
    dyList_P->next_p = new;
    dyList_P = new;
    return true;
    //return true;
}
//弹出最后一个
dyList * dyListPop(dyList *dyList_P){
    if (dyList_P->next_p != NULL)return NULL;
    if (dyList_P->last_p == NULL){//已经是最后一个节点了
        // free(dyList_P);
        return dyList_P;
    }else{
        dyList *pop = dyList_P;
        dyList_P = dyList_P->last_p;
        dyList_P->next_p = NULL;
        return pop;
    };    
}
//获取链表长度
int dyListLength(dyList * dyList_P){
    int i,i1=0;
    if (dyList_P->next_p != NULL && dyList_P->last_p != NULL){//如果是从中间开始
         dyList * next = dyList_P->next_p;
         dyList * last = dyList_P->last_p;
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
         dyList * next = dyList_P->next_p;
        while (next){
            i+=1;
            next = next->next_p;
        }
        return i;
    }else if (dyList_P->last_p != NULL){//从尾部开始
         dyList * last = dyList_P->last_p;
        while (last){
            i1+=1;
            last = last->last_p;
        }
        return i1;
    }
    
}

bool dyListFree(dyList * dyList_P){
    if(dyList_P!=NULL){
        dyList *head = dyListHead(dyList_P);
        while(head->last_p){
            dyList *now = head;
            head = head->last_p;
            free(now);
        }
        return true;
    }
    return false;
}
//取链表头
dyList * dyListHead(dyList * dyList_P){
     dyList * last = dyList_P->last_p;
    while (last){
        last = last->last_p;
    }
    return last;
}
//取链表尾
 dyList * dyListTail(dyList *dyList_P){
     dyList * next = dyList_P->next_p;
    while (next){
        next = next->next_p;
    }
    return next;
}
//获取链表中的参数
dyList * dyListGet(dyList *dyList_P,int i){
    
}

 dyList * dyListDelete(dyList *dyList_P,int i){
    if(i> dyListLength(dyList_P))return dyList_P;
    if(i ==0){
         
    }

}

