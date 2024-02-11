#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  pid_t pid;

  // fork a child process
  pid = fork();
  //initialize a variable to 10
  int var=10;
  if (pid == 0) {
    // this is the child process
    printf("Child PID: %d, Variable value: %d\n", getpid(),var);
    int var=20;
    printf("Child After change, Variable value: %d\n", var);
  } else if (pid > 0) {
    // parent process
   printf("Parent PID: %d, Variable value: %d\n", getpid(), var);
    var = 30; // Change variable in parent
    printf("Parent After change, Variable value: %d\n", var);
  }else{
    //pid<0
    //fork failed
    perror("fork");
    return 1;
  }
  return 0;
}
