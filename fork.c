#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t pid;

  // Fork a child process
  pid = fork();

  if (pid == 0) {
    // This is the child process
    printf("This is the child process (PID: %d)\n", getpid());
    _exit(0); // Terminate child process
  } else if (pid > 0) {
    // This is the parent process
    int status;

    // Wait for the child process to finish
    wait(&status);

    printf("This is the parent process (PID: %d)\n"
       "Child process (PID: %d) terminated.\n", getpid(), pid);  }
        else {
    // Fork failed
    perror("fork");
    return 1;
  }

  return 0;
}
