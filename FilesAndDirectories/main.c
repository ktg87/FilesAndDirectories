#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "LearningAccess.h"
#include "LearningCreat.h"
#include "LearningChdir.h"
#include "LearningChmod.h"
#include "LearningDirent.h"
#include "LearningGetcwd.h"
#include "LearningLink.h"
#include "LearningMkdir.h"
#include "LearningOpen.h"
#include "LearningRead.h"
#include "LearningRmdir.h"
#include "LearningSymlink.h"
#include "LearningUnlink.h"
#include "LearningWrite.h"

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
    enum bool anotherChoice = TRUE;
    
    while(anotherChoice == TRUE)
    {
        printf("Enter the filename: ");
        scanf("%s", filename);
        getchar(); //added this to capture the newline char.
        
        printf("Which function would you like to try? \
               \n(o)pen \
               \t\t(c)reat \
               \n(r)ead \
               \t\t(w)rite \
               \n(p)ermissions \
               \t\t(a)ccess \
               \n(s)oft link \
               \t\t(u)nlink \
               \n(l)ink \
               \t\t(m)akedir \
               \n(d)elete dir \
               \t\t(g)et cwd \
               \nc(h)dir \
               \t\tdirlis(t)\n");
        scanf("%c", &functionChoice);
        getchar();
        
        
        mode_t mode = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP;

        switch(functionChoice)
        {
            case 'a' :
                printf("You chose to check a file's access permissions.\n" );
                rc = useAccess(filename); //Here rc is the filedescriptor
                break;
            case 'c' :
                printf("You chose to create a file.\n" );
                rc = useCreat(filename, mode); //Here rc is the filedescriptor
                break;
            case 'd' :
                printf("You chose to delete a directory.\n" );
                rc = useRmdir(filename); //Here rc is the filedescriptor
                break;
            case 'g' :
                printf("You chose to get the current working directory.\n");
                rc = useGetcwd(); //Here rc is just a success or failure
                break;
            case 'h' :
                printf("You chose to change the current working directory.\n");
                rc = useChdir(filename); //Here rc is just a success or failure
                break;
            case 'l' :
                printf("You chose to create a soft link for a file.\n");
                rc = useLink(filename); //Here rc is just a success or failure
                break;
            case 'm' :
                printf("You chose to make a new directory.\n");
                rc = useMkdir(filename); //Here rc is just a success or failure
                break;
            case 'o' :
                printf("You chose to open a file.\n" );
                /* We are going to attempt to open the file that we just created */
                mode = O_RDONLY;
                rc = useOpen(filename, mode); //Here rc is the filedescriptor
                break;
            case 'p' :
                printf("You chose to change permissions to a file.\n");
                rc = useChmod(filename); //Here rc is just a success or failure
                break;
            case 'r' :
                printf("You chose to read a file.\n");
                /* We will need to open the file first before we read it. This will be done in the function*/
                mode = O_RDONLY;
                rc = useRead(filename, mode); //Here rc is just a success or failure
                break;
            case 's' :
                printf("You chose to create a soft link for a file.\n");
                rc = useSymlink(filename); //Here rc is just a success or failure
                break;
            case 't' :
                printf("You chose to list the directory entries.\n");
                rc = useDirent(filename); //Here rc is just a success or failure
                break;
            case 'u' :
                printf("You chose to unlink a soft link for a file.\n");
                rc = useUnlink(filename); //Here rc is just a success or failure
                break;
            case 'w' :
                printf("You chose to write to a file.\n");
                mode = O_CREAT | O_RDWR | O_APPEND;
                rc = useWrite(filename, mode); //Here rc is just a success or failure
                break;
            default :
                printf("Invalid choice.  Defaulting to creat.\n" );
                rc = useCreat(filename, mode); //Here rc is the filedescriptor
        } //end switch
        
        if(rc != -1)
        {
            printf("It worked!  We were able to complete your request for %s\n", filename);
        }
        else
        {
            printf("Failed to complete your request %s\n", filename);
        }
        char nextChoice;
        printf("Would you like to complete another action on a file? (y)es or (n)o\n");
        scanf("%c", &nextChoice);
        getchar();
        

        switch(nextChoice)
        {
            case 'y' :
                //loop will continue
                //TODO: figure out why this option doesn't work after changing permissions
                break;
            case 'n' :
                printf("Thank you and goodbye.\n" );
                /* We are going to attempt to open the file that we just created */
                anotherChoice = FALSE;
                break;
            default :
                printf("Invalid choice.  Program Ending.\n" );
                anotherChoice = FALSE; 
        } //end switch
        
    } //end while(anotherChoice)
    return 0;
}
