#include <stdlib.h>



typedef struct dyList{
    const void *last_p;
    int size;
    void *data;
    const void *next_p;
}dyList;

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

const dyList * dyListAppend(dyList *dyList_P,int size,void *data){
    if(dyList_P->next_p != NULL)return dyList_P;// 并不是最后一个节点
    const dyList new = {
        .last_p=dyList_P,
        .next_p=NULL,
        .size = size,
        .data=data,
    };
    dyList_P->next_p = &new;
    const dyList * new_p = &new;
    return new_p;
}

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

