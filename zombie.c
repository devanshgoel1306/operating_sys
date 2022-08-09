//zombie process: if a process's parent is alive but never executes
//a wait(), the process's return code will never be accepted
//and the process will remain a zombie(child process)
#include<stdio.h>
#include<unistd.h> //header file to execute unix commands in c
#include<stdlib.h> //for exit() function

int main(void){

    //print the process id of the parent
    printf("Process id of the parent is %d.\n",getpid());

    //making a new process
    int pid=fork();

    //fork return the pid of the child to parent process
    if(pid!=0) //this will be true for parent process
    {
        while (1) //never terminates and never execute a wait()
        {
            //sleep the parent process for 60s
            sleep(60);//stop executing for 60s
        } 
            
    }
    //fork return 0 to the child process
    else//this will be true of child process
    {
        printf("Process id of the child process is %d.\n",getpid());
        //Child want to exit
        exit(42);
    }

    return 0;
}
//for running the infinte process in background
//we have used the command ./a.out &
//using ps(process status) command
//we can see all running processes.
//kill the parent process by kill pid
//child process will be then zombie
//and it will be adopted by 'init'
/*
Sample Output
root@DESKTOP-3V1QJSN:/mnt/c/operating_sys# gcc zombie.c
root@DESKTOP-3V1QJSN:/mnt/c/operating_sys# ./a.out &
[1] 84
root@DESKTOP-3V1QJSN:/mnt/c/operating_sys# Process id of the parent is 84.
Process id of the child process is 85.
ps
  PID TTY          TIME CMD
    6 tty1     00:00:00 init
   32 tty1     00:00:00 sudo
   33 tty1     00:00:00 bash
   84 tty1     00:00:00 a.out
   85 tty1     00:00:00 a.out <defunct>
   86 tty1     00:00:00 ps
root@DESKTOP-3V1QJSN:/mnt/c/operating_sys# kill 84
root@DESKTOP-3V1QJSN:/mnt/c/operating_sys# ps
  PID TTY          TIME CMD
    6 tty1     00:00:00 init
   32 tty1     00:00:00 sudo
   33 tty1     00:00:00 bash
   87 tty1     00:00:00 ps
[1]+  Terminated              ./a.out
*/
