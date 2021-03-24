//
//  LearningAccess.c
//  FilesAndDirectories
//

#include "LearningAccess.h"

#include<stdio.h>
#include<unistd.h>

int useAccess(char *filepath)
{
    
    int read_status, file_status, write_status;
    
    file_status = access(filepath, F_OK);
    /*   Returns   -1 ----> If File Doesn't Exist    0 ----> If File Exists*/
    
    if(file_status == -1)
    {
        printf("%s File does not exist in Location.\n", filepath);
        _exit(0);
        
    }
    
    read_status = access(filepath, R_OK);
    write_status = access(filepath, W_OK);
    
    // Checks for the both Read and Write Access
    if(read_status == 0 && write_status == 0)
    {
        printf("%s File has both read and write permissions\n", filepath);
        
    }
    else if(read_status == 0 && write_status == -1)
    {
        // If file has only read access then
        printf("%s File has only read permissions\n", filepath);
        
    }
    else if(read_status == -1 && write_status == 0)
    {
        // If file has only write access then
        printf("%s File has only write permissions\n", filepath);
        
    }
    else
    {
        // If file does not have both read and write access then
        printf("%s File has no read and write permissions", filepath);
        
    }
    
    return 0;
    
}
