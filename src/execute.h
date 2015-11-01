#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <vector>

/*Parameters: command to be executed and  vector<string> of arguments 
 * Return Value: bool (if execute was successful) */
bool execute(std::string cmd, std::vector<string> args)
{
  //turn args into one big string
  std:: string sArgs;
  for(int i = 0; i < args.size(); i++)
  {
    sArgs.append(args.at(i));
    sArgs.append(" ");
  }

  //add "./" to cmd
  cmd = "./" + cmd;
  
  //pass to execvp
  execvp(cmd, sArgs);
  perror("execvp fail");

  return true;
}
