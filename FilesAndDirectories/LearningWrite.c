//
//  LearningWrite.c
//  FilesAndDirectories
//

#include "LearningWrite.h"

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include <fcntl.h>

int useWrite(char* filename, mode_t mode)
{
    int file_descriptor = open(filename, mode, 0777);
    
    if (file_descriptor == -1)
    {
        perror("Something went wrong.  File not Found!");
        exit(1);
    }
    
    char content[1024];
    printf("Enter the content to write on a given file: ");
    
    // User Input to write into a File.
    scanf("%[^\n]%*c", content);
    size_t size = write(file_descriptor, content, strlen(content));
    printf("%lu", size);
    close(file_descriptor);
    return 0;
}
