#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t pid;

  // fork a child process
  pid = fork();

  if (pid == 0) {
    // this is the child process
    printf("This is the child process (PID: %d)\n", getpid());
    // use execlp to replace child process image with "ls -l" command
        int exec_ret = execlp("ls", "ls", "-l", NULL);
     // handle potential errors in execlp
        if (exec_ret == -1) {
            perror("execlp");
            _exit(1); //exit the child process with error
        }
  } else if (pid > 0) {
    // parent process
    int status;
    // wait for child process to finish
    wait(&status);
    // used of WIFEXITED  to check if the child exited normally
    // WEXITSTATUS is to get the exit code (0 for success).
    if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
            printf("Child process (PID: %d) terminated successfully.\n", pid);
        } else {
            printf("Child process (PID: %d) terminated with error.\n", pid);
        }
  }else{
    //pid<0
    //fork failed
    perror("fork");
    return 1;
  }
  return 0;
}
