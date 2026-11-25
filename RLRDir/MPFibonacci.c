#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
//-------------------------------------------------------------------------------------------------
#define MAX_ARGS 20
#define MAX_STRING 1024
typedef char String[MAX_STRING];
//-------------------------------------------------------------------------------------------------
long Fibonacci(int Index) {
    
    int ChildPID;
    String ShellCommand;
    char *MyArgV[MAX_ARGS];
    int MyArgC;

    fprintf(stderr,"STDERR: In Fibonacci(%d) function\n",Index);
    if (Index <= 1) {
        return(Index);
    } else {
        printf("STDOUT: Index %d large enough, fork a child\n",Index);
        if ((ChildPID = fork()) == 0) {
            ChildPID = getpid();
            printf("STDOUT: In the child process %d computing Fibonacci(%d)\n",ChildPID,Index-1);
            sprintf(ShellCommand,"./Fibonacci %d",Index-1);
            MyArgC = 0;
            MyArgV[MyArgC] = strtok(ShellCommand," ");
            while (MyArgV[MyArgC++] != NULL) {
                MyArgV[MyArgC] = strtok(NULL," ");
            }
            execvp(MyArgV[0],MyArgV);
            fprintf(stderr,"STDERR: Could not exec %s\n",ShellCommand);
            exit(EXIT_FAILURE);
        } else {
            printf("STDOUT: In the parent, the child is %d\n",ChildPID);
        }
        return(Fibonacci(Index-1) + Fibonacci(Index-2));
    }
}
//-------------------------------------------------------------------------------------------------
int main(int argc,char *argv[]) {

    int numberToCompute;
    
    numberToCompute = atoi(argv[1]);
    printf("STDOUT: In MPFibonacci with PID %d computing Fibonacci(%d)\n",getpid(),numberToCompute);
    printf("STDOUT: Fibonacci of %d is %ld\n",numberToCompute,Fibonacci(numberToCompute)); 
    return(EXIT_SUCCESS);
}
//-------------------------------------------------------------------------------------------------
