#include <cstdlib>
#include <cstdio>
#include <unistd.h>

int main (int argc, char * argv[]) {
  const char * file = "mkdir";

  execvp(file, argv);
  perror("execve failed");

  return 0;
}
