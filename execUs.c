#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>

#define NUM_PROGRAMS (3)

#define FORKCHLD	(pid_t)0
#define FORKERR		(pid_t)-1

char * execUs[NUM_PROGRAMS] = {"date", "pwd", "ls"}

int main()
{

   assert(0) /*TBD*/
   return 1;

}
