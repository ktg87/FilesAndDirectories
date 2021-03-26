//
//  LearningGetcwd.c
//  FilesAndDirectories
//

#include "LearningGetcwd.h"

#include<stdio.h>
#include<unistd.h>

int useGetcwd()
{
    char newDirectory[100];
    getcwd(newDirectory, 100);
    printf("Current Working Directory: %s\n", newDirectory);
    
    return 0;
    
}
