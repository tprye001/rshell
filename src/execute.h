#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <vector>

/*Parameters: command to be executed and  vector<string> of arguments 
 * Return Value: bool (if execute was successful) */

bool execute(std::string cmd, std::vector<std::string> args){

  //turn args into one big string
  char* sArgs[args.size()];
  for(unsigned int i = 0; i < args.size(); i++){
    char sArgsData = *args.at(i).data();
    char* sArgsPointer = &sArgsData;
    sArgs[i] = sArgsPointer;
  }

  cmd = "./" + cmd;

  execvp(cmd.data(), sArgs);
  perror("execvp fail");

  return true;
}
