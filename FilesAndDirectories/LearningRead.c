//
//  LearningRead.c
//  FilesAndDirectories
//

#include "LearningRead.h"

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <fcntl.h>


int useRead(char* filename, mode_t mode)
{
    int file_descriptor;
    size_t size;
    char *content = (char *) calloc(100, sizeof(char));
    
    file_descriptor = open(filename, O_RDONLY);
    
    // Program exit if the given file is not found.
    
    if (file_descriptor == -1)
    {
        perror("File Not found.\n");
        return -1;
        
    }
    
    // read the Content from a given file descriptor.
    size = read(file_descriptor, content, 100);
    printf("Number of bytes returned are: %lu\n", size);
    content[99] = '\0';
    printf("File Content: %s\n", content);
    
    // Closes the file descriptor.
    close(file_descriptor);
    return 0;
    
}
