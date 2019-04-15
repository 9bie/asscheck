// 检测器核心文件
#include <stdio.h>
#include<windows.h>
#define MAX_SIZE 255
struct variable
{
    char name;
    char size;
    
}
struct chunk
{
    int pStack ;//栈平衡指针，用于计算push和pop是否统一
    int size;
};
BOOL IsFileExits(char *path){
    printf("Precompiled:%s\n",path);
    WIN32_FIND_DATA  FindFileData;
    HANDLE hFind;
    hFind = FindFirstFile(path, &FindFileData);
    if (hFind == INVALID_HANDLE_VALUE){
        printf ("Invalid File Handle. Get Last Error reports %d ", GetLastError ());
    }else{
        printf ("The first file found is %s ", FindFileData.cFileName);
        FindClose(hFind);
    }
}

int  main(int argc, char *argv[])
{
    if (argc == 1){
        printf("usage: asscheck.exe [path]\n    Precompiled the code.\n");
    }else {
        
        IsFileExits(argv[1]);
    }
    return 0;
}