//
//  LearningMkdir.c
//  FilesAndDirectories
//

#include "LearningMkdir.h"

#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
int useMkdir(char *dirname)
{
    int isCreated;
    
    // We are defaulting to a mode of 0777, but we can change this.
    isCreated = mkdir(dirname, 0777);
    
    if(isCreated == 0)
    { // The value is 0 for Successful
        printf("Directory Created Successfully\n");
        
    }
    else
    {
        // Value is -1 if it is unsuccessful.
        printf("Unable to Create Directory\n");
        
    }
    
    return 0;
    
}
