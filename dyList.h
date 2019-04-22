#include <stdlib.h>
#define false 0
#define true 1
typedef int bool; // or #define bool int
typedef int BOOL;
//我TMD蠢了，干嘛要设置返回值位const dyList*，直接参数返回不就行了吗


typedef struct dyList{
     void *last_p;
    int size;
    void *data;
     void *next_p;
}dyList;

dyList * dyListInit(int size,void *data);
bool dyListAppend(dyList * dyList_P,int i,int size,void *data);
bool dyListPush( dyList *dyList_P,int size,void *data);
dyList * dyListPop(dyList *dyList_P);
int dyListLength(dyList * dyList_P);
bool dyListFree(dyList * dyList_P);
dyList * dyListHead(dyList * dyList_P);
dyList * dyListTail(dyList *dyList_P);
dyList * dyListGet(dyList *dyList_P,int i);
dyList * dyListDelete(dyList *dyList_P,int i);
