#ifndef TEST_H 
#define TEST_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <vector>

bool test(std::vector<char *> args){
  char flag1 = 'f';
  char flag2 = 'e';
  char flag3 = 'd';
  
  bool ret = false;

  char flag;
  char* path;

  if(args.at(1)[1] == flag1) {
    flag = flag1;
    path = args.at(2);
  }
  else if(args.at(1)[1] == flag3){
    flag = flag3;
    path = args.at(2);
  }
  else if(args.at(1)[1] == flag2){
    flag = flag2;
    path = args.at(2);
  }
  else{
    path = args.at(1);
    flag = flag2;
  }

  struct stat kevin;
  stat(path, &kevin);

  if(flag == flag1){
    ret = S_ISREG(kevin.st_mode);
  }
  else if(flag == flag3){
    ret =  S_ISDIR(kevin.st_mode);
  }
  else {
    ret = (S_ISREG(kevin.st_mode) || S_ISDIR(kevin.st_mode));
  }
  return ret;
}

#endif
