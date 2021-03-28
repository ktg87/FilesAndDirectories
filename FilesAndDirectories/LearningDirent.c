//
//  LearningDirent.c
//  FilesAndDirectories
//

#include "LearningDirent.h"

#include <stdio.h>
#include<stdlib.h>
#include <dirent.h>

int useDirent(char *dirname)
{
    // Directory Entry
    struct dirent *DIR_ENTRY;
    
    // opendir() returns a pointer of DIR type.
    DIR *DIR_READER = opendir(dirname);
    
    if (DIR_READER == NULL)
    {
        printf("Could not open the directory you provided\n" );
        exit(1);
    }
    
    while ((DIR_ENTRY = readdir(DIR_READER)) != NULL)
        printf("%s\n", DIR_ENTRY->d_name);
    
    //Make sure to close the directory stream
    int status = closedir(DIR_READER);
    
    if(status == 0){
           printf("Directory Closed Successfully!\n");
       }else{
           printf("Unable to close the Directory.\n");
       }
    
    return 0;
    
}
