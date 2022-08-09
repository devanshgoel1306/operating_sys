#include<stdio.h>
//#include<unistd.h>
#include<stdlib.h>

int main(void)
{
    //get the user manual of exec system call
    system("man exec");

    //get the user manual of wait system call
    system("man wait");

    //get the user manual of sleep system call
    system("man sleep");

    //get the user manual of exit system call
    system("man exit");

    //get the user manual of fork system call
    system("man fork");

    //get the user manual of getpid system call
    system("man getpid");

    //get the user manual of init process
    system("man init");

    system("man waitid waitpid");

    return 0;
}