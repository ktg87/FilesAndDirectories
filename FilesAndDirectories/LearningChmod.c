//
//  LearningChmod.c
//  FilesAndDirectories
//

#include "LearningChmod.h"

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h> //needed for chmod


int useChmod(char *filepath)
{
    int rc;
    mode_t new_permission_value;
    
    // Taking the Input from the user
    printf("Enter the new permission to set (make sure to start with a 0 i.e. 0444): ");
    
    // Permission Set value starts with 0.
    // Eg: if i want to set 444 to a particular file then i need to give like 0444.
    
    scanf("%hu", &new_permission_value);
    
    // Setting the Permissions
    rc = chmod(filepath, new_permission_value);
    
    // 0 ---> On Success || -1 ---> On Failure.
    
    if (rc == 0)
    {
        printf("New permissions: %hu set successfully.!\n", new_permission_value);
        
    }
    else
    {
        printf("Permissions Change Unsuccessful");
        
    }
    
    return rc;
    
}
