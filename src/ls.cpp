#include <cstdlib>
#include <unistd.h>
#include <cstdio>

int main (int argc, char * argv[]) {
  const char * file = "ls";
  
  execvp(file, argv);
  perror("execve failed");

  return 0;
}
