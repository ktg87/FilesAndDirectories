#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "LearningCreat.h"
#include "LearningOpen.h"
#include "LearningRead.h"

int main(int argc, const char * argv[]) {
    
    int rc = 0; //Return code
    char filename[255];
    char functionChoice;
    enum bool
    {
        FALSE  = 0,
        TRUE   = 1,
    };
    /* C doesn't have bool data type, so we'll use an enum to take care of this*/
    enum bool needsClose = FALSE;
    
    printf("Enter the filename: ");
    scanf("%s", filename);
    getchar(); //added this to capture the newline char.
    printf("Which function would you like to try?  (o)pen or (c)reat or (r)ead?: ");
    scanf("%c", &functionChoice);
    getchar();
    
    
    mode_t mode = O_RDWR | O_CREAT;

   switch(functionChoice)
   {
      case 'c' :
           printf("You chose to create a file.\n" );
           rc = useCreat(filename, mode); //Here rc is the filedescriptor
           needsClose = TRUE;
           break;
      case 'o' :
           printf("You chose to open a file.\n" );
           /* We are going to attempt to open the file that we just created */
           mode = O_RDONLY;
           rc = useOpen(filename, mode); //Here rc is the filedescriptor
           needsClose = TRUE;
           break;
      case 'r' :
           printf("You chose to read a file.\n");
           /* We will need to open the file first before we read it. This will be done in the function*/
           mode = O_RDONLY;
           rc = useRead(filename, mode); //Here rc is just a success or failure
           break;
      default :
           printf("Invalid choice.  Defaulting to creat.\n" );
           rc = useCreat(filename, mode); //Here rc is the filedescriptor
           needsClose = TRUE;
   } //end switch
    
    if(rc != -1)
    {
        printf("It worked!  We were able to complete your request for %s\n", filename);
    }
    else
    {
        printf("Failed to complete your request %s\n", filename);
    }
    
    
    if (needsClose == TRUE)
    {
        rc = close(rc); //Utilizing the close system call to close the file that we openned or created.
    }
    
    
    if(rc != 0)
    {
        printf("Failed to close file!\n");
    }
    
    printf("Successfully closed file!\n");
    
    return 0;
}
