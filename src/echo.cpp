#include <cstdlib>
#include <unistd.h>
#include <cstdio>

int main (int argc, char * argv[]) {
  const char * file = "echo";
  
  execvp(file, argv);
  perror("execve failed");

  return 0;
}
