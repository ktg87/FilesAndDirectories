#include <stdio.h>
#include <fcntl.h>
#include "LearningCreat.h"

int main(int argc, const char * argv[]) {
    
    int rc = 0; //Return code
    char filename[255];
    
    printf("Enter the filename: ");
    scanf("%s", filename);
    
    mode_t mode = O_RDWR | O_CREAT;
    
    rc = useCreat(filename, mode);
        
    return 0;
}
