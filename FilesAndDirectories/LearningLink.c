//
//  LearningLink.c
//  FilesAndDirectories
//

#include "LearningLink.h"

#include<stdio.h>
#include<unistd.h>

int useLink(char *filepath)
{
    int link_status;
    char linkname[50];
    
    printf("Enter the linkname: ");
    scanf("%[^\n]%*c", linkname);
    
    link_status = link(filepath, linkname);
    
    // Hardlink be Created.   // 0 ---> Successful || -1 ---> Failure.
    if(link_status == 0)
    {
        printf("HardLink is Created Successfully.!");
        
    }
    else
    {
        printf("Unable to Create the Hard Link.");
        
    }
    
    return 0;
    
}
