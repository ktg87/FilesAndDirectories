//
//  LearningGetcwd.c
//  FilesAndDirectories
//

#include "LearningGetcwd.h"

#include<stdio.h>
#include<unistd.h>

int useGetcwd()
{
    char currentDir[1024];
    getcwd(currentDir, sizeof(currentDir));
    printf("Current Working Directory: %s\n", currentDir);
    
    return 0;
    
}
