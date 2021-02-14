#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "LearningCreat.h"
#include "LearningOpen.h"

int main(int argc, const char * argv[]) {
    
    int file_descriptor = 0; //Return code
    char filename[255];
    char functionChoice;
    
    printf("Enter the filename: ");
    scanf("%s", filename);
    getchar(); //added this to capture the newline char.
    printf("Which function would you like to try?  (o)pen or (c)reat?: ");
    scanf("%c", &functionChoice);
    getchar();
    
    
    mode_t mode = O_RDWR | O_CREAT;

   switch(functionChoice)
   {
      case 'c' :
           printf("You chose to create a file.\n" );
           file_descriptor = useCreat(filename, mode);
           break;
      case 'o' :
           printf("You chose to open a file.\n" );
           /* We are going to attempt to open the file that we just created */
           mode = O_RDONLY;
           file_descriptor = useOpen(filename, mode);
           break;
      default :
           printf("Invalid choice.  Defaulting to creat.\n" );
           file_descriptor = useCreat(filename, mode);
   } //end switch
    
    if(file_descriptor != -1)
    {
        printf("It worked!  We were able to complete your request for %s\n", filename);
    }
    else
    {
        printf("Failed to complete your request %s\n", filename);
    }
    
    int rc = 0;
    
    rc = close(file_descriptor); //Utilizing the close system call to close the file that we openned or created.
    
    if(rc != 0)
    {
        printf("Failed to close file!\n");
    }
    
    printf("Successfully closed file!\n");
    
    return 0;
}
