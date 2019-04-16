// 检测器核心文件
#include <stdio.h>
#include<windows.h>
#define MAX_SIZE 255
#define ISFUNCTION 0
#define ISVARIABLE 1
#define CODESEGMENT 0
#define DATASEGMENT 1
const char  * keywords[] = {"mov","call","inc","and other..."};//汇编关键字


// 静态信息段落，保留解析前的基本信息
typedef struct SEGMENTS{
    int type;
    char name;
    int size;
    char *code;
}SEGMENTS;

typedef struct CODE{
    int size;//代码长度
    char *buff;//代码地址地址
    int size_segment;//多少个代码段
    SEGMENTS *seg;
}CODE;

// 静态信息段落结束


// 动态解析时候保存的信息


typedef struct cpu_i
{ //当前解析函数
    char cs; //当前解析函数
    int ip; //当前解析的第几行
}cpu_i;


typedef struct variables // 用户解析时候申明的变量内容
{
    char name;
    char type;
    char count_ref; //引用计数器
    BOOL alive;//是否还在存货周期内 
} variables;
typedef struct chunk //用户
{
    int pStack ;//栈平衡指针，用于计算push和pop是否统一
    int variables;
    struct varibales *i;
}chunk;




struct cpu_i cpu;


BOOL FileIntomation(char *path,WIN32_FIND_DATA  * FindFileData ){
    printf("Precompiled:%s\n",path);
    
    HANDLE hFind;
    hFind = FindFirstFile(path, FindFileData);
    if (hFind == INVALID_HANDLE_VALUE){
        
        return FALSE;
    }else{
        
        return TRUE;
    }
}

void Interpreter_Runner(){

}

void Interpreter_Entry(char *path){// 包含初始化代码信息，区分代码段等等
    
    WIN32_FIND_DATA f;
    FILE *fp;
    int fsize;
    if (FileIntomation(path,&f)){
        fsize = f.nFileSizeLow;
    }else return;
    
    
    fp = fopen(path, "r");
    if(fp==NULL)  {
        printf("read error\n");
        return;
    }

}
int  main(int argc, char *argv[])
{
    //CLI部分
    if (argc == 1){
        printf("usage: asscheck.exe [path]\n    Precompiled the code.\n");
    }else {
        
        
    }
    return 0;
}