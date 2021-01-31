#include <stdio.h>
#include <fcntl.h>

int main(int argc, const char * argv[]) {
    
    int file_descriptor;
    char filename[255];
    
    printf("Enter the filename: ");
    scanf("%s", filename);
    // Setting Permissions to Read and Write Access for the file.
    file_descriptor = creat(filename, O_RDWR | O_CREAT);
    if(file_descriptor != -1)
    {
        printf("File Created Successfully!");
    }
    else
    {
        printf("Unable to Create the File.");
    }
    
    return 0;
}
