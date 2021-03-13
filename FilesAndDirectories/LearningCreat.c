//
//  LearningCreat.c
//  FilesAndDirectories
//
#include "LearningCreat.h"
#include "LearningWrite.h"
#include <fcntl.h>
#include <sys/syslimits.h>
#include <unistd.h>

//The intent of this is just to learn to create a new file
//using the system call creat.  My useCreat function doesn't really do
//anything different than the actual system call creat, but this will
//likely evolve as I move through the various file/directory sys calls
int useCreat(char* filename, mode_t mode)
{
    int file_descriptor; //Used to store the return value from the creat system call
    
    // Setting Permissions to Read and Write Access for the file.
    // Notice the use of the bitwise OR to set two modes during the file creation
    file_descriptor = creat(filename, mode);
    printf("Here is the file_descriptor: %d\n", file_descriptor);
    if(file_descriptor != -1)
    {
        printf("The File (%s) Created Successfully!\n", filename);
        char filePath[PATH_MAX];
        if (fcntl(file_descriptor, F_GETPATH, filePath) != -1)
        {
            printf("Here is the filePath: %s\n", filePath);
        }
        else
        {
            printf("Unable to get filePath\n");
        }
    }
    else
    {
        printf("Unable to Create the File: %s.  Returned error: %d\n", filename, file_descriptor);
    }
    
    close(file_descriptor);
    
    return file_descriptor;
}


