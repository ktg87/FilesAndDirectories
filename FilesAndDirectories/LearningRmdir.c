//
//  LearningRmdir.c
//  FilesAndDirectories
//

#include "LearningRmdir.h"

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int useRmdir(char *dirname)
{
    int isRemoved;
    
    isRemoved = rmdir(dirname);
    
    if(isRemoved == 0)
    {
        // The value is 0 for Successful
        printf("Directory Deleted Successfully\n");
        
    }
    else
    {
        // Value is -1 if it is unsuccessful.
        printf("Unable to Delete Directory\n");
        
    }
    
    return 0;
    
}
