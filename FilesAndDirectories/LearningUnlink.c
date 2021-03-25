//
//  LearningUnlink.c
//  FilesAndDirectories
//

#include "LearningUnlink.h"

#include<stdio.h>
#include<unistd.h>

int useUnlink(char *linkname)
{
    int unlink_status;
    
    unlink_status = unlink(linkname);
    
    // 0 --->On Success || -1 ---> Failure.
    if(unlink_status == 0)
    {
        printf("File unlinked Successfully!");
        
    }
    else
    {
        printf("Unable to unlink the file.");
        
    }
    
    return 0;
    
}
