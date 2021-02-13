//
//  LearningOpen.c
//  FilesAndDirectories
//

#include "LearningOpen.h"
#include <fcntl.h>
#include <errno.h>

int useOpen(char* filename, mode_t mode)
{
    int file_descriptor;
    
    //Read Only permission set for file
    file_descriptor = open(filename, O_RDONLY|O_CREAT);

    printf("Here is the file_descriptor: %d\n", file_descriptor);
    
    /* On Failure, the value -1 will be returned */
    
    if (file_descriptor != -1)
    {
        printf("%s Opened with Read Only Permission!\n", filename);
    }
    else
    {
        printf("Failed to Open %s\n", filename);
    }
    
    return file_descriptor;
}
