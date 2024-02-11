#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t pid;

  // fork a child process
  pid = fork();
  // initialize a variable to 10
  if (pid == 0)
  {
    execlp("ls", "ls", "-l", NULL); // Replace child process with "ls" command
    perror("execlp failed");  // This line won't execute if execlp succeeds
  }
  else if (pid > 0)
  {
    // parent process
    printf("Parent process still running (PID: %d)\n", getpid());
    wait(NULL); // Wait for child process to finish
  }
  else
  {
    // pid<0
    // fork failed
    perror("fork failed");
    return 1;
  }
  return 0;
}
