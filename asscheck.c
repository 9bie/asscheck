// 检测器核心文件
#include <stdio.h>
#include<windows.h>
#include<string.h>
#define MAX_SIZE 255
#define ISFUNCTION 0
#define ISVARIABLE 1
#define CODESEGMENT 0
#define DATASEGMENT 1
const char  * keywords[] = {"mov","call","inc","push","pop"};//汇编关键字


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



//全局变量定义去
SEGMENTS *cs;
int ip;//按行数来当IP的hhhhh
chunk strack;







void Interpreter_Runner(){

}

void Interpreter_Entry(char *path){// 包含初始化代码信息，区分代码段等等
    int file_size;
    DWORD dwRead;
    HANDLE hFile;
    char *code;
    hFile = CreateFile(path,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    if (hFile == NULL) return;
    file_size=GetFileSize(hFile,NULL);
    code = (char*)malloc(file_size+1);
    code[file_size+1]="\0";
    if(!ReadFile(hFile,code,file_size,&dwRead,NULL))return;
    // 首次处理代码，犹豫要不要用strtok
    char *line;
    line = strtok (code,"\n");
    while(line){
        
        line = strtok (NULL,"\n");
    }





    free(code);

}
int  main(int argc, char *argv[])
{
    //CLI部分
    if (argc == 1){
        printf("usage: asscheck.exe [path]\n    Precompiled the code.\n");
    }else {
        
        Interpreter_Entry(argv[1]);
    }
    return 0;
}