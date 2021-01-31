#include <stdio.h>
#include <fcntl.h>

int main(int argc, const char * argv[]) {
    
    int file_descriptor; //Used to store the return value from the creat system call
    char filename[255];
    
    printf("Enter the filename: ");
    scanf("%s", filename);
    // Setting Permissions to Read and Write Access for the file.
    // Notice the use of the bitwise OR to set two modes during the file creation
    file_descriptor = creat(filename, O_RDWR | O_CREAT);
    if(file_descriptor != -1)
    {
        printf("The File (%s) Created Successfully!\n", filename);
    }
    else
    {
        printf("Unable to Create the File: %s.  Returned error: %d\n", filename, file_descriptor);
    }
    
    return 0;
}
