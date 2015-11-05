#include <cstdlib>
#include <unistd.h>
#include <cstdio>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char * argv[]) {
  const char * file = "ls";
  pid_t c_pid, pid;
  int status;

  c_pid = fork();

  if (c_pid < 0) {
    perror("fork failed");
    exit(1);
  }

  else if (c_pid == 0) {
    execvp(file, argv);
    perror("execve failed");
  }

  else if (c_pid > 0) {
    if ( (pid = wait(&status)) < 0) {
      perror("wait");
      exit(1);
    }
  }
  return 0;
}
