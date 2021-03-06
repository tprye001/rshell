#ifndef EXECUTE_H
#define EXECUTE_H

#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>
#include "test.h"

/*Parameters: command to be executed and  vector<string> of arguments 
 * Return Value: bool (if execute was successful) */

bool execute(std::string cmd, std::vector<std::string> args){
  
    //turn args into one big string
  std::vector<char *> sArgs;

  for (std::vector<std::string>::iterator loop = args.begin(); 
        loop != args.end(); ++loop) {
    sArgs.push_back(&(*loop)[0]);
  }

  sArgs.push_back(NULL);

  if (cmd == "test")
    return test(sArgs);

  if (cmd == "true")
    return true;

  if (cmd == "false")
    return false;

  cmd = "./bin/" + cmd;
  
  pid_t c_pid, pid;
  int status;

  int x = 0;

  c_pid = fork();

  if (c_pid < 0) {
    perror("fork failed");
    exit(1);
  }

  else if (c_pid ==0) {
    x = execvp(cmd.data(), &sArgs[0]);
    perror("execvp fail");
  }

  else if (c_pid > 0) {
    if( (pid = wait(&status)) < 0) {
      perror("wait");
      exit(1);
    }
  }
  return (x != -1); 
}

#endif
