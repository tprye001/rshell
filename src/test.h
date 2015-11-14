#ifndef TEST_H 
#define TEST_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

bool test(vector<char *> args){
  char* flag = "-e"
  char* path;
  if(args.at(0) == "-f") {
    flag = "-f";
    path = args.at(1);
  }
  else if(args.at(0) == "-d"){
    flag = "-d";
    path = args.at(1);
  }
  else if(args.at(0) == "-e"){
    path = args.at(1);
  }
  else
    path = args.at(0);

  struct stat kevin;
  stat(path, &kevin);

  if(flag == "-f"){
    return S_ISREG(kevin.st_mode);
  }
  else if(flag == "-d"){
    return S_ISDIR(kevin.st_mode);
  }
  return (S_ISREG(kevin.st_mode) || S_ISDIR(kevin.st_mode));
}

#endif
