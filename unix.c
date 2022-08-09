#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    //Linux provides us a utility called ps for viewing information related with the processes on a system which 
    //stands as abbreviation for “Process Status”.
    printf("Various operations using UNIX commands\n");
    printf("Process Status\n");
    system("ps");

    //creating a new file
    printf("\nCreating new file with touch command\n");
    system("touch file.txt");

    //display the files in operating_sys directory
    printf("\nfiles in operating_sys directory\n");
    system("ls -l");

    //adding data to the file created
    printf("\nAdding text to file.txt using echo and redirection operator\n");
    system("echo  I am Devansh> file.txt");

    //display the data in file.txt
    printf("\nData in file.txt\n");
    system("cat file.txt");

    //deleting the created file
    printf("\ndeleting the created file with rm command\n");
    system("rm file.txt");

    //display the files in operating_sys directory
    printf("\nfiles in operating_sys directory\n");
    system("ls -l");

    //creating new sub-directory
    printf("\nCreating new sub-directory sample\n");
    system("mkdir sample");

    //displays all files and directories
    printf("\nfiles and directories in operating_sys directory\n");
    system("ls -l");

    //deleting the created directory
    printf("\ndeleting the created directory using rmdir command\n");
    system("rmdir sample");

    //displays all files and directories
    printf("\nfiles and directories in operating_sys directory\n");
    system("ls -l");

    return 0;
}
