/**
 * This code is based on https://gist.github.com/iomonad/a66f6e9cfb935dc12c0244c1e48db5c8 and it's idea.
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#define PB_PATH "PhoneBook.txt"

void pipeline(char*** commands){
    int fdd = 0;
    int pfds[2];
    pid_t pid;
    int i = 0;

    while(commands[i] != NULL){ //while there are still commands to execute
        if(pipe(pfds)){
            perror("pipe failed");
            return;
        }
        if((pid = fork())<0){
            perror("fork failed");
            return;
        }
        if(pid==0){ //child process
            dup2(fdd, 0);//set the reading end of the pipe to the the file descriptor that the last command wrote into
            if(commands[i+1] != NULL){ // if not the last command then set the writing end of the pipe to pfds[1], so it will write the output of the command to there
                dup2(pfds[1], 1); 
            }
            close(pfds[0]);//close the read end of the pipe
            execvp(commands[i][0], commands[i]);//execute the command, the execvp takes the command name(the first cell in each command array), and the command arguments(the entire command array)
        } else {//not a child process
            wait(NULL); //wait for the child process to finish and collect them
            close(pfds[1]); //close the write end of the pipe
            fdd = pfds[0]; //set the file descriptor to the read end of the pipe, so that on the next iteration dup2 will 
            i++; //move to next command
        }
    }

}


int main(int argc, char* argv[]){
    // handling arguments:
    if(argc != 2){
        fprintf(stderr, "Not enough arguments");
        return 1;
    }
    
    char *grep[] = {"grep", argv[1], PB_PATH, NULL}; //creating each command as an array of strings
    char *sed[] = {"sed", "s/ /#/g", NULL};
    char *sed2[] = {"sed", "s/,/ /", NULL};
    char *awk[] = {"awk", "{print $2}", NULL};
    char *head[] = {"head", "-n", "1", NULL}; //make sure that only one number will be printed(if found). Prints the first number if the text file that matches
    char **commands[] = {grep, sed, sed2, awk, head, NULL}; //creating an array of commands
    pipeline(commands); //calling the pipeline function
    return 0;
}