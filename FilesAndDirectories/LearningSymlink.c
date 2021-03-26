//
//  LearningSymlink.c
//  FilesAndDirectories
//

#include "LearningSymlink.h"

#include<stdio.h>
#include<unistd.h>

int useSymlink(const char *filepath)
{
    int link_status;
    char linkname[50];
    
    // Taking User Input for file path
    
    printf("\nEnter the name that you would like to give your soft link: ");
    scanf("%[^\n]%*c", linkname);
    
    link_status = symlink(filepath,linkname);
    
    // 0 ---> On Success || -1 ---> If Any Error Occurs
    if(link_status == 0)
    {
        printf("Soft link Created Successfully!\n");
        
    }
    else
    {
        printf("Unable to Create the Link.\n");
        
    }
    
    return 0;
    
}
