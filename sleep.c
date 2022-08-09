//suspending the process for a period of time using sleep()
#include<stdio.h>
#include<unistd.h>

int main(void){

printf("I am parent process with id %d\n",getpid());
//creating the child processes
int pid=fork();

if(pid!=0){
    //sleep the process for 10 seconds
    sleep(10);
}
else{
    printf("Parent Process is asleep.\n");
    printf("I am child process with process id %d.\n", getpid());
    printf("I am son with process pid %d.\n",getppid());
}
return 0;
}
/*Sample Output
I am parent process with id 54
Parent Process is asleep.
I am child process with process id 55.
I am son with process pid 54.
*/
//Observation
//After printing the sample output cursor blinks for 1s approx.
//because the parent process was in sleep state.