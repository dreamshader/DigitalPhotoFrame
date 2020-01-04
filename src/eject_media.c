#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define E_FORK_FAILED    -10
#define E_EXEC_FAILED    -11

int eject_volume( const char* pDevice )
{
    int retVal = 0;
    pid_t ejectProc = fork();
  
    if (ejectProc < 0)
    {
        printf("A fork error has occurred.\n");
        retVal = E_FORK_FAILED;
    }
    else 
    {
        if (ejectProc == 0) /* We are in the child. */
        {
            printf("child -> exec eject ");

            if( pDevice != NULL )
            {
                printf("%s ...\n", pDevice);
            }
            else
            {
                printf(" ...\n");
            }

            execlp("eject", "eject", pDevice, (char *) NULL);
            /* execlp() failed if reaching this point. */
            printf("execlp() FAILED.\n");
            retVal = E_EXEC_FAILED;
        }
        else  /* We are in the parent. */
        {
            printf("parent -> waiting ...\n");
            wait(0);
            printf("parent -> child ended -> return\n");
        }
    }

    return(retVal);  
}

int main()
{
    eject_volume( "/dev/sr1" );
}


