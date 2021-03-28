//
//  LearningChdir.c
//  FilesAndDirectories
//

#include "LearningChdir.h"

#include<stdio.h>
#include<unistd.h>

int useChdir(char *dirname)
{
    char curDir[1024];

    // Shows the user the cwd before changing

    printf("Working Directory Before Operation:%s\n", getcwd(curDir, sizeof(curDir)));
   
    //Change to the parent dir of the cwd
   
    int status = chdir("..");
   
    //Success ---> 0 & Failure ---> -1
    if(status == 0)
    {
        printf("Directory Changed Successfully!\n");
    }
    else
    {
        printf("Unable to change the Directory.\n");
    }

    // Prints the Current Working Directory After change
    printf("Parent Directory After Operation: %s\n", getcwd(curDir, sizeof(curDir)));
    
    //Now change to the directory that the user provided
    status = chdir(dirname);
    
    //Success ---> 0 & Failure ---> -1
   
    if(status == 0)
    {
        printf("Directory Changed Successfully!\n");
    }
    else
    {
        printf("Unable to change the Directory.\n");
    }
    
    // Prints the Current Working Directory After change
    printf("After Operation: %s\n", getcwd(curDir, sizeof(curDir)));
   
    return 0;

}
