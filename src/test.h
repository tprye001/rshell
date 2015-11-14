#ifndef TEST_H 
#define TEST_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <vector>

bool test(std::vector<char *> args){
  std::string flag1 = "-f";
  std::string flag2 = "-e";
  std::string flag3 = "-d";

  char* flag = &flag2[0];
  char* path;
  if(*(args.at(0)) == flag1[0]) {
    flag = &flag1[0];
    path = args.at(1);
  }
  else if(*(args.at(0)) == flag3[0]){
    flag = &flag3[0];
    path = args.at(1);
  }
  else if(*(args.at(0)) == flag2[0]){
    path = args.at(1);
  }
  else
    path = args.at(0);

  struct stat kevin;
  stat(path, &kevin);

  if(*flag == flag1[0]){
    return S_ISREG(kevin.st_mode);
  }
  else if(*flag == flag3[0]){
    return S_ISDIR(kevin.st_mode);
  }
  return (S_ISREG(kevin.st_mode) || S_ISDIR(kevin.st_mode));
}

#endif
