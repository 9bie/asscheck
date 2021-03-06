// 检测器核心文件
#include <stdio.h>
#include<windows.h>
#include<string.h>
#include "dyList.h"
#include"utlis.c"
#define MAX_SIZE 255
#define ISFUNCTION 0
#define ISVARIABLE 1
#define CODESEGMENT 0
#define DATASEGMENT 1
const char  * keywords[] = {"mov","call","inc","push","pop"};//汇编关键字





// 静态信息段落，保留解析前的基本信息



// 静态信息段落结束


// 动态解析时候保存的信息





typedef struct variables // 用户解析时候申明的变量内容
{
    char name;
    char type;
    // char count_ref; //引用计数器
    BOOL alive;//是否在存货周期内 ，这个需要动态修改
} variables;
typedef struct chunk //用户
{
    int pStack ;//栈平衡指针，用于计算push和pop是否统一
    // int variables;
    // dyList * variable;//这货是存variables的指针链表
    char * name;//该段落的名称
    dyList * linecode;// 用户存这个段落每行的代码
}chunk;



typedef struct cpu{
    int * cs;
    int ip;//用行数来保存
    // int variables;
    dyList * variable;//这货是存variables的指针链表
    
    dyList * code_segment;//这货是用来存数据的，用于存chunk

    dyList * stack;// 栈
}cpu;


//删首尾空



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
    code[file_size+1]='\0';
    if(!ReadFile(hFile,code,file_size,&dwRead,NULL))return;
    // 首次处理代码
    char *line;
    line = strtok (code,"\n");
    while(line){
        

        line = strtok (NULL,"\n");
    }





    free(code);

}
int  main(int argc, char *argv[])
{
    
/*
运行流程

读入代码

逐行分析代码段

切割代码段
    DATASEGMENT += {段落名称，段落代码（按行保存）}

初始化CPU，找到程序入口点

逐行伪运行：
    case 遇到变量
        case 声明
            CPU中的变量栈压入变量信息{属于哪个段落（作用域），变量名，变量类型}
        case 引用
            查找CPU代码段中是否有变量信息，引用计数+1
    case 遇到调用
        case 外部调用
            检查自带的函数表
        case 内部函数
            CPU {CS:调用函数,;IP:0}
    case other.....
        

*/

    //CLI部分
    if (argc == 1){
        printf("usage: asscheck.exe [path]\n    Precompiled the code.\n");
    }else {
        
        Interpreter_Entry(argv[1]);
    }
    return 0;
}