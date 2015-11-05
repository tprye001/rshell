#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>

/*Parameters: command to be executed and  vector<string> of arguments 
 * Return Value: bool (if execute was successful) */

bool execute(std::string cmd, std::vector<std::string> args){

  //turn args into one big string
  // unsigned n = args.size();
  /*char* sArgs[args.size()]; //should be n not 20 but WERROR
  for(unsigned int i = 0; i < args.size(); i++){
    char sArgsData = *args.at(i).data();
    char* sArgsPointer = &sArgsData;
    sArgs[i] = sArgsPointer;
    
  }*/
  
  std::vector<char *> sArgs;

  for (std::vector<std::string>::iterator loop = args.begin(); 
        loop != args.end(); ++loop) {
    sArgs.push_back(&(*loop)[0]);
  }

  sArgs.push_back(NULL);

  cmd = "./" + cmd;
  
  pid_t c_pid, pid;
  int status;

  c_pid = fork();

  if (c_pid < 0) {
    perror("fork failed");
    exit(1);
  }

  else if (c_pid ==0) {
    execvp(cmd.data(), &sArgs[0]);
    perror("execvp fail");
  }

  else if (c_pid > 0) {
    if( (pid = wait(&status)) < 0) {
      perror("wait");
      exit(1);
    }
  }
    
  return true;
}
