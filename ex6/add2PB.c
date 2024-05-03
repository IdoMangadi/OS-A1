#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>   
#include <fcntl.h>

#define NAME_SIZE 40
#define PHONE_SIZE 20
#define PB_PATH "PhoneBook.txt"

/**
 * The logic:
 * first the program handles arguments and operates a validation check on them.
 * then it creats a pipe and a child proccess using fork() and keeps its proccess id (pid).
 * child proccess: manipulating stdin and stdout, means directing stdin to reading end of the pipe and stdout to the phonebook file.
 *                 using execve to launch cat with no arguments, means it will read from stdin and write to stdout (redirected).
 * parent proccess: sending the string via the pipe and waits for child procccess to finish.               
*/
int main(int argc, char* argv[]){
    // handling arguments:
    if(argc < 2 || argc > 3){
        fprintf(stderr, "Usage: %s Firstname(optional) Lastname,PhoneNumber\n", argv[0]);
        return 1;
    }

    // Concatenate the name and phone number into a single string:
    char record[NAME_SIZE + PHONE_SIZE + 2]; // 2 extra for the comma and newline
    if(argc == 2){  // means the input in format: "name,PhoneNumber"
        snprintf(record, sizeof(record), "%s\n", argv[1]);
    }
    else{  // means the input in format: "name name,PhoneNumber"
        snprintf(record, sizeof(record), "%s %s\n", argv[1], argv[2]);
    }

    // ---------------------------------------
    // TODO: more validation checks if needed.
    // ---------------------------------------

    // counting string actual length:
    size_t record_size = 0;
    while(record[record_size] != '\0'){
        record_size++;
    }

    int fd[2];
    pid_t pid;

    if(pipe(fd) == -1){  // creating a pipe
        fprintf(stderr, "Pipe error\n");
        return 1;
    }

    pid = fork();  // creating a child proccess
    if(pid == -1){
        fprintf(stderr, "Fork error\n");
        return  1;
    }

    if(pid == 0){  // child process

        close(fd[1]);  // closing writing end

        // redirecting stdin to the reading end of the pipe
        dup2(fd[0], 0); 
        close(fd[0]); // closing reading end

        // redirectin stdout to the phonebook file:
        int pb = open(PB_PATH, O_WRONLY | O_CREAT | O_APPEND, 0666);
        dup2(pb, 1);
        close(pb);

        // executing cat:
        char *cat_args[] = {"cat", NULL};
        execve("/bin/cat", cat_args, NULL);
        fprintf(stderr, "Usage: %s Firstname Lastname,PhoneNumber\n", argv[0]); // getting here means the execve didnt succeed
        return 1;
    }
    else {  // Parent process

        close(fd[0]);  // Close reading end of the pipe

        // writing to the pipe:
        write(fd[1], record, record_size);
        close(fd[1]);  // Close writing end of the pipe

        wait(NULL);  // wating for child procces to end
    }
    
    return 0;
}
